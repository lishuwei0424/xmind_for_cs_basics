/*
编写一个程序，将一个整型数组中的数据从大到小排列，要求使用希尔排序
*/

#include <iostream>
using namespace std;

//希尔排序分段进行排序，使得元素交换是跳跃的，减少了元素交换次数
void shellSort(int data[],int len)
{
   int i,j,flag,tmp,gap=len;

   while(gap>1)//间隔为1比较结束
   {
       gap=gap/2;//按照经验值，每次间隔缩小一半
       do
       {
          flag=0;//子序列可以使用冒泡
          for(i=0;i<len-gap;i++)
          {
              j=i+gap;
              if(data[i]>data[j])
              {
                  tmp=data[i];
                  data[i]=data[j];
                  data[j]=tmp;
                  flag=1;
              }
          }
       }while(flag!=0);//改进了冒泡排序
   }
   
    
}

int main()
{
    int data[9]={0,3,1,2,4,6,6,10,5};
    shellSort( data,9);
    for(int i=0;i<9;i++)
        cout<<data[i]<<endl;

    return 0;
}