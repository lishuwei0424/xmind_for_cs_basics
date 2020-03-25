
// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include <iostream>
using namespace std;

#include <algorithm>

//判断1001位是什么
//序列的前10位0-9只有10位数字，显然不符合，在从后面紧跟着的序列中找 1001-10=991位

//接下来10～99 共90×2=180位数字，180<991,因此也跳过，从后面继续找 991-180=881

//接下来100～999 共900×3=2700 2700>881，因此很明显在这里面，开始找，因为881=270×3+1
//这意味着第811位是从100开始的第270个数字 即370的中间一位 ，即是7
int countOfIntegers(int digits);
int digitAtIndex(int index,int digits);
int beginNumber(int digits);

int digitAtIndex(int index)//1001
{
    if(index<0)
        return -1;

    int digits=1;
    while(true)
    {
        int numbers=countOfIntegers(digits);

        if(index<numbers*digits)
            return digitAtIndex(index,digits);

        index-=digits*numbers;//811-1*90

        digits++;

    }

    return -1;
}

//得到m位的数字共多少个。输入2是（10～99）90个，输入3是900个
int countOfIntegers(int digits)
{
    if(digits==1)
        return 10;

    int count=(int)std::pow(10,digits-1);

    return 9*count;
}

//当我们知道要找的那一位数字位于某m位数之中后，就可以用下面函数找出那一位数字了
int digitAtIndex(int index,int digits)
{
    int number=beginNumber(digits)+index/digits;//100+811/3=370
    int indexFromRight=digits-index%digits;//3-811%3=2
    for(int i=1;i<indexFromRight;++i)
        number/=10;//37 

    return number%10;//7
}

//得到m位的第一个数字，第一个两位数是10,第一个三位数是100
int beginNumber(int digits)
{
    if(digits==1)
        return 0;

    return (int)std::pow(10,digits-1);
}

int main()
{
   
    int result=digitAtIndex(1001);

    cout<<result<<endl;
   
   
    return 0;
}
