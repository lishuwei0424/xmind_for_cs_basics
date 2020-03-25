#include <iostream>
#include <thread>

//无参数的线程函数
void ThreadFunc()
{
    std::cout<<"Thread ID: "<<std::this_thread::get_id()<<std::endl;
}

//双参数的线程函数
void ThreadFunc_1(int a,int b)
{
     std::cout<<"Thread ID: "<<std::this_thread::get_id()<<std::endl;
     std::cout<<a<<"+"<<b<<"="<<a+b<<std::endl;
}

//双参数的函子对象
class Functor
{
    public:
        void operator()(int a,int b)
        {
          std::cout<<"Thread ID: "<<std::this_thread::get_id()<<std::endl;
          std::cout<<a<<"+"<<b<<"="<<a+b<<std::endl;

        }
};

//使用std::bind()函数绑定对象及普通成员函数
class Worker
{
    public:
        Worker(int a=0,int b=0):_a(a),_b(b){}
    void ThreadFunc_2()
    {
        std::cout<<"Thread ID: "<<std::this_thread::get_id()<<std::endl;
          std::cout<<_a<<"+"<<_b<<"="<<_a+_b<<std::endl;

    }

    private: 
        int _a,_b;
};

int main()
{   
    // //无参数
    // std::thread t(&ThreadFunc);//创建线程
    // t.join();//等待线程结束

    // //双参数
   // int m=10,n=20;
    // //C++11标准库使用可变参数的模板形式参数列表，线程函数参数个数任意
    // std::thread t(&ThreadFunc_1,m,n);
    // t.join();
    
    // //双参数的函子对象
    // std::thread t(Functor(),m,n);
    // t.join();

    //使用std::bind()函数绑定对象及普通成员函数
    Worker worker(10,20);
    std::thread t(std::bind(&Worker::ThreadFunc_2,&worker));
    t.join();


    return 0;
}