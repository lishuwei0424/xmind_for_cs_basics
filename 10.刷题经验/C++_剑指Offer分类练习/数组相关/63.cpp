// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。

#include <iostream>
using namespace std;

//找到数组中相差最大值的两个数
//在卖价固定时候，买价最小，差值最大

int  MaxDiff(const int* data, unsigned leng)
{
    if(data==nullptr && leng<2)
        return 0;

    int min=data[0];
    int maxDiff=data[1]-min;

    for(int i=2;i<leng;++i)
    {
        if(data[i-1]<min)
            min=data[i-1];

        int currentDiff=data[i]-min;
        if(currentDiff>maxDiff)
            maxDiff=currentDiff;
    }
    return maxDiff;
}

int main()
{
    
    int data[] = { 4, 1, 3, 2, 5 };
    int result=MaxDiff(data, sizeof(data) / sizeof(int));
    cout<<result<<endl;

    return 0;
}