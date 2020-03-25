#include <iostream>
#include <string>

using namespace std;

void getdup(int data[],int leng)
{  
   if(data==nullptr||leng<0)
        //如何创建检查？时间复杂度为n*n，效率较差
        return;
	
   
    int i,j;
    int k=0;
    int dup[]={0};
   for(i=0;i<leng;i++)
   {
      for(j=i+1;j<leng;j++)
      {
         if(data[i]==data[j])

             {
              
	        dup[k]=data[i];
                 k++;
           
             }     
      
    }

    }

    for(int h=0;h<k;h++)
    {
         cout<<dup[h]<<endl;
    }
   
   
}

int main()
{
   int data[]={6,2,3,0,2,5,3};
   getdup(data,sizeof(data)/sizeof(int));
   return 0;
}

