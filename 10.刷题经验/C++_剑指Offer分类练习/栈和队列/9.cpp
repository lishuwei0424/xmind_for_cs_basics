/*
两个栈实现一个队列
*/

#include <iostream>
using namespace std;

#include <stack>
#include <queue>
#include <exception>

//声明一个队列类
template <typename T>
 class Queue
{
    public:
        Queue(void);
        ~Queue(void);

        void appendTail(const T& node);
        T deleteHead();

    private:
        stack<T> stack1;
        stack<T> stack2;
};


template <typename T> Queue<T>::Queue(void)
{
}

template <typename T> Queue<T>::~Queue(void)
{
}

template<typename T>
 void Queue<T>::appendTail(const T& value)
{
    stack1.push(value);
}

template<typename T> 
T Queue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {    
        while(stack1.size()>0)
        {
            T& data=stack1.top();
            stack1.pop();
            stack2.push(data);
        }  
    }

    if(stack2.size()==0)
        return NULL;
        
    T head=stack2.top();
    stack2.pop();

    return head;
}

int main()
{
    Queue<char> queue;
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    cout<<head<<endl;

    head = queue.deleteHead();
    
    queue.appendTail('d');
    head = queue.deleteHead();
   

    queue.appendTail('e');
    head = queue.deleteHead();
    head = queue.deleteHead();
 

    return 0;

}