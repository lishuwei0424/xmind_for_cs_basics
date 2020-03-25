/*
给定一个长度为n的数组，其中每个元素的取值范围为1-N.
判断数组中是否有重复元素
*/

#include <iostream>
using namespace std;

//巧妙的思想，满足上述条件，则所有元素的和为 n*(n+1)/2
//反之，不满足上述条件，则有重复元素
int haveRepeatElem(int data[],int n)
{
  int i,sum=0;
  for(i=0;i<n;i++)
    sum+=data[i];
  
  if(sum != (n*(n+1)/2))
    return 1;//存在重复元素返回1
   else
   {
       return 0;
   }
   
}


int main()
{
    int array[10]={0,0,3,4,5,6,7,8,9,10};
   
    int result=haveRepeatElem( array,10);
    cout<<"result "<<result<<endl;

    return 0;
}