// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <iostream>
using namespace std;

#include <algorithm>

//由于是排序好的，因此0在下标为0的位置，1在下标为1的位置。。。。
//由于m不再数组中，m+1处在下标为m的位置，m+2处在下标为m+1的位置。。。。。。
//因此问题转换为在排序数组中找到第一个值和下标不相等的元素

int GetMissingN(const int* data, int leng)
{
    if(data==nullptr || leng<0)
        return -1;

    int left=0;
    int right=leng-1;

    while(left<=right)
    {
        int mid=(right+left)>>1;
        if(data[mid]!=mid)
        {
            if(mid==0 || data[mid-1]==mid-1)
                return mid;

            right=mid-1;
        }
        else
            left=mid+1;
    }

    if(left==leng)
        return leng;

    return -1;
}

int main()
{
   int data[] = { 1, 2, 3, 4, 5 };
   
    int result=GetMissingN(data,sizeof(data)/sizeof(int));

    cout<<result<<endl;
   
   
    return 0;
}
