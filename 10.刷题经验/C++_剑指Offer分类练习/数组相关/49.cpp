// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

#include <iostream>
using namespace std;

//若一个数能被2整除，就连续除以2,同理连续除以3,5
//如果最后得到的是1,那么这个数就是丑数

bool IsUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;

    return (number == 1) ? true : false;
}

//只需要按照顺序判断每个整数是不是丑数
int GetUglyNumber(int index)//1500
{
    if(index <= 0)
        return 0;

    int number = 0;
    int uglyFound = 0;
    while(uglyFound < index)
    {
        ++number;

        if(IsUgly(number))
            ++uglyFound;
    }

    return number;
}


int main()
{
    

    int result=GetUglyNumber(15);
    cout<<result<<endl;

    return 0;
}