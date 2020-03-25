/*
一个关键值数组，任意输入一个数字k，使用折半查找算法找到K在数组中的下标
*/

#include <iostream>
using namespace std;

int bin_search(int key[],int len,int k)
{
    int low=0,high=len-1,mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(key[mid]==k)
            return mid;

        if(k>key[mid])
            low=mid+1;

        else
        {
            high=mid-1;
        }
    }

    return -1;

}

//递归
int bin_search_recur(int key[],int low,int high,int k)
{
    int mid;
    if(low>high)
        return -1;

    else
    {
        mid=(low+high)/2;

        if(key[mid]==k)
            return mid;
        if(k>key[mid])
            return bin_search_recur(key,mid+1,high,k);
        
        else
           return bin_search_recur(key,low,mid-1,k);
    }
}

int main()
{
    int data[10]={1,3,5,7,10,12,15,19,21,50};

    int result=bin_search(data,10,15);
    cout<<result<<endl;
    int result2=bin_search_recur(data,0,9,15);
    cout<<result2<<endl;

    return 0;
}