/*
已知一个从小到大排列的有序整型数组，从中找出某个数出现的次数
*/

#include <iostream>
using namespace std;

//折半查找这个数第一次出现的位置loc_a和最后一次出现的位置loc_b,loc_b-loc_a+1;

//loc_a是key左边的，而loc_b是key右边的，依然折半查找，直到子序列中查找不到key,
//则最后一次查找到key时记录下来的位置就是loc_a或者loc_b的位置

int bin_search(int data[],int key,int len,int loc_flag)
{
    int low=0,high=len-1;
    int mid=0;

    int last=-1;//记录最终的loc_a或者loc_b

    while(low<=high)
    {
        mid=(low+high)/2;

        if(data[mid]<key)
            low=mid+1;

        else if(data[mid]>key)
            high=mid-1;

        else
        {
            //找到key
            last=mid;

            if(loc_flag==0)
                high=mid-1;//查找loc_a,调整high的值继续在左边查找
            else
                low=mid+1;//查找loc_b，在右边查找
        }
    }

    return last;//他是最终的loc_a或者loc_b为位置
}

int getDataCount(int data[],int len,int key)
{
    int loc_a,loc_b;

    loc_a=bin_search(data,key,len,0);
    loc_b=bin_search(data,key,len,1);

    if(loc_a==-1 || loc_b==-1)
        return 0;
    else
        return loc_b-loc_a+1;
}

int  main()
 {
	int array[] = {0,1,3,5,5,5,5,5,5,5,5,5,5,5,5,5,6,9,12};
	int result=getDataCount(array,19,5);
	cout<<"result "<<result<<endl;

    return 0;
}

