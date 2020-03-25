/*
有一个整数数组，求出两两之差绝对值的最小值，只要计算出这个最小值
不需要知道是哪两个数
*/

#include <iostream>
using namespace std;

int getMinDifference(int data[],int len)
{
    int minVal=10000;
    int row=0;
    int rank=0;

//计算矩阵的上三角阵
    for(row=0;row<len;row++)
    {
        for(rank=row+1;rank<len;rank++)
        {
            if(abs(data[rank]-data[row])<minVal)
            {
                minVal=abs(data[rank]-data[row]);
            }
        }
    }

    return minVal;
}

int main()
{
    int data[]={1,12,23,4,25,20,2};

    int absdifference= getMinDifference( data,sizeof(data)/sizeof(int));

    cout<<"abs "<<absdifference<<endl;

    return 0;
}