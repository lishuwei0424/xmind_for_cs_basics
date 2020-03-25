// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。
#include <iostream>
using namespace std;

#include <cstring>


//定义small=1,big=2,计算和，当和小于s时候，增大big，当和大于s时候，增大small
//结束条件是 small=（1+s)/2
 void Print(int small,int big);
void FindContinuousSequence(int s)
{
    int small=1;
    int big=2;

    while(small<((s+1)/2))
    {
        int CurrentSum=0;
        for(int i=small;i<=big;i++)
            CurrentSum+=i;

        if(CurrentSum==s)
        {
            // cout<<small;
            // cout<<big;
           

            //此时已经满足一對了
            //满足了就调用打印函数呗
            Print(small,big);

            cout<<endl;

            //继续寻找下一对哦
            big++;
        }

        else if(CurrentSum>s)
            small++;
        else
            big++;
    }
}

 void Print(int small,int big)
 {
     for(int i=small;i<=big;i++)
        cout<<i<<endl;
 }

int main()
{  
      int s=15;
    FindContinuousSequence(s);
  

    return 0;

}