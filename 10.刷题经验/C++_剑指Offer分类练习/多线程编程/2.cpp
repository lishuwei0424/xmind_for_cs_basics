

/*
题目：编写一个程序，开启3个线程，这3个线程的ID分别为A、B、C，
每个线程将自己的ID在屏幕上打印10遍，要求输出结果必须按ABC的顺序显示；
如：ABCABC….依次递推。*/

#include <iostream>  
#include <string>  
#include  <thread>  
#include  <mutex>
#include <condition_variable>

using namespace std;

//保护条件的互斥访问
mutex m;

//条件变量
condition_variable cond;

int loop = 10;

//条件
int flag = 0;

void func(int id)
{
    for (int i = 0; i < loop; ++i)
    {
         //A unique lock is an object that manages a mutex object
         // with unique ownership in both states: locked and unlocked.  
        unique_lock<mutex> lk(m);
        while (flag != id)
        //在调用wait时会执行lk.unlock()  
            cond.wait(lk);
        cout << static_cast<char>('A' + id) << " ";
        flag = (flag + 1) % 3;
         //被阻塞的线程唤醒后lk.lock()恢复在调用wait前的状态  
        cond.notify_all();
    }
}

int main()
{
    thread A(func, 0);
    thread B(func, 1);
    func(2);
    cout << endl;

    A.join();
    B.join();



    return 0;
}