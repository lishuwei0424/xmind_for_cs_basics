/*
// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
*/

#include <iostream>
using namespace std;

//将第一个数，和后面的数分成两组，固定第一个，依次和后面的进行交换
void Permutation(char* pStr,char* pBegin);

void Permutation(char* pStr)
{
    if(pStr==NULL)
        return;

    Permutation(pStr,pStr);
}

 void Permutation(char* pStr,char* pBegin)
 {  
     //指向当前我们执行排列操作的字符串的第一个字符
     if(*pBegin=='\0')
        printf("%s\n",pStr);

    else
    {
        for(char* pCh=pBegin;*pCh!='\0';++pCh)
        {
            char tmp=*pCh;
            *pCh=*pBegin;
            *pBegin=tmp;

            Permutation(pStr,pBegin+1);
            

            tmp=*pCh;
            *pCh=*pBegin;
            *pBegin=tmp;

        }
    }
    
    
      
 }
int main()
{  
   char string4[] = "abc";
   Permutation(string4);

    return 0;

}