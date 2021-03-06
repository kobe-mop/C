//模拟火车买票系统
买火车票是大家春节回家最为关注的事情，我们就简单模拟一下火车票的售票系统(为使程序简单，我们就抽出最简单的模型进行模拟)：有500张从北京到赣州的火车票，在8个窗口同时出售，保证系统的稳定性和数据的原子性。
//SaleTickets.h文件

#include <windows.h>
#include <iostream>
#include <strstream> 
#include <string>

using namespace std;

#define NAME_LINE   40

//定义线程函数传入参数的结构体
typedef struct __TICKET
{
    int nCount;
    char strTicketName[NAME_LINE];
	
    __TICKET() : nCount(0)
    {
        memset(strTicketName, 0, NAME_LINE * sizeof(char));
    }
}TICKET;

typedef struct __THD_DATA
{
    TICKET* pTicket;
    char strThreadName[NAME_LINE];
	
    __THD_DATA() : pTicket(NULL)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }
}THD_DATA;


//基本类型数据转换成字符串
template<class T>
string convertToString(const T val)
{
    string s;
    std::strstream ss;
    ss << val;
    ss >> s;
    return s;
}

//售票程序
DWORD WINAPI SaleTicket(LPVOID lpParameter);

HANDLE g_hMutex = NULL;

/********************************************************************/
//SaleTickets.cpp文件

#include <windows.h>
#include <iostream>
#include "SaleTickets.h"

using namespace std;

extern HANDLE g_hMutex;

//售票程序
DWORD WINAPI SaleTicket(LPVOID lpParameter)
{
	
    THD_DATA* pThreadData = (THD_DATA*)lpParameter;
    TICKET* pSaleData = pThreadData->pTicket;
    while(pSaleData->nCount > 0)
    {
        //请求获得一个互斥量锁
        WaitForSingleObject(g_hMutex, INFINITE);
        if (pSaleData->nCount > 0)
        {
            cout << pThreadData->strThreadName << "出售第" << pSaleData->nCount -- << "的票,";
            if (pSaleData->nCount >= 0) {
                cout << "出票成功!剩余" << pSaleData->nCount << "张票." << endl;
            } else {
                cout << "出票失败！该票已售完。" << endl;
            }
        }
        Sleep(10);
        //释放互斥量锁
        ReleaseMutex(g_hMutex);
    }
	
    return 0L;
}

//售票系统
void main()
{
    //创建一个互斥量
    g_hMutex = CreateMutex(NULL, FALSE, NULL);
	
    //初始化火车票
    TICKET ticket;
    ticket.nCount = 100;
    strcpy(ticket.strTicketName, "北京-->赣州");
	
    const int THREAD_NUMM = 8;
    THD_DATA threadSale[THREAD_NUMM];
    HANDLE hThread[THREAD_NUMM];
    for(int i = 0; i < THREAD_NUMM; ++ i)
    {
        threadSale[i].pTicket = &ticket;
        string strThreadName = convertToString(i);
		
        strThreadName = "窗口" + strThreadName;
		
        strcpy(threadSale[i].strThreadName, strThreadName.c_str());
		
        //创建线程
        hThread[i] = CreateThread(NULL, NULL, SaleTicket, &threadSale[i], 0, NULL);
		
        //请求获得一个互斥量锁
        WaitForSingleObject(g_hMutex, INFINITE);
        cout << threadSale[i].strThreadName << "开始出售 " << threadSale[i].pTicket->strTicketName << " 的票..." << endl;
        //释放互斥量锁
        ReleaseMutex(g_hMutex);
		
        //关闭线程
        CloseHandle(hThread[i]);
    }
	
    system("pause");
}
