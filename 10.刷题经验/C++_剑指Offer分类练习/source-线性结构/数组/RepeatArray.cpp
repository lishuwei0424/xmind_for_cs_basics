/*
重新排列数组使得数组左边为奇数，右边为偶数
不考虑原来数组的次序
*/

#include <iostream>
using namespace std;
//定义两个变量一个指向头，一个指向尾部，尾部往前移动，遇到奇数就放到前面

bool isEvenNum(int data)
{
    bool result=false;
    if(data%2==0)
    {
        result=true;
    }

    return result;
}

void swap(int array[],int &a,int &b)
{
    int temp=array[a];
    array[a]=array[b];
    array[b]=temp;
}
int reArrange(int array[],int len)
{
    int low=0,high=len-1;
    if(len<1 || low>=high)
        return 0;

    while(1)
    {
        while(!isEvenNum(array[low])  && low<high)
        {
            low++;//是low指向偶数元素
        }

        while(isEvenNum(array[high]) && low<high)
        {
            high--;//high指向奇数元素
        }

        if(low>=high)
            return 1;

        else
        {
            swap(array,low,high);//交换low和high元素的位置

            low++;
            high--;
        }
    }

    return 1;
}

int main()
{
    int array[10]={1,2,3,4,5,6,7,8,9,10};
   
    reArrange( array,10);

    for(int i=0;i<10;i++)
        cout<<array[i]<<endl;
}