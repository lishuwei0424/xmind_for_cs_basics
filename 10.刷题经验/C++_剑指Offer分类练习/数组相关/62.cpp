// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

#include <cstdio>
#include <list>

#include <iostream>


using namespace std;

//约瑟夫问题
//定义一个list,创建一个共有n个节点的环形链表，然后每次在这个环形链表中删除第m个节点
//std::list模拟一个环形链表，因此每当迭代器扫描到链表末尾的时候，记得把迭代器移动到链表头部
//这相当于按照顺序在一个圆圈里遍历了

int LastRemaining(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    unsigned int i = 0;
    
    //环形链表赋值
    list<int> numbers;
    for(i = 0; i < n; ++ i)
        numbers.push_back(i);
    
    //迭代器
    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1)
    {   
        //循环找到要删除的额节点
        for(int i = 1; i < m; ++ i)
        {
            current ++;
            //迭代器扫描到链表结尾时候，将其指向第一个数
            if(current == numbers.end())
                current = numbers.begin();
        }

        list<int>::iterator next = ++ current;
        if(next == numbers.end())
            next = numbers.begin();

        -- current;
        numbers.erase(current);
        //第二次循环的开始
        current = next;
    }

    return *(current);
}

int main()
{
    int result=LastRemaining(5,3);
    cout<<result<<endl;

    return 0;
}