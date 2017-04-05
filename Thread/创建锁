CreateMutex、WaitForSingleObject、ReleaseMutex

在使用互斥量进行线程同步时会用到以下几个函数：

HANDLE WINAPI CreateMutex(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,        //线程安全相关的属性，常置为NULL
    BOOL                  bInitialOwner,            //创建Mutex时的当前线程是否拥有Mutex的所有权
    LPCTSTR               lpName                    //Mutex的名称
);
**说明：**lpMutexAttributes也是表示安全的结构，与CreateThread中的lpThreadAttributes功能相同，表示决定返回的句柄是否可被子进程继承，如果为NULL则表示返回的句柄不能被子进程继承。bInitialOwner表示创建Mutex时的当前线程是否拥有Mutex的所有权，若为TRUE则指定为当前的创建线程为Mutex对象的所有者，其它线程访问需要先ReleaseMutex。lpName为Mutex的名称。

DWORD WINAPI WaitForSingleObject(
    HANDLE hHandle,                             //要获取的锁的句柄
    DWORD  dwMilliseconds                           //超时间隔
);
**说明：**WaitForSingleObject的作用是等待一个指定的对象(如Mutex对象)，直到该对象处于非占用的状态(如Mutex对象被释放)或超出设定的时间间隔。除此之外，还有一个与它类似的函数WaitForMultipleObjects，它的作用是等待一个或所有指定的对象，直到所有的对象处于非占用的状态，或超出设定的时间间隔。 
hHandle：要等待的指定对象的句柄。dwMilliseconds：超时的间隔，以毫秒为单位；如果dwMilliseconds为非0，则等待直到dwMilliseconds时间间隔用完或对象变为非占用的状态，如果dwMilliseconds 为INFINITE则表示无限等待，直到等待的对象处于非占用的状态。

BOOL WINAPI ReleaseMutex(HANDLE hMutex);
说明：释放所拥有的互斥量锁对象，hMutex为释放的互斥量的句柄。
