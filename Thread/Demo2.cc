//线程传入参数

#include "stdafx.h"
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



//线程函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    THREAD_DATA* pThreadData = (THREAD_DATA*)lpParameter;

    for (int i = 0; i < pThreadData->nMaxNum; ++ i)
    {
        cout << pThreadData->strThreadName << " --- " << i << endl;
        Sleep(100);
    }
    return 0L;
}

int main()
{
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
    //关闭线程
    CloseHandle(hThread1);
    CloseHandle(hThread2);

    //主线程的执行路径
    for (int i = 0; i < 5; ++ i)
    {
        cout << "主线程 === " << i << endl;
        Sleep(100);
    }

    system("pause");
    return 0;
}

结果如下：
主线程 === 线程1 — 0 
0 
线程2 — 0 
线程1 — 1 
主线程 === 1 
线程2 — 1 
主线程 === 2 
线程1 — 2 
线程2 — 2 
主线程 === 3 
线程2 — 3 
线程1 — 3 
主线程 === 4 
线程2 — 4 
线程1 — 4 
线程2 — 5 
请按任意键继续… 线程2 — 6 
线程2 — 7 
线程2 — 8 
线程2 — 9

从【Demo2】中可以看出，虽然创建的子线程都正常执行起来了，但输出的结果并不是我们预期的效果。我们预期的效果是每输出一条语句后自动换行，但结果却并非都是这样。这是因为在线程执行时没有做同步处理，比如第一行的输出，主线程输出“主线程 ===”后时间片已用完，这时轮到子线程1输出，在子线程输出“线程1 —”后时间片也用完了，这时又轮到主线程执行输出“0”，之后又轮到子线程1输出“0”。于是就出现了“主线程 === 线程1 — 0 0”的结果。

主线程：cout << “主线程 === ” << i << endl; 
子线程：cout << pThreadData->strThreadName << ” — ” << i << endl;

为避免出现这种情况，我们对线程做一些简单的同步处理，这里我们用互斥量(Mutex)
