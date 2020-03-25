// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。
#include <iostream>
using namespace std;

#include <cstring>

//排序数组，想到用二分查找，找到第一个3和最后一个3不就完事了
//第一个
//中间数字比k大，则在左边，否则在右边，继续查找
//最后一个k

int GetFirstK(int* data,int leng,int k,int start,int end)
{
    if(start>end)
        return -1;

    int mid=(start+end)/2;
    int midData=data[mid];

    if(midData==k)
    {
        //比较左一个或者右一个是否为k，不是的话就是第一个左或右的
        if((mid>0 && data[mid-1]!=k) || mid==0)
            return mid;

        else
          end=mid-1;

    }
    else if(midData>k)
        end=mid-1;
    else
        start=mid+1;

    return GetFirstK(data,leng,k,start,end);
}

int GetLastK(int* data,int leng,int k,int start,int end)
{
    if(start>end)
        return -1;

    int mid=(start+end)/2;
    int midData=data[mid];

    if(midData==k)
    {
        if((mid<leng-1 && data[mid+1]!=k) || mid==leng-1)
            return mid;
        else
            start=mid+1;

    }
    else if(mid<k)
        start=mid+1;
    else
        end=mid-1;

    return GetLastK(data,leng,k,start,end);

}

int GetNumberOfK(int* data,int leng,int k)
{
    int count=0;
    if(data!=nullptr && leng>0)
    {
        int first=GetFirstK(data,leng,k,0,leng-1);
        int last=GetLastK(data,leng,k,0,leng-1);

        if(first>-1 && last>-1)
            count=last-first+1;
    }

    return count;
}

int main()
{  
      int data[] = {3, 3, 3, 3, 4, 5};
    int result=GetNumberOfK(data,sizeof(data)/sizeof(int),3);
    cout<<result<<endl;
  

    return 0;

}