/*
// 面试题59（二）：队列的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}
*/

#include <iostream>
using namespace std;

#include <stack>
#include <assert.h>
#include <queue>
#include <deque>
#include <exception>
template<typename T> 
class QueueWithMax
{
    public:
        QueueWithMax():currentIndex(0)
        {

        }

        void push_back(T number)
        {
            while(!maximums.empty() && number >= maximums.back().number)
                maximums.pop_back();

            InternalData internalData={number,currentIndex};
            data.push_back(internalData);
            maximums.push_back(internalData);

            ++currentIndex;
        }

        void pop_front()
        {
            // if(maximums.empty())
            //       throw new exception("queue is empty");
            
            if(maximums.front().index==data.front().index)
                maximums.pop_front();

            data.pop_front();
        }

        T max() const
        {
            // if(maximums.empty())
            //       throw new exception("queue is empty");
            
            return maximums.front().number;
        };

    
    private:
        struct InternalData
        {
            T number;
            int index;
        };

    deque<InternalData> data;//原始数据队列
    deque<InternalData> maximums;//最大值队列
    int currentIndex;
};

int main(int argc, char* argv[])
{
    QueueWithMax<int> queue;
    // {2}
    queue.push_back(2);
    // {2, 3}
    queue.push_back(3);
    // {2, 3, 4}
    queue.push_back(4);
    // {2, 3, 4, 2}
    queue.push_back(2);

    // {3, 4, 2}
    queue.pop_front();

    // {4, 2}
    queue.pop_front();
   


    return 0;
}
