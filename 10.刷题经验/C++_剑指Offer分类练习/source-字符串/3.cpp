/*
从字符串指定位置删除指定长度的字符串
输入：abcdefg pose=3 len=3
输出：abfg
*/

#include <iostream>
using namespace std;

#include <cstring>

int delChars(char *str,int pos, int len)
{
    int strLen,i,j;
    if(str==NULL)
        return 0;
    strLen=strlen(str);

    if(len<0 || pos<=0 || pos+len-1>strLen)
        return 0;

    i=pos-1;//删除的字符串的第一个单词
    j=pos+len-1;//删除字符串的最后一个单词下一个位置
    while(str[j]!='\0' && j<strLen)
    {
        str[i]=str[j];//f到c的位置，g到d的位置
        i++;
        j++;
    }

    //最后要添加字符串结束的标志
    str[strLen-len]='\0';
    return 1;
}

int main()
{
    char str[20] = "abcdefg";
    printf("The string is %s\n",str);
    delChars(str,3,3);
    printf("The string after delChars is %s\n",str);
    getchar();
}