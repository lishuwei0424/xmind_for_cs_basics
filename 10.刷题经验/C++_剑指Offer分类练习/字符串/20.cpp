/*
// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
*/

#include <iostream>
using namespace std;

bool scanUnsignedInter(const char** str);
bool scanInteger(const char** str);
//A[.[B][e|E C]]或者 .B[e|E C]
bool isNumeric(const char* str)
{
    if(str==NULL)
        return false;

    //B是一个无符号整数
    bool numeric=scanInteger(&str);

     // 如果出现'.'，接下来是数字的小数部分
    if(*str == '.')
    {
        ++str;

        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
        numeric = scanUnsignedInter(&str) || numeric;
    }

    // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
    if(*str == 'e' || *str == 'E')
    {
        ++str;

        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0';
}

//扫描可能以表示正负的‘+’或者‘-’为起点的0-9的数位，带正负号的整数
//用来匹配A或C
bool scanInteger(const char** str)
{
    if(**str=='+' || **str=='-')
        ++(*str);

    return scanUnsignedInter(str);
}

//扫描字符串中0-9的位数，匹配B
bool scanUnsignedInter(const char** str)
{
   const char* before=*str;
   while(**str!='\0' && **str>='0' && **str<='9')
        ++(*str);

    //当str中存在若干0-9的数字，返回true
    return *str>before;
}
int main()
{  
  const char* str="221e45";
   bool result=isNumeric(str);

    cout<<result<<endl;

    return 0;

}