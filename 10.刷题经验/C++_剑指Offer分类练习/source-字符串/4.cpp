/*
找出字符串“111001111110000”中0连续出现的最大次数4,1连续出现的最大次数6
*/
#include <iostream>
using namespace std;

#include <cstring>

int getMaxCount(char *str,int *max0, int *max1)
{
    int i,len;
    int tmp_max0=0,tmp_max1=0;//临时变量存放最大0 ，1
    if(str==NULL)
        return 0;

    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='0')
        {
            if(str[i-1]=='1' && i!=0)//字符串1-0的转换点
            {
                if(tmp_max1 > *max1)
                {
                    *max1=tmp_max1;
                   
                }
                 tmp_max1=0;//临时变量需要清0
            }
            tmp_max0++;
        }


         if(str[i]=='1')
        {
            if(str[i-1]=='0' && i!=0)//字符串0-1的转换点
            {
                if(tmp_max0 > *max0)
                {
                    *max0=tmp_max0;
                }
                tmp_max0=0;//临时变量需要清0
            }
             tmp_max1++;
        }

        
    }

    //因为第一次无需判断是0-1还是1-0,因此少比较了一次
        if(tmp_max1>*max1)
            *max1=tmp_max1;
        if(tmp_max0>*max0)
            *max0=tmp_max0;
        
    
        return 1;
}

int main()
{
    char str[20] = "111100110000111111";
    printf("The string is %s\n",str);
    int max0=0;
    int max1=0;
    getMaxCount(str,&max0, &max1);
    cout<<max0<<endl;
    cout<<max1<<endl;
    getchar();
}