/*
有四个线程1、2、3、4。线程1的功能就是输出1，线程2的功能就是输出2，
以此类推.........现在有四个文件ABCD。初始都为空。现要让四个文件呈如下格式：

A：1 2 3 4 1 2....
B：2 3 4 1 2 3....
C：3 4 1 2 3 4....

D：4 1 2 3 4 1....
*/
#include <iostream>  
#include <string>  
#include  <thread>  
#include  <mutex>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cond;
int loop = 10;
int flag=0;

void func(int num)
{
    for (int i = 0; i < loop; ++i)
    {
        unique_lock<mutex> lk(m);
        while (num != flag)
            cond.wait(lk);
        cout << num + 1 << " ";
        flag = (flag + 1) % 4;
        cond.notify_all();
    }
}

int main(int argc,char *argv[])
{
    //flag = atoi(argv[1]);
    thread one(func, 1);
    thread two(func, 2);
    thread three(func, 3);
    func(0);
    one.join();
    two.join();
    three.join();
    cout << endl;

  return 0;
}