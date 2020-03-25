/*
将字符串循环右移动n个字符
输入：abcdefg n=3
输出：efgabcd
*/

#include <iostream>
using namespace std;

#include <cstring>
//#include <mallo.c>

int LoopMoveStr(char *str,int n)
{
    if(str==NULL || n<0)
        return 0;

    int len=0,i=0;
    char *tmp;
    len=strlen(str);

    //当n>len 时候，n=99,l=10的时候，移动99次和9次是一样的
    if(n>=len)
    {
        n=n%len;
    }

    tmp=(char*)malloc(n);
    for(i=0;i<n;i++)
    {
        tmp[i]=str[len-n+i];//将尾部的n个字符保存在开辟的缓冲区内
    }

    for(i=len-1;i>=n;i--)
    {
        str[i]=str[i-n];//将前面的len-n个字符向后移动n个位置
    }

    for(i=0;i<n;i++)
    {
        str[i]=tmp[i];//将上上步从字符串尾部取出的放在字符串首部
    }
    free(tmp);

    return 1;
}

int main()
{
    char str[20]="abcdefg";
    printf("The string is %s\n",str);
    LoopMoveStr(str,6);
    printf("The string after loop right move %d charactors is %s\n", 6, str);
    getchar();
}