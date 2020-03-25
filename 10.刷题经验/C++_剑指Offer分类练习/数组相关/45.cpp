
// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>

//比较两个数，不是大小，而是m和n哪一个应该放在前面
//mn<nm则 m放前面，反之

//考虑可能出现大数问题，因此将数字转成字符串处理

// int型整数用十进制表示最多只有10位
const int g_MaxNumberLeng=10;

char* g_StrCombine1=new char[g_MaxNumberLeng*2+1];
char* g_StrCombine2=new char[g_MaxNumberLeng*2+1];
int compare(const void* strNumber1, const void* strNumber2);

void PrintMinNumber(int* numbers, int leng)
{
    if(numbers==NULL || leng<=0)
        return;
    
    char** strNumbers=(char**)(new int[leng]);
    //数字转字符串
    for(int i=0;i<leng;++i)
    {
        strNumbers[i]=new char[g_MaxNumberLeng+1];
        sprintf(strNumbers[i],"%d",numbers[i]);
    }

    //调用库函数进行排序
    qsort(strNumbers,leng,sizeof(char*),compare);

    for(int i=0;i<leng;++i)
        printf("%s",strNumbers[i]);
    printf("\n");

    for(int i=0;i<leng;++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}

// 如果[strNumber1][strNumber2] > [strNumber2][strNumber1], 返回值大于0
// 如果[strNumber1][strNumber2] = [strNumber2][strNumber1], 返回值等于0
// 如果[strNumber1][strNumber2] < [strNumber2][strNumber1], 返回值小于0
int compare(const void* strNumber1, const void* strNumber2)
{
    // [strNumber1][strNumber2]
    strcpy(g_StrCombine1, *(const char**)strNumber1);
    strcat(g_StrCombine1, *(const char**)strNumber2);
 
    // [strNumber2][strNumber1]
    strcpy(g_StrCombine2, *(const char**)strNumber2);
    strcat(g_StrCombine2, *(const char**)strNumber1);
 
    return strcmp(g_StrCombine1, g_StrCombine2);
}

int main(int argc, char* argv[])
{   
  int numbers[] = {3, 32, 321};
  PrintMinNumber(numbers,sizeof(numbers)/sizeof(int));
     

    return 0;
}

