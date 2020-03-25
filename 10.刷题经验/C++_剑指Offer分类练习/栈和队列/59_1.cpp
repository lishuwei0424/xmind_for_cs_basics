/*
// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，
*/

#include <iostream>
using namespace std;

#include <stack>
#include <assert.h>

#include <vector>
#include <deque>


vector<int> maxInWindows(const vector<int>& num,unsigned int size)
{
    vector<int> maxInWindows;

    if(num.size()>=size && size>=1)
    {
        deque<int> index;//建立一个双端队列，为了使他能从前后两端删除和插入数字，存放队列的下标志
       
       //前三个数字构成一个滑动窗口
        for(unsigned int i=0;i<size;i++)
        {   
            //数组第一个数字是2,把它存入队列，第二个数字是3,由于它比前一个数字2大，因此2不可能成为
            //滑动窗口最大值，先把2从队列删除，再把3存入
            while(!index.empty() && num[i]>=num[index.back()])//存放可能最大值的索引
                index.pop_back();

            index.push_back(i);
        }
        //以上队列中已经有三个数字，而他的最大值4位于队列的头部

        for(unsigned int i=size;i<num.size();++i)
        {
            maxInWindows.push_back(num[index.front()]);//把可能最大值的下表对应的数字存入最大窗口中

            while(!index.empty() && num[i]>=num[index.back()])//把下一次滑动窗口中不可能的最大值的下标删除
                index.pop_back();
            
            //当一个数字的下标与当前处理的数字的下标之差大于或者等于滑动窗口大小时，这个数字已经从窗口中滑出
            //可以从队列中删除了
            if(!index.empty() && index.front()<=(int)(i-size))
                index.pop_front();//对头删除

            index.push_back(i);
        }

        maxInWindows.push_back(num[index.front()]);
    }

    return maxInWindows;
}

int main()
{
     int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

    //int expected[] = { 4, 4, 6, 6, 6, 5 };
   // vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 3;

    vector<int> vecExpected=maxInWindows(vecNumbers,size);
    for(auto it=vecExpected.begin();it!=vecExpected.end();++it)
        cout<<*it<<endl;
} 