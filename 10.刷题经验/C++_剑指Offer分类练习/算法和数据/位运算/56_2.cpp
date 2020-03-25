/*
// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
*/

#include <iostream>
using namespace std;

//位运算
//n和1做与运算，判断n的最低位是不是1,接着把1左移动一位得到2，再和n做与运算，就能判断n的次低位是不是1.。。。

//把一个整数减去1,再和原整数做与运算，会把该整数最右边的1变为0
//那么一个整数的二进制表示中有多少个1,就可以进行多少次这样的操作

 int FindNumberApperingOnce(int data[],int leng)
 {
     if(data==NULL || leng<=0)
        return 0;

     //存储每一位的和
     //32位，不能写成4位
     int bitSum[32]={0};
     for(int i=0;i<leng;++i)
     {
         int bitMask=1;
         for(int j=31;j>=0;--j)
         {
             int bit=data[i]&bitMask;
             if(bit!=0)
                bitSum[j]+=1;

            bitMask=bitMask<<1;
         }

         
     }
      for(int j=31;j>=0;--j)
         {
            cout<<"bitSum"<<"["<<j<<"]"<<bitSum[j]<<endl;
         }

   //计算如果出现三次，每一位的和除3余数肯定是0
     int result=0;
     for(int i=0;i<32;++i)
     {
         result=result<<1;//0左移动1位还是0
         result+=bitSum[i]%3;

         cout<<result<<endl;
     }

     return result;
 }

int main()
{
    int data[] = {  1, 1, 2, 2, 2, 1, 3  };
    
    int result=FindNumberApperingOnce(data,sizeof(data)/sizeof(int));

   cout<<result<<endl;

    

    return 0;
}