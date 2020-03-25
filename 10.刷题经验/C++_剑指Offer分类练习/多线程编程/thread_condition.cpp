#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

std::mutex x;
std::condition_variable cond;//条件变量与互斥连用

bool ready=false;
bool IsReady(){return ready;}

void Run(int no)
{
    std::unique_lock<std::mutex> locker(x);
    while(!ready)//若标志为非true,阻塞当前进程
    {
        cond.wait(locker);//解锁并睡眠，被唤醒后重新枷锁
        std::cout<<"thread"<<no<<"\n";

        //等价cond.wait(locker,&IsReady)
    }
}

int mian()
{
    std::thread threads[8];
    for(int i=0;i<8;i++)
        threads[i]=std::thread(Run,i);
    std::cout<<"8 threads ready...\n";

    {
        std::unique_lock<std::mutex> locker(x);//互斥枷锁
        ready=true;//设置全局标志为true
        cond.notify_all();//唤醒所有线程

    }//离开作用阈，自动解锁，可将次复合语句块实现为函数
    
    for(auto &t:threads)
        t.join();

    return 0;
}