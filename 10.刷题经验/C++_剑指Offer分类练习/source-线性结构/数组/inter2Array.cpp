/*
两个有序数组的交集

给定两个有序数组，数组中的元素是递增的，且没有重复元素，找到两个数组的交集
*/

#include <iostream>
using namespace std;

//i,j分别指向两个数组的第一个元素,如果两者相等，都往后移动
//如果i>j，则移动j,反之移动i
//相等的保存下来
int getInterSection(int array_1[],int len_1, int array_2[], int len_2, int inter[])
{
   int i=0,j=0,k=0,len=0;
   while(i<len_1 && j<len_2)//当两者有一个到头就结束
   {
       if(array_1[i]==array_2[j])
       {
           inter[k]=array_1[i];
           i++;
           j++;
           k++;
       }

       if(array_1[i]>array_2[j])
       {
           j++;
       }

       if(array_1[i]<array_2[j])
       {
           i++;
       }
   }
   len=k;

   return len;
}

//如果两者数组长度相差较大，没有必要用上述方法
//现在找到最短数组，在长数组中利用二分查找短数组中的元素即可
int bin_search(int key[],int low, int high,int k)
{
	int mid;
	if(low>high) 
    {
		return -1;
	}
	else
    {
		mid = (low+high) / 2;

		if(key[mid]==k) 
        {
			return mid;
		}

		if(k>key[mid]) 
        {
			return bin_search(key,mid+1,high,k);	/*在序列的后半部分查找*/
		} 
        else
         {
			return bin_search(key,low,mid-1,k);		/*在序列的前半部分查找*/
		}
	}
}

int getIntersection2(int array_1[], int len_1, int array_2[], 
                int len_2, int intersection[]) 

{
	int i,len_short, len_long, index, k = 0;

	int *array_short; 
	int *array_long;

	if (len_1 < len_2) 
    {			/*找到较小的数组*/
		len_short = len_1;
		len_long = len_2;
		array_short = array_1;
		array_long = array_2;
	} 
    else
     {
		len_short = len_2;
		len_long = len_1;
		array_short = array_2;
		array_long = array_1;
	}

	for (i=0; i<len_short; i++)
     {	/*遍历较小的数组*/
		index = bin_search(array_long, 0, len_long, array_short[i]);  /*调用二分查找算法*/
		if (index != -1)
         {
			intersection[k] = array_short[i];		
            /*如果index不为-1表示查找成功，返回该元素在array_long中的下标*/
			k++;
		}
	}

	return k;			/*返回数组intersection的长度*/
}


int main()
{
    int array_1[5]={2,5,6,8,0};
    int array_2[10000];

    int inter[]={0}; 
     int len=getIntersection2( array_1,5, array_2, 10000, inter);

    for(int i=0;i<len;i++)
        cout<<inter[i]<<endl;
}