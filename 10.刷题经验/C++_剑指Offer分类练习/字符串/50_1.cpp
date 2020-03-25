/*
// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

*/

#include <iostream>
using namespace std;

#include <cstring>

 //创建一个哈系表，key是每个单词，value是出现的次数
 char FirstNotRepeatingChar(const char* pString)
 {
     if(pString==NULL)
        return '\0';

     const int tableSize=256;
     unsigned int hashTable[tableSize];

     for(unsigned int i=0;i<tableSize;++i)
        hashTable[i]=0;//value都初始化0次

    const char* pHashKey=pString;
    while(*(pHashKey)!='\0')
        hashTable[*(pHashKey++)]++;

    pHashKey=pString;
    while(*pHashKey!='\0')
    {
        if(hashTable[*pHashKey]==1)
            return *pHashKey;

        pHashKey++;
    }

    return '\0';
 }


int main()
{  
  const  char* pString= "google";

   char result=FirstNotRepeatingChar(pString);
  cout<<result<<endl;

    return 0;

}