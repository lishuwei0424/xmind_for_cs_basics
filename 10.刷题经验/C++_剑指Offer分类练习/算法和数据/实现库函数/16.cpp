/*
// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
*/

#include <iostream>
using namespace std;

#include <algorithm>

double PowerWithUnsignedE(double base,unsigned int e);

//指数为负
//低数为负
bool InvalidInput=false;

double Power(double base,int e)
{
    InvalidInput=false;

    //if(equal(base,0.0) && e<0)
    if(e<0)
    {
        InvalidInput=true;
        return 0.0;
    }

    unsigned int absE=(unsigned int )(e);
    if(e<0)
        absE=(unsigned int)(-e);

    double result=PowerWithUnsignedE(base,absE);
    if(e<0)
        result=1.0/result;

    return result;
}

double PowerWithUnsignedE(double base,unsigned int e)
{
    double result=1.0;
    for(int i=1;i<=e;++i)
        result*=base;

    return result;
}

int main()
{
   double result=Power(-2,3);

    cout<<result<<endl;

    return 0;

}