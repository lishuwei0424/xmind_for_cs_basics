/*
// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。
*/

#include <iostream>
using namespace std;

//动态规划
//递归会造成重复计算，因此从小到大避免重复
//f(n)=f(i)*f(n-i)

int maxProduct(int leng)
{
    if(leng<2)
        return 0;
    if(leng==2)
        return 1;
    if(leng==3)
        return 2;
    
    //定义一个数组，存放每次的乘
    int* products=new int[leng+1];
    products[0]=0;
    products[1]=1;
    products[2]=2;
    products[3]=3;

    int max=0;

    //从下到上的递归
    for(int i=4;i<=leng;++i)
    {
        max=0;

        //f(n)=f(i)*f(n-i)的最大值
        for(int j=1;j<i/2;++j)
        {
            int product=products[j]*products[i-j];
            if(max<product)
                max=product;

            products[i]=max;
        }
    }

    max=products[leng];
    delete[] products;

    return max;
}


int main()
{

    int result=maxProduct(12);

    cout<<result<<endl;

    return 0;
}