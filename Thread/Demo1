#include <windows.h>
#include <iostream>

using namespace std;

//线程函数
DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    for (int i = 0; i < 5; ++ i)
    {
        cout << "子线程:i = " << i << endl;
        Sleep(100);
    }
    return 0L;
}

int main()
{
    //创建一个线程
    HANDLE thread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    //关闭线程
    CloseHandle(thread);

    //主线程的执行路径
    for (int i = 0; i < 5; ++ i)
    {
        cout << "主线程:i = " << i << endl;
        Sleep(100);
    }

    return 0;
}

结果如下： 
主线程:i = 0 
子线程:i = 0 
主线程:i = 1 
子线程:i = 1 
子线程:i = 2 
主线程:i = 2 
子线程:i = 3 
主线程:i = 3 
子线程:i = 4 
主线程:i = 4
