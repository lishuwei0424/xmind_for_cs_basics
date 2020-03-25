// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
//{1,-2,3,10,-4,7,2,-5}  {3,10,-4,7,2} 18

 #include <iostream>
using namespace std;

//初始化和为0,第一步加上第一个数字1,此时和为1，第二步加上数字-2,和变为-1
//第三步加上数字3,则为2。比3本身小，所以不如从3开始的数组和大，因此之前的抛弃

//因此3+10-4=9，此时把之前得到的最大和13记录到最大数组和中，以后相大于13就更新
//遇到小于上一次更新的数就退出

//为了区分字子数组和的最大值是0和无效输入这两种情况，定义一个全局变量来标记是否有效输入
bool g_InvalidInput=false;

int FindGreatestSumOfSubArray(int *data,int leng)
{
    if(data==NULL || leng<0)
    {
        g_InvalidInput=true;
        return 0;
    }

    g_InvalidInput=false;

    int nCurSum=0;
    int nGreatestSum=0x80000000;
    for(int i=0;i<leng;i++)
    {
        if(nCurSum<=0)
            nCurSum=data[i];

        else
           nCurSum+=data[i];

        if(nCurSum>nGreatestSum)
            nGreatestSum=nCurSum;

    }

    return nGreatestSum;
}
int main()
{
    // 典型输入，单调升序的数组的一个旋转
      int data[] = {1, -2, 3, 10, -4, 7, 2, -5};

    int result=FindGreatestSumOfSubArray(data,sizeof(data)/sizeof(int));

    cout<<result<<endl;

    return 0;
}