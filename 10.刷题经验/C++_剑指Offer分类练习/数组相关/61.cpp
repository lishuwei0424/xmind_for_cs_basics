// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

 #include <iostream>
using namespace std;

//首先将数组排序，
//其次统计数组中0的个数
//最后统计排序之后的数组中相邻数字之间的空缺数
//如果空缺的总数小于或者等于0的个数，那么这个数组就是连续的
#include <cstdio>
#include <cstdlib>

int compare(const void *arg1, const void *arg2);
bool IsContinuous(int* data,int leng)
{
    if(data==nullptr || leng<1)
        return false;

    qsort(data,leng,sizeof(int),compare);

    int NumOf0=0;
    int NumOfK=0;

    //统计数组中0的个数
    for(int i=0;i<leng && data[i]==0;++i)
        ++NumOf0;

    //统计数组中的空数目
    int small=NumOf0;
    int big=small+1;
    while(big<leng)
    {
        //如果两个数字相等，有对子，不可能是顺子
        if(data[small]==data[big])
            return false;
        //空缺数
        NumOfK=data[big]-data[small]-1;
        small=big;
        ++big;
    }

    return (NumOfK>NumOf0)?false:true;
}

int compare(const void *arg1,const void* arg2)
{
    return *(int*)arg1-*(int*)arg2;
}
int main()
{
      int data[] = { 1, 3, 2, 5, 4 };
  
   bool result=IsContinuous(data,sizeof(data)/sizeof(int));

    cout<<result<<endl;

    return 0;
}