/*
一个整数数组，元素在0-65535之间。已知相同的数字不能重复出现，0可以重复出现
且0可以通配任意字符。
设计一个算法判断该数组中的元素是否连续
*/

#include <iostream>
using namespace std;

//数组中有n个元素，数组中非0最大值与最小值之差不能超过n-1，
int isContinueArray(int data[],int len)
{
    int max=data[0],min=data[0];
    int i;
    for(i=1;i<len;i++)
    {
        //扫描数组找出最大值和最小值
        if(data[i]>max && data[i]!=0)
            max=data[i];
        else if(data[i]<min && data[i]!=0)
        {
            min=data[i];
        }
        
    }

    if(max-min >len-1)
        return 0;
    else
    {
        return 1;
    }
    
}

int main()
{
    int a[]={7,2,3,4,5};
   int result=isContinueArray(a,sizeof(a)/sizeof(int));
    
   cout<<"result "<<result<<endl;

    return 0;
}