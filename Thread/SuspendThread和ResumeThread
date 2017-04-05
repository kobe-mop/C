操作系统的线程有几种状态的变化：执行(运行)，挂起（阻塞）和恢复(就绪)执行。 
当线程做完任务或者现在想暂停线程运行，就需要使用SuspendThread来暂停线程的执行，当然恢复线程的执行就是使用ResumeThread函数了。这两个函数使用很简单的，下面就来看看例子是怎么样使用的。

函数原型如下： 

挂起线程
DWORD WINAPI SuspendThread(_In_ HANDLE hThread);

恢复线程
DWORD WINAPI ResumeThread(_In_ HANDLE hThread);
说明：hThread为指定线程的句柄。

/************************************************************/

#include <windows.h>
#include <iostream>
using namespace std;

#define NAME_LINE   40

//定义线程函数传入参数的结构体
typedef struct __THREAD_DATA
{
    int nMaxNum;
    char strThreadName[NAME_LINE];

    __THREAD_DATA() : nMaxNum(0)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }
}THREAD_DATA;

HANDLE g_hMutex = NULL;     //互斥量

//线程函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;

    for (int i = 0; i < pThreadData->nMaxNum; ++ i)
    {
        //请求获得一个互斥量锁
        WaitForSingleObject(g_hMutex, INFINITE);
        cout << pThreadData->strThreadName << " --- " << i << endl;
        Sleep(100);
        //释放互斥量锁
        ReleaseMutex(g_hMutex);
    }
    return 0L;
}

int main()
{
    //创建一个互斥量
    g_hMutex = CreateMutex(NULL, FALSE, NULL);

    //初始化线程数据
    THREAD_DATA threadData1, threadData2;
    threadData1.nMaxNum = 5;
    strcpy(threadData1.strThreadName, "线程1");
    threadData2.nMaxNum = 10;
    strcpy(threadData2.strThreadName, "线程2");


    //创建第一个子线程
    HANDLE hThread1 = CreateThread(NULL, 0, ThreadProc, &threadData1, 0, NULL);
    //创建第二个子线程
    HANDLE hThread2 = CreateThread(NULL, 0, ThreadProc, &threadData2, 0, NULL);
    // 挂起线程
    SuspendThread(hThread1);                    // [代码段1]

    //Sleep(500);                                   // [代码段2]
    //ResumeThread(hThread1);                       // [代码段2]

    //关闭线程
    CloseHandle(hThread1);
    CloseHandle(hThread2);

    system("pause");
    return 0;
}


当我们打开[代码段1]，注释[代码段2]时，结果如下：

线程2 — 0 
线程2 — 1 
线程2 — 2 
线程2 — 3 
线程2 — 4 
线程2 — 5 
线程2 — 6 
线程2 — 7 
线程2 — 8 
线程2 — 9
可以发现线程1被挂起，并没有执行。

当我们同时打开[代码段1]和[代码段2]，结果如下：

线程2 — 0 
线程2 — 1 
线程2 — 2 
线程2 — 3 
线程2 — 4 
线程1 — 0 
线程2 — 5 
线程1 — 1 
线程2 — 6 
线程1 — 2 
线程2 — 7 
线程1 — 3 
线程2 — 8 
线程1 — 4 
线程2 — 9
可以发现线程1在0.5秒之后才开始执行，这是因为线程1在挂起0.5秒之后才被唤醒(恢复)，开始执行。
