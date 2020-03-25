#include <iostream>
using namespace std;

bool find(int data[][4],int i,int j,int expected)
{
  if(data==nullptr||i<0||j<0)
	return false;

   
  
    
   if(data[i][j]<expected||data[0][0]>expected)
        return false;
   //最后一行
   /*
    else if(data[i][0]<expected)
       {  
         for(;i>=0;i--)
         {
          for(int k=0;k<=j;k++)
          {
           
            if(data[i][k]==expected)
               return true;
            if(data[i][j]<expected)
               return false;

          }
         }
            
       }

    //第一列
     else if(data[i][0]>expected)
       {    
             
          for( ;i>=0; i--)
          {
             for(int k=0;k<=j;k++)
            {
            
            if(data[i][k]==expected)
               return true;
             
            if(data[0][0]>expected)
               return false;
            }
          }
            
       }*/
    if(data[i][0]==expected)
        return true;
    
//代替上面注释的两行
    else 
       {    
             
          for( ;i>=0; i--)
          {
             for(int k=0;k<=j;k++)
            {
            
            if(data[i][k]==expected)
               return true;
            }
          }
            
       }
     


  return false;
}

int main()
{  
   int n=3;
   int m=4;
   int exp=13;
   int data[3][4] ={ {1,2,3,4} , {5,6,7,8} , {9,10,11,12} };
  
  bool result=find(data,n-1,m-1,exp);
  cout<<"result"<<result<<endl;
 
 return 0;

    
}
          
