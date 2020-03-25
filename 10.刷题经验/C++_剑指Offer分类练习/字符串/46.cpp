/*
// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。
*/

#include <iostream>
using namespace std;

#include <cstring>

 int GetTranslationCount(const string& numberInString);
//主要在11-25之间会有两种翻译
//数字转字符串
int GetTranslationCount(int number)
{
    if(number<0)
        return 0;

    string numberInString=to_string(number);

    return GetTranslationCount(numberInString);
}

 int GetTranslationCount(const string& numberInString)
 {
     int leng=numberInString.length();
     int* counts=new int[leng];

     int count=0;

     for(int i=leng-1;i>=0;--i)
     {
         count=0;
         if(i<leng-1)
            count=counts[i+1];
        else
            count=1;

        if(i<leng-1)
        {
            int d1=numberInString[i]-'0';
            int d2=numberInString[i+1]-'0';

            int converted=d1*10+d2;
            if(converted>=10 && converted<=25)
            {
                if(i<leng-2)
                    count+=counts[i+2];
                else
                    count+=1;
                
            }
        }

        counts[i]=count;
        
     }

     count=counts[0];
     delete[] counts;

     return count;
 }
int main()
{  
  int number = 126;
  int result=GetTranslationCount(number);

  cout<<result<<endl;

    return 0;

}