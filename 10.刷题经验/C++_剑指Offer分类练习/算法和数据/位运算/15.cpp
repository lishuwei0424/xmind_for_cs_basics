/*
// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
*/

#include <iostream>
using namespace std;

//位运算
//n和1做与运算，判断n的最低位是不是1,接着把1左移动一位得到2，再和n做与运算，就能判断n的次低位是不是1.。。。

int NumberOf1(int n)
{
    int count=0;
    unsigned int flag=1;

    while(flag)
    {
        if(n&flag)
            count++;
        
        flag=flag<<1;
    }

    return count;
}

//把一个整数减去1,再和原整数做与运算，会把该整数最右边的1变为0
//那么一个整数的二进制表示中有多少个1,就可以进行多少次这样的操作
int NumberOf1_1(int n)
{
    int count=0;

    while(n)
    {
        ++count;
        n=(n-1)&n;
    }

    return count;
}

int main()
{
    // 典型输入，单调升序的数组的一个旋转
    int n=10;

    int result= NumberOf1(n);

    cout<<result<<endl;

    return 0;
}