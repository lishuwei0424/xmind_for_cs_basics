/*
// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
*/

#include <iostream>
using namespace std;

//递归
long long Sol_1(unsigned int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 1;

    return Sol_1(n-1)+Sol_1(n-2);
}

//循环
//从下往上算，首先根据f(0)+f(1)=f(2)，再f(1)+f(2)=f(3)....
long long Sol_2(unsigned int n)
{
    int result[2]={0,1};
    if(n<2)
        return result[n];

    long long f_one=1;
    long long f_two=0;
    long long f=0;
    for(unsigned int i=2;i<=n;++i)
    {
        f=f_one+f_two;

        f_two=f_one;
        f_one=f;
    }

    return f;
}

int main()
{
    int result_1=Sol_1(10);
    int result_2=Sol_2(10);

    cout<<result_1<<" "<<result_2<<endl;

    return 0;

}