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

//根据58_1的参考，先翻转字符串前面字符，再翻转后面的字符，最后翻转整体字符

char* LeftRotateString(char* pStr,int n)
{
    if(pStr!=NULL)
    {
        int leng=static_cast<int>(strlen(pStr));
        if(leng>0 && n>0 && n<leng)
        {
            char* pFirstStart=pStr;
            char* pFirstEnd=pStr+n-1;
            char* pSecondStart=pStr+n;
            char* pSecondEnd=pStr+leng-1;

            //翻转字符串前面n个字符
            Reverse(pFirstStart,pFirstEnd);

            //翻转字符串的后面字符
            Reverse(pSecondStart,pSecondEnd);

            //翻转整个字符
            Reverse(pFirstStart,pSecondEnd);
        }
    }

    return pStr;
}
int main()
{   

    char input[] = "abcdefg";
    char* result=LeftRotateString(input,2);

    cout<<result<<endl;

    return 0;

}