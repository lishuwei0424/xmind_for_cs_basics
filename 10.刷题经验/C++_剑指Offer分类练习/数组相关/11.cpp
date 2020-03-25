/*
// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
*/

#include <iostream>
using namespace std;

//定义两个指针，分别指向第一个p1和最后一个p2，
//判断两者中间值p>p1，说明在第一队列，使跑p1=p，再比较p1和p2的中间值p,p<p2,在第二队列，使p2=p，两者相差1,则返回p2
//{1,0,1,1,1}这种情况单独拿出来，for循环查找最小值
int MinInOrder(int* data,int index1,int index2);
int Min(int* data,int len)
{
    // if(data==NULL || len<0)
    //     throw new std::exception("Invaild parameters");

    int index1=0;
    int index2=len-1;

    int mid=index1;
    while(data[index1]>=data[index2])
    {   
        //终止条件
        if(index2-index1==1)
        {
            mid=index2;
            break;
        }

        mid=index1+(index2-index1)/2;

        //如果三者相等，顺序查找
        if(data[index1]==data[index2] && data[mid]==data[index1])
            return MinInOrder(data,index1,index2);

        if(data[mid]>=data[index1])
            index1=mid;

        if(data[mid]<=data[index2])
            index2=mid;


    }

    return data[mid];
}

int MinInOrder(int* data,int index1,int index2)
{
    int result=data[index1];
    for(int i=index1+1;i<=index2;++i)
    {
        if(result>data[i])
            result=data[i];
    }

    return result;
}

int main()
{
    // 典型输入，单调升序的数组的一个旋转
    int data[] = { 3, 4, 5, 1, 2 };

    int result=Min(data,sizeof(data)/sizeof(int));

    cout<<result<<endl;

    return 0;
}