/*
// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。
*/

#include <iostream>
using namespace std;

#include <cstring>

//每次通过对10取余看看个位数是不是1
//如果这个数大于10,则除以10之后再判断个位数是不是1
int NumberOf1(unsigned int n);
int NOf1(unsigned int n)
{
    int count=0;
    for(unsigned int i=1;i<=n;++i)
        count+=NumberOf1(i);
    
    return count;
}

int NumberOf1(unsigned int n)
{
    int count=0;
    while(n)
    {
        if(n%10==1)
            count++;

        n=n/10;
    }
    return count;
}

//方法2
//例如输入的数字特别大 n=21345
//分成两段 1～1345  1346～21345
//先来分析1346～21345  1出现在10000～19999中的最高为万位的次数是1×10×10×10×10
//1出现在10000～12345中的次数是除去最高数字之后剩下的数字再加上1（2345+1=2346）

//分析1出现在除最高位之外的其他4位数的情况。
//1346～21345 分成1346～11345 和 11346～21345
//每一段上下的4位数选择其中一个为1,其余3个可有0～9的选择，即4×10×10×10×2

//至于在1～1345中1出现的次数，可用递归楼
//因为把21345最高位去掉得到的就是1345
int PowerBase10(unsigned int n);
int NumberOfOf1(const char* strN);

int NumOf1(int n)
{
    if(n<=0)
        return 0;

    char strN[50];
    //把数字转成字符串
    sprintf(strN,"%d",n);

    return NumberOfOf1(strN);
}

int NumberOfOf1(const char* strN)
{
    if(!strN || *strN<'0' || *strN>'9' || *strN=='\0')
        return 0;

    int first=*strN-'0';//取最高位
    cout<<"first "<<first<<endl;

    
    unsigned int leng=static_cast<unsigned int>(strlen(strN));

    if(leng==1 && first==0)
        return 0;

    if(leng==1 && first>0)
        return 1;

    //count1是数字10000～19999的第一位为1的数字出现的次数
    int count1=0;
    if(first>1)
        count1=PowerBase10(leng-1);
    else if(first==1)
        count1=atoi(strN+1)+1;//atoi为string转int

    //count2是1346～21345除第一位之外的数位中的数目
    int count2=first*(leng-1)*PowerBase10(leng-2);

    //count3是1～1345中的数目
    int count3=NumberOfOf1(strN+1)+1;

    return count1+count2+count3;

    
}

int PowerBase10(unsigned int n)
{
    int result=1;
    for(unsigned int i=0;i<n;++i)
        result*=10;

    return result;
}

int main()
{  
    int result1= NOf1(21345);
    cout<<result1<<endl;

    int result2=NumOf1(21345);
    cout<<result2<<endl;
  

    return 0;

}