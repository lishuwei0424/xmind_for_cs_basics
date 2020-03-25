#include <atomic>
#include <iostream>
#include <thread>

int n=0;
std::atomic<int> a(0);
void AddAtomic(int m)
{
    while(m--)
        a.fetch_add(1);
}

void Add(int m)
{
    while(m--)
        ++n;
}

int main()
{
    std::thread ts1[8],ts2[8];
    for(auto &t:ts1)
        t=std::move(std::thread(AddAtomic,1000000));
    for(auto &t:ts2)
        t=std::move(std::thread(Add,1000000));
    for(auto &t:ts1) t.join();
    for(auto &t:ts2) t.join();

    //输出结果，a固定，而n多次运行结果可能不同
    std::cout<<"a= "<<a<<std::endl;
    std::cout<<"n= "<<n<<std::endl;

    return 0;
}