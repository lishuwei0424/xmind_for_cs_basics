/*
判断一个数组序列是不是栈的弹出序列
*/

#include <iostream>
using namespace std;

#include <stack>
#include <assert.h>


bool IsPopOrder(const int* pPush, const int* pPop,int len)
{
    bool is=false;

    if(pPush!=NULL && pPop!=NULL && len>0)
    {
        const int* pNextPush=pPush;
        const int* pNextPop=pPop;

        std::stack<int> stackData;

        while(pNextPop-pPop <len)
        {   
            //如果下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈
            //直到把下一个需要弹出的数字压入栈顶为止
            while(stackData.empty() || stackData.top()!=*pNextPop)
            {
                if(pNextPush-pPush ==len)
                    break;

                stackData.push(*pNextPush);

                pNextPush++;
            }
        //如果所有数字都压入栈后仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列
            if(stackData.top()!=*pNextPop)
                break;

            stackData.pop();
            pNextPop++;

        }

        if(stackData.empty() && pNextPop-pPop==len)
            is=true;
    }
        return is;
}

int main()
{
     const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    bool result=IsPopOrder(push,pop,nLength);
    cout<<result<<endl;
}