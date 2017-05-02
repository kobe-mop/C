在Windows平台，Windows API提供了对多线程的支持。前面进程和线程的概念中我们提到，一个程序至少有一个线程，这个线程称为主线程(main thread)，如果我们不显示地创建线程，那我们产的程序就是只有主线程的间线程程序。 
下面，我们看看Windows中线程相关的操作和方法：

//CreateThread

CreateThread用于创建一个线程，其函数原型如下：

HANDLE WINAPI CreateThread(
    LPSECURITY_ATTRIBUTES   lpThreadAttributes, //线程安全相关的属性，常置为NULL
    SIZE_T                  dwStackSize,        //新线程的初始化栈在大小，可设置为0
    LPTHREAD_START_ROUTINE  lpStartAddress,     //被线程执行的回调函数，也称为线程函数
    LPVOID                  lpParameter,        //传入线程函数的参数，不需传递参数时为NULL
    DWORD                   dwCreationFlags,    //控制线程创建的标志
    LPDWORD                 lpThreadId          //传出参数，用于获得线程ID，如果为NULL则不返回线程ID
);

**说明：**

lpThreadAttributes：指向SECURITY_ATTRIBUTES结构的指针，决定返回的句柄是否可被子进程继承，如果为NULL则表示返回的句柄不能被子进程继承。

dwStackSize ：线程栈的初始化大小，字节单位。系统分配这个值对

lpStartAddress：指向一个函数指针，该函数将被线程调用执行。因此该函数也被称为线程函数(ThreadProc)，是线程执行的起始地址，线程函数是一个回调函数，由操作系统在线程中调用。线程函数的原型如下：
DWORD WINAPI ThreadProc(LPVOID lpParameter);    //lpParameter是传入的参数，是一个空指针

lpParameter：传入线程函数(ThreadProc)的参数，不需传递参数时为NULL

dwCreationFlags：控制线程创建的标志，有三个类型，0：线程创建后立即执行线程；CREATE_SUSPENDED：线程创建后进入就绪状态，直到线程被唤醒时才调用；STACK_SIZE_PARAM_IS_A_RESERVATION：dwStackSize 参数指定线程初始化栈的大小，如果STACK_SIZE_PARAM_IS_A_RESERVATION标志未指定，dwStackSize将会设为系统预留的值。

返回值：如果线程创建成功，则返回这个新线程的句柄，否则返回NULL。如果线程创建失败，可通过GetLastError函数获得错误信息。



//CloseHandle

BOOL WINAPI CloseHandle(HANDLE hObject);        //关闭一个被打开的对象句柄
可用这个函数关闭创建的线程句柄，如果函数执行成功则返回true(非0),如果失败则返回false(0)，如果执行失败可调用GetLastError.函数获得错误信息。
