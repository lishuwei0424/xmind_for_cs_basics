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

 unsigned int FindFirstBitIs1(int num);
 bool IsBit1(int num,unsigned int indexBit);
//{2,4,3,6,3,2,5,5}
//依次异或数组中的每个数字，最终得到的就是两个只出现一次的数字的异或结果
//相同数字异或为0
void FindNumsApperaOnce(int data[],int leng,int* num1,int* num2)
{
    if(data==NULL || leng<2)
        return;

    int resultExclusiveOR=0;
    for(int i=0;i<leng;++i)
        resultExclusiveOR^=data[i];

    cout<<resultExclusiveOR<<endl;//最后得到的是4和6异或的额结果2

    //找到整数resultExclusiveOR的二进制表示中的最右边是1的位
    unsigned int indexOf1=FindFirstBitIs1(resultExclusiveOR);

    cout<<indexOf1<<endl;

    *num1=*num2=0;
    for(int j=0;j<leng;j++)
    {   
        //判断data[j]从右边起的第indexOf1是不是1,进行分组
        //然后依次异或，得到的就是单个数
        if(IsBit1(data[j],indexOf1))
        {
             *num1^=data[j];
             cout<<"data"<<data[j]<<endl;
        }
           
        else
            *num2^=data[j];
    }

}

 unsigned int FindFirstBitIs1(int num)
 {
     int indexBit=0;
     //n和1做与运算，判断n的最低位是不是1,若是1,则结果为1，否则为0
     //接着把1左移动一位得到2，再和n做与运算，就能判断n的次低位是不是1.。。。
    // while(((num&1)==0) &&(indexBit<8*sizeof(int)))
      while(((num&1)==0) && num>=0)
     {   
         cout<<"num"<<num<<endl;

         num=num>>1;
         ++indexBit;

     }

     return indexBit;
 }

 bool IsBit1(int num,unsigned int indexBit)
 {
     num=num>>indexBit;//2右移动1位是1
     return (num&1);//1&1返回1，倒数第2位是1
 }

int main()
{
    int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
    
    int result1,result2;
   FindNumsApperaOnce(data,sizeof(data)/sizeof(int),&result1,&result2);

   cout<<result1<<" "<<result2<<endl;

    

    return 0;
}