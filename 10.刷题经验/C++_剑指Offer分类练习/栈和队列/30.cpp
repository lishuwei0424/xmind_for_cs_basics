/*
找到一个栈中的最小元素
*/

#include <iostream>
using namespace std;

#include <stack>
#include <assert.h>


//声明一个栈
template <typename T>
 class StackWithMin
{
    public:
        StackWithMin(){}
        virtual ~StackWithMin(){}

        T& top();
        const T& top() const;

        void push(const T& value);
        void pop();

        const T& min() const;

        bool empty() const;
        size_t size() const;

    private:
        stack<T> m_data;//数据栈，存放栈的所有元素
        stack<T> m_min;//辅助栈，存放栈的最小元素
};


template <typename T> 
T& StackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T> 
const T& StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T> 
bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> 
size_t StackWithMin<T>::size() const
{
    return m_data.size();
}

template <typename T>
void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);

    if(m_min.size()==0 || value<m_min.top())
        m_min.push(value);

    else
    {
        m_min.push(m_min.top());//为了保存长度一致，把自身最小放在上面
    }
    
}

template <typename T> 
void StackWithMin<T>::pop()
{
    assert(m_data.size()>0 && m_min.size()>0);

    m_data.pop();
    m_min.pop();
}

template <typename T>
 const T& StackWithMin<T>::min() const
{
    assert(m_data.size()>0 && m_min.size()>0);

    return m_min.top();
}

int main()
{
   
    StackWithMin<int> stack;

    stack.push(3);
    stack.push(4);
    stack.push(3);
    stack.push(2);

    int min=stack.min();
    cout<<min<<endl;
 

    return 0;

}