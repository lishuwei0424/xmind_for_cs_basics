/*
// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
// 能使用atoi或者其他类似的库函数。
*/

#include <iostream>
using namespace std;

#include <algorithm>

long long StrToIntCore(const char* str,bool minus);

enum Status{kValid=0,kInvalid};
int g_nStatus=kValid;

int StrToInt(const char* str)
{
    g_nStatus=kInvalid;
    long long num=0;

    if(str!=NULL && *str!='\0')
    {
        bool minus=false;//负数
        if(*str=='+')//考虑这个符号，继续往后查找
        {
            str++;
        }

        else if(*str=='-')//遇到-这个符号，给个标注，我是负的
        {
            str++;
            minus=true;
        }

        if(*str!='\0')
        {
            num=StrToIntCore(str,minus);
        }
    }
}

long long StrToIntCore(const char* str,bool minus)
{
    long long num=0;

    while(*str!='\0')
    {
        if(*str>='0' && *str<='9')//这才是合法输入
        {
            int flag=minus?-1:1;
            
            num=num*10+flag*(*str-'0');

            if(!minus && num>0x7FFFFFFFF || 
            (minus && num<(signed int)0x80000000))//大于最大正整数或者小于最小负整数
            {
                num=0;
                break;
            }

            str++;
        }
        //非法输入
        else
        {
            num=0;
            break;
        }
        
    }

    if(*str=='\0')
    {
        g_nStatus=kValid;
    }

    return num;
}
int main()
{
   const char* string="23";
   int result=StrToInt(string);

    cout<<result<<endl;

    return 0;

}