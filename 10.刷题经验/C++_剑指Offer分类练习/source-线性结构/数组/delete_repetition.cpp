/*
删除一个只包含正整数的数组中的重复元素
输入：{2,3,5,2,5,3,6,9,11,6}
输出：{2,3,5,6,9,11}
*/

#include <iostream>
using namespace std;
#define FLAG -1

//方法1 ，每次比较，相同调用删除
void DelElem(int Sqlist[], int *len, int i);
void purge(int a[],int *len)
{
    int i=0,j;
    while(i< *len)
    {
        j=i+1;
        while(j<*len)
        {
            if(a[i]==a[j])
            {
                DelElem(a,len,j+1);
            }
            else
            {
                j++;
            }
        }

        i++;
    }
}

void DelElem(int Sqlist[], int *len, int i)
{
    int j;
    if(i<1 || i>*len)
    {
        return ;
    }

    for(j=i; j< *len; j++)
    {
        Sqlist[j-1]=Sqlist[j];//将第i以后的元素前移
    }

    *len=*len-1;//表长减1

 
}

//方法2,遇到相同，做标记，最后一次性删除带标记的
void deleteElem(int a[],int *len)
{
    int i,j;
    int length=*len;

    for(i=0;i<length;i++)
    {
        if(a[i]!=FLAG)
        {
            for(j=i+1;j<length;j++)
            {
                if(a[j]==a[i])
                {
                    a[j]=FLAG;
                }
            }
        }
    }
    
   

    //删除
    for(i=0;a[i]!=FLAG;i++);//找到第一个特殊标记

    for(j=i+1;j<length;)
    {
        if(a[j]!=FLAG)
        {
            a[i++]=a[j++];

            
        }
        else
        {
            j++;
        }

        *len=i;//删除元素后数组的额实际长度会发生变化
    }
}

int main()
{
    int a[]={2,3,5,2,5,3,6,9,11,6};
    int len=10;
    // purge(a,&len);
    
    // for(int i=0;i<len;i++)
    //     cout<<a[i]<<endl;


     deleteElem(a,&len);
    for(int k=0;k<len;k++)
        cout<<a[k]<<endl;

    return 0;
}