/*
编写一个程序，将一个整型数组中的数据从大到小排列，要求使用快速排序
*/

#include <iostream>
using namespace std;

//快速排序是先挑选一个基准，把比它小的放在左边，比它大的放在右边
//之后在他的左边继续挑选一个基准，执行上述过程
//在它右边也是一样
void swap(int *a,int *b)
{                            /*交换序列中元素的位置*/
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

//s,t表示每一序列的首尾元素
void quickSortArray(int array[], int s,int t)
{
    int low,high;
    if(s<t)
    {
        low = s;
        high = t+1;
        while(1)
        {
            do low++;
            while(array[low]>=array[s] && low!=t);        /*array[s]为基准元素，重复执行low++操作*/

            do high--;
            while(array[high]<=array[s] && high!=s);      /*array[s]为基准元素，重复执行high--操作*/

            if(low<high)
                swap(&array[low],&array[high]);           /*交换array[low]和array[high]的位置*/
            else
                break;
        }
        
        swap(&array[s],&array[high]);                   /*将基准元素与array[high]进行交换*/
        quickSortArray (array,s,high-1);                /*将基准元素前面的子序列快速排序*/
        quickSortArray (array,high+1,t);                /*将基准元素后面的子序列快速排序*/
    }
}

void quickSort(int array[], int arraySize) {
	quickSortArray(array, 0, arraySize-1);
}

main()
{
    int i,array[10];
    printf("Input ten integer\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&array[i]);                /*循环输入10个整数*/
    }

    quickSort(array,10);                     /*执行快速选择排序*/
    printf("\nThe result of quick sort is\n");
    for(i=0;i<10;i++) {
        printf("%d ",array[i]);                    /*输出排序后的结果*/
	}
    getchar();
	getchar();
}