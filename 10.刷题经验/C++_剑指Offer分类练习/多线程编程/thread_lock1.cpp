#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex x;

void ThreadFunc()
{
    x.lock();//锁定它，其他线程进不去临界区
    std::cout<<std::this_thread::get_id()<<"is entering..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<std::this_thread::get_id()<<"is leaving .."<<std::endl;
    x.unlock();
}

int main()
{
    std::vector<std::thread*> v(8);
    for(int i=0;i<8;i++)
        v[i]=new std::thread(ThreadFunc);
    for(int i=0;i<8;i++)
        v[i]->join();

    return 0;
}