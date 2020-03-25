/*
顺序表的逆序
*/

#include <iostream>
using namespace std;


void reverseSqList(int a[],int len)
{
    //定义两个变量，指向头和尾部，两者交换
    int buf;
    int low=0;
    int high=len-1;

    while(low<high)
    {
        buf=a[low];
        a[low]=a[high];
        a[high]=buf;

        low++;
        high--;
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    reverseSqList(a,sizeof(a)/sizeof(int));
    
    for(int i=0;i<5;i++)
        cout<<a[i]<<endl;

    return 0;
}