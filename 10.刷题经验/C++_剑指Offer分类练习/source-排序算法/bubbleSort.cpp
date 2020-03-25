/*
编写一个程序，将一个整型数组中的数据从大到小排列，要求使用冒泡
*/

#include <iostream>
using namespace std;

void bubbleSort(int data[],int len)
{
  
   int tmp;
   int i,j;
   int flag=1;
   for(i=0;i<len-1 && flag==1;i++)//排序的汤数
   {    
       flag=0;
       for(j=i+1;j<len;j++)
       {
           if( data[i]<data[j])
           {
               tmp=data[j];
               data[j]=data[i];
               data[i]=tmp;
               flag=1;//发生数据交换，标志为1 
           }
       }
   }
     
    
}

int main()
{
    int data[9]={0,3,1,2,4,6,6,10,5};
    bubbleSort( data,9);
    for(int i=0;i<9;i++)
        cout<<data[i]<<endl;

    return 0;
}