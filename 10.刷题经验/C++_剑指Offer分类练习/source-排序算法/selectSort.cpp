/*
编写一个程序，将一个整型数组中的数据从大到小排列，要求使用选择排序
*/

#include <iostream>
using namespace std;

//每次选择序列中的最小元素，让他它未排序的第一个元素交换
void selectSort(int data[],int len)
{
  
   int tmp;
   int i,j;
   int min;
   for(i=0;i<len-1;i++)
   {
       min=i;

       for(j=i+1;j<len;j++)
       {
           if(data[min]>=data[j])
           {
               min=j;//记录最小元素的位置
           }
       }

       if(min!=i)
       {
           tmp=data[min];
           data[min]=data[i];
           data[i]=tmp;
       }

   }
     
    
}

int main()
{
    int data[9]={0,3,1,2,4,6,6,10,5};
    selectSort( data,9);
    for(int i=0;i<9;i++)
        cout<<data[i]<<endl;

    return 0;
}