#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>


unsigned long int Cal(short int n)
{
    unsigned long int r=1;
    if(n>20)
        throw std::range_error("the number is too big ");

    for(short int i=2;i<=n;i++)
      r*=i;

    return r;
}

//Cal()函数的包装函数原型
void Dol(std::promise<unsigned long int> &&promise,
short int n)
{
    try
    {
        //设置线程返回值，共期许对象获取
        promise.set_value(Cal(n));
    }
    catch(...)
    {
        //捕获全部异常，并在期许线程返回值时重新引发
        promise.set_exception(std::current_exception());

    }
}

int main()
{
    short int n=20;
    //启动异步线程，执行后台计算任务，并返回std::future对象
    //std::future<unsigned long int> f=std::async(Cal,n);
   
    //创建承诺对象
    std::promise<unsigned long int> p;
    //获取相关期许对象
    std::future<unsigned long int> f=p.get_future();
    //启动线程，执行包装函数
    std::thread t(Dol,std::move(p),n);
    //分离线程，不管它了，后台跑去把
    t.detach();

    
        try
    {
       //获取线程返回值，若线程已经结束，立即返回，否则等待线程计算完毕
       //若线程引发异常，则延迟到std::future::get()或
       //std::future::wait()调用时候引发
       unsigned long int r=f.get();
       std::cout<<n<<"!= "<<r<<std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

