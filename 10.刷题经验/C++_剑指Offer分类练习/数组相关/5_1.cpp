#include <iostream>
#include <string>
using namespace std;

void insertstring(char intput[],int leng,char output[],int newleng)
{
    if(intput==nullptr || leng<0)
        return ;
 
   
    int blank=0;//空格长度
    int orileng=0;//原始长度
    int i=0;
    while(intput[i]!='\0')
    {   
        if(intput[i]==' ')
        {    
             blank++; 
        }

        //空格也算长度，不能else 
       // else
      //  {    
        //    orileng++;  
       // }
        
       orileng++;  
       i++;   
    }
     
     newleng=orileng+blank*2;//因为之前的空格算一个
    if(newleng<leng)
        return;
    
    //替换问题，设置前后不同索引变量，避免用一个不知所措，从后往前遍历
     
    //为了下面传出newleng的值，需要设置一个变量，保留newleng的长度
    int newindex=newleng;
    int oriindex=orileng;
    int add=0;
     for(int k=0;k<orileng;k++)
        cout<<"intput"<<k<<" "<<intput[k]<<endl;
  
    while( newindex>=0 ||oriindex==0)
    {   
        
         if(intput[oriindex]!=' ')
         {  
             cout<<intput[oriindex]<<endl;//第一次空的
            output[newindex+add]=intput[oriindex];

         }
         
         else
         {
             output[newindex--]='0';
             output[newindex--]='2';
             output[newindex--]='%';
             add++;
         }
          oriindex--; 
          newindex--;

         cout<<"oriindex"<<oriindex<<endl;
         cout<<"ssss"<<intput[oriindex]<<endl;
    }
    
   
    for(int k=0;k<newleng;k++)
        cout<<"output"<<k<<" "<<output[k]<<endl;
}


int main()
{
    char intput[]="We are happy";
    char output[]={};
    int newleng=2;
    
   insertstring(intput,sizeof(intput)/sizeof(char)-1,output,newleng);
    cout<<sizeof(intput)/sizeof(char)<<endl;//13
    cout<<newleng;//2??
    //for(int k=0;k< newleng;k++)
      //  cout<<"result"<<output[k]<<endl;


    return 0;


}