/*
// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/

#include <iostream>
using namespace std;

void Reorder(int *data,unsigned int leng,bool (*func)(int));
bool isEven(int n);

void ReorderOddEven(int *data,unsigned int leng)
{
    Reorder(data,leng,isEven);
}
//定义两个指针，最前和最后，最前指向偶数，最后指向奇数时候，交换
void Reorder(int *data,unsigned int leng,bool (*func)(int))
{
    if(data==NULL || leng==0)
        return;

    int *begin=data;
    int *end=data+leng-1;

    while(begin<end)
    {
        while(begin<end && !func(*begin))//从最开始查找满足func函数的位置
            begin++;

        while(begin<end && func(*end))//从最后往前找
            end--;

        if(begin<end)
        {
            int tmp=*begin;
            *begin=*end;
            *end=tmp;
        }
    }
}

bool isEven(int n)
{
    return (n&1)==0;
}



int main()
{  
    int data[] = {1, 2, 3, 4, 5, 6, 7};
   ReorderOddEven(data,sizeof(data)/sizeof(int));
    for(int i=0;i<7;i++)
        cout<<data[i]<<endl;

    return 0;

}