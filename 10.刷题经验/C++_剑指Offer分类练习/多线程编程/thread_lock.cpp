#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


class Account
{
    public:
        explicit Account(double balance):_balance(balance){}
        double GetBalance(){return _balance;}

        void Increase(double amount){_balance+=amount;}
        void Decrease(double amount){_balance-=amount;}

        std::mutex& GetMutex(){return _x;}

        private:
            double _balance;
            std::mutex _x;

};

//避免死锁，使用std::lock()函数锁定多个互斥，不同的锁定顺序不会导致死锁
//枷锁时候有可能引发异常，std::lock()函数会处理该异常
//将解锁此前已经枷锁的部分互斥，然后重新引发该异常
void Transfer(Account& from,Account& to,double amount)
{
    std::unique_lock<std::mutex> locker1(from.GetMutex(),std::adopt_lock);
    std::unique_lock<std::mutex> locker2(to.GetMutex(),std::adopt_lock);
    std::lock(from.GetMutex(),to.GetMutex());

    from.Decrease(amount);
    to.Increase(amount);

}

int main()
{
    Account a1(100.0),a2(200.0);
    //线程参数采用值传递机制，如果要传递引用，调用std::ref()函数
    std::thread t1(Transfer,std::ref(a1),std::ref(a2),10.0);
    std::thread t2(Transfer,std::ref(a2),std::ref(a1),20.0);

    t1.join();
    t2.join();

    return 0;
}


// template<typename T>
// class Worker
// {
//     public:
//         explicit Worker(int no,T a=0,T b=0):_no(no)
//         ,_a(a),_b(b){}

//         void ThreadFUnc(T *r)
//         {
//              //使用复合语句块封装临界区操作，块结束即释放局部对象
//              {
//                  std::lock_guard<std::mutex> locker(x);//构造对象时候同时枷锁
//                  *r=_x+_y;
//              }//无需手动解锁，locker对象在析构时候自动解锁

//              std::cout<<"Thread NO: "<<_no<<std::endl;
//              std::cout<<_a<<"+"<<_b<<"="<<_a+_b<<std::endl;
//         }
//         private:
//             int _no;
//             T _a,_b;
// };

