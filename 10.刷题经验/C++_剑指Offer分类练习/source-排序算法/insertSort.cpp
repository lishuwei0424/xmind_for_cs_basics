/*
编写一个程序，将一个整型数组中的数据从大到小排列，要求使用直接插入排序
*/

#include <iostream>
using namespace std;

void insertSort(int data[],int len)
{
    int i,j,tmp;

    for(i=1;i<len;i++)
    {
        tmp=data[i];

        j=i-1;
        while(j>=0 && tmp>data[j])//从大到小排序
        {
            data[j+1]=data[j];//循环右移，直到找到data[i]应该放置的位置
            j--;
        }

        data[j+1]=tmp;//将元素tmp插入指定位置
    }

     
    
}

int main()
{
    int data[9]={0,3,1,2,4,6,6,10,5};
    insertSort( data,9);
    for(int i=0;i<9;i++)
        cout<<data[i]<<endl;

    return 0;
}