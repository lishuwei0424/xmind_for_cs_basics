
// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <iostream>
using namespace std;

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字

// 排序数组0，1,2,3，4.。。。。如果没有重复，则下标对应的就是值 
//时间复杂度n,比3_1效率高        
int *duplicate(int numbers[], int length,int duplication[])
{  

    if(numbers == nullptr || length <= 0)
         return NULL;

    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return NULL;
    }
    
    int k=0;
    
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] != i)
        {     
            if(numbers[i] == numbers[numbers[i]])
            {
                duplication[k] = numbers[i];
                k++;   
            }
               
            // 交换numbers[i]和numbers[numbers[i]]             
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
      
    }

    return duplication;
   
}



int main()
{
    int data[]={2,3,1,0,2,5,3};
    int duplication[]={0};
    int *p;
    p=duplicate(data, sizeof(data)/sizeof(int),duplication);
    cout<<"sizeof"<<sizeof(p)/sizeof(int)<<endl;

    for(int h=0;h<sizeof(p)/sizeof(int);h++)
     	cout<<"result"<<p[h]<<endl;
   
   
    return 0;
}
