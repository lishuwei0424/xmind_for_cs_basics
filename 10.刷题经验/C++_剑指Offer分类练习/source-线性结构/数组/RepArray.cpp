/*
重新排列数组使得数组左边为奇数，右边为偶数
考虑原来数组的次序
原来奇数怎么排列的，后面结果还是谁在谁的前面
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

//方法1,开辟一个新的数组，保存原来的奇数在前面，偶数在后面
int reArrange(int array[],int len)
{
    int i,j;
    if(len<1 )
        return 0;

   int *tmp;
   tmp=(int*)malloc(sizeof(int)*len);
   if(tmp==NULL)
    return 0;//堆内存分配失败
   
   //数组中的奇数拷贝到前半部分
   for(i=0,j=0;i<len;i++)
   {
       if(!isEvenNum(array[i]))
       {
           tmp[j]=array[i];
           j++;
       }
   }

     //数组中的偶数拷贝到后半部分
   for(i=0;i<len;i++)
   {
       if(isEvenNum(array[i]))
       {
           tmp[j]=array[i];
           j++;
       }
   }

   //拷贝数组拷贝到原数组
   for(i=0;i<len;i++)
   {
       array[i]=tmp[i];
   }

   free(tmp);

   return 1;
}


//方法2,不开辟空间
//找到第一个偶数i和第一个偶数后面的第一个奇数j，将第一个奇数移动到第一个偶数的位置，中间的元算向后移动一个位置
//如此循环下去，i仍然是数组中的第一个偶数，而i之后的元素已经不再有奇数了，奇数都已经移动到i的前面了
int reArrange2(int array[],int len)
{
    int i,j,k;
    int tmp;
    if(len<1 )
        return 0;

   //找到数组中的第一个偶数
   for(i=0;i<len;i++)
   {
       if(isEvenNum(array[i]))
       {
           break;
       }
   }

   for(j=i+1;j<len;j++)
   {
       if(!isEvenNum(array[j]))
       {
           tmp=array[j];//第一个奇数，先存起来
            
            for(k=j-1;k>=i;k--)
            {
                array[k+1]=array[k];//数据后移动一个单位，将array[i]空出来
            }

            array[i]=tmp;
            i=i+1;

       }
   }

   return 1;
}

int main()
{
    int array[10]={1,2,3,4,5,6,7,8,9,10};
   
    reArrange2( array,10);

    for(int i=0;i<10;i++)
        cout<<array[i]<<endl;
}