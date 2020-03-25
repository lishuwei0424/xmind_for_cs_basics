#include <iostream>
#include <string>
using namespace std;

char* insertstring(char* input,int leng,char* output)
{
    if(input==nullptr || leng<0)
        return NULL;
    //统计有几个空格，每个空格给三个单位长度
    int spacecount=0;
    while(*input!='\0')
    {   
        if(*input!=' ')
        {  
            output=input;
            spacecount++;
           cout<<*output<<endl;
           cout<<spacecount<<endl;
        }
         
        else
        {    
             cout<<*output<<endl;
            *(output+3)='0';
            *(output+2)='2';
            *(output+1)='%';

        }
           
        input++;
       
    }
    
    return output;
    
}


int main()
{
    char* input="We are happy.";
    char* output=new char[20];
    string data;
    data=input;
    int leng=data.length();
    char* result=insertstring(input,leng,output);
    cout<<"output"<<result<<endl;
    delete []output;

    return 0;


}