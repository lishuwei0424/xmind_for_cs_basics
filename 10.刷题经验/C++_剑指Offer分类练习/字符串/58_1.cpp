/*
// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。
*/

#include <iostream>
using namespace std;

#include <cstring>

//先整体翻转，再单个单词进行翻转
void Reverse(char *pBegin,char *pEnd)
{
    if(pBegin==NULL || pEnd==NULL)
        return;
    
    while(pBegin<pEnd)
    {
        char tmp=*pBegin;
        *pBegin=*pEnd;
        *pEnd=tmp;

        pBegin++;
        pEnd--;
    }
}

//翻转句子
char* ReverseSentence(char *pData)
{
    if(pData==NULL)
        return NULL;

    char *pBegin=pData;

    //找到字符转最后一个字符
    char *pEnd=pData;
    while(*pEnd !='\0')
        pEnd++;
    pEnd--;

    //翻转整个句子
    Reverse(pBegin,pEnd);

    //翻转句子中的单词
    pBegin=pEnd=pData;
    while(*pBegin !='\0')
    {
        if(*pBegin==' ')
        {
            pBegin++;
            pEnd++;
        }

        else if(*pEnd==' ' || *pEnd=='\0')
        {
            Reverse(pBegin,--pEnd);
            pBegin=++pEnd;//放在第二个单词上了
        }
        else
        {
            pEnd++;
        }
        
    }

    return pData;
}
int main()
{  
  char input[] = "I am a student.";;
  char* result=ReverseSentence(input);

  cout<<result<<endl;

    return 0;

}