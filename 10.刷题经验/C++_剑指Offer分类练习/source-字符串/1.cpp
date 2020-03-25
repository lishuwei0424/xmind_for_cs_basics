
/*
实现字符串的倒置
输入： I am a student
输出： tneduts a ma I
*/

#include <iostream>
using namespace std;

#include <cstring>

int reverseStr(char *str,int begin,int end);

int reverseWords(char *str)
{
    int wordBegin=0, wordEnd=0, len=0;
    if(str==NULL || *str=='\0')
    {
        return 0;
    }

    len=strlen(str);
    reverseStr(str,0,len-1);//先倒置整个句子

    while(wordEnd<len)
    {
        if(str[wordEnd]!=' ')
        {
            wordBegin=wordEnd;//指向单词的第一个字符
            while(str[wordEnd]!=' ' && str[wordEnd]!='\0' && wordEnd<len)
            {
                wordEnd++;
            }

            //找到了第一个单词的结束符，指向第一个单词的最后一个字符
            wordEnd--;
            reverseStr(str,wordBegin,wordEnd);//反转单词
        }
        wordEnd++;
    }
    return 1;
}

int reverseStr(char *str,int begin,int end)
{
    char tmp;
    if(str==NULL)
    {
        return 0;
    }

    if(begin<end)
    {
        tmp=str[begin];
        str[begin]=str[end];
        str[end]=tmp;

        //递归调用
        reverseStr(str,begin+1,end-1);
    }
    return 1;
}

int main()
{
    char str[20]=" I am a student";
     printf("%s\n",str);
    reverseWords(str);
    printf("%s\n",str);
        getchar();
}