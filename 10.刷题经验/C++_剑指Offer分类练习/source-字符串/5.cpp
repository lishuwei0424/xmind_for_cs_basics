/*
在两个字符串中查找最大公共子串
输入：A="abcdefg",B="cdeab"
输出：“cde"
*/
#include <iostream>
using namespace std;

#include <cstring>

char *getCommonString(char *str1, char *str2)
{
    char *longStr, *shortStr, *subStr;
    int i,j;

    if(str1==NULL || str2==NULL)
        return NULL;
    
    //找到最长字串，分别赋值
    if(strlen(str1)<= strlen(str2))
    {
        shortStr=str1;
        longStr=str2;
    }
    else
    {
        shortStr=str2;
        longStr=str1;
    }

    //利用strstr函数判断
    if(strstr(longStr,shortStr)!=NULL)
        return shortStr;
    
    //申请内存空间以存放子串
    subStr=(char*)malloc(strlen(shortStr));

    //从最短字串的最长字串开始查找
   for(i=strlen(shortStr)-1;i>0;i--)//外层循环控制字串的长度
   {
         for(j=0;j<=strlen(shortStr)-i;j++)//内层循环获得程度为i的子串  j<=5-4=1
         {
             memcpy(subStr,&shortStr[j],i);//拷贝子串，长度为i
             subStr[i]='\0';//添加字符串结束标志

            //0-i 1-i+1, 2-i+2直到结束取字串进行判断
            if(strstr(longStr,subStr)!=NULL)
                return subStr;
         }
   }

   free(subStr);
   return NULL;
}


int main()
{
    char str1[20] = "abcdefg";
    char str2[20]="defga";
    printf("The string is %s\n",str1);
    printf("The string is %s\n",str2);
    char *sub;
    sub=getCommonString(str1, str2);

     printf("The getCommonString is %s\n",sub);
    getchar();
}
