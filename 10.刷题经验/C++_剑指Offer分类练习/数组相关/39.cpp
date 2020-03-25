
// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

#include <iostream>
using namespace std;

//出现次数超过一半，则他出现的次数大于其他次数的和
//定义保存两个值，一个是次数，首次为1，一个数组中的一个数字
//遍历到下一个数字的时候，和前面相等就加1,不等就减去1
//当次数为0的时候，重新保存下一个数，继续这个步骤
//则最后一个不为0的数必然是超过一半的


bool g_bInputInvalid=false;

//判断输入的有效性
bool CheckInvalidArray(int* datas,int leng)
{
    g_bInputInvalid=false;
    if(datas==NULL && leng<=0)
        g_bInputInvalid=true;

    return g_bInputInvalid;
}

//检查次数是否超过一半
bool CheckMoreThanHalf(int* datas,int leng,int data )
{
    int times=0;
    for(int i=0;i<leng;++i)
    {
        if(datas[i]==data)
            times++;
    }

    bool isMoreThanHalf=true;
    if(times*2<=leng)
    {
        g_bInputInvalid=true;
        isMoreThanHalf=false;
    }

    return isMoreThanHalf;

}

int Solution(int* datas,int leng)
{
    if(CheckInvalidArray(datas,leng))
        return 0;

    int result=datas[0];
    int times=1;
    for(int i=1;i<leng;++i)
    {
        if(times==0)
        {
           result=datas[i];
           times=1;
        }

        else if(datas[i]==result)
            times++;

        else
            times--;
    }

    if(!CheckMoreThanHalf(datas,leng,result))
        result=0;

    return result;
}

int main()
{
   int datas[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int result=Solution(datas,sizeof(datas)/sizeof(int));

    cout<<result<<endl;
   
   
    return 0;
}
