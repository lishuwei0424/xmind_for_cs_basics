// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

#include <iostream>
using namespace std;

#include <algorithm>


//定义两个指向，最前面后最后面，相加的和大于 s，则移动后面的数往前一个格子，依次
void  FindTwoOfSum(const int* data, int leng,int s,int* output)
{
    if(data==nullptr || leng<0)
        return;

    int left=0;
    int right=leng-1;

    while(left<=right)
    {
        int CurrentSum=data[left]+data[right];
        if(CurrentSum>s)
            right--;
        else if(CurrentSum<s)
            left++;
        else 
        {
            output[0]=data[left];
            output[1]=data[right];
            break;//这个不能少啊啊啊啊啊，找到了就退出来啊啊啊啊 
        }
    }
}

int main()
{
   int data[] = { 1, 2, 4, 7, 11,15 };
   int output[]={};
   FindTwoOfSum(data,sizeof(data)/sizeof(int),15,output);
   for(int i=0;i<2;i++)
        cout<<output[i]<<endl;
    
   
   
    return 0;
}
