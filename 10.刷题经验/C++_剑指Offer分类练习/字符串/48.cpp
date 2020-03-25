/*
// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。
*/

#include <iostream>
using namespace std;

#include <cstring>

 //暴力法，就是遍历它的子字符串，看看子字符串是否包含重复的
 bool hasDuplication(const std::string& str, int position[]);

 int longestSub(const std::string& str)
 {
     int longest=0;
     int* position=new int[26];
     for(int start=0;start<str.length();++start)
     {
         for(int end=start;end<str.length();++end)
         {
             int count=end-start+1;
             //将字符串str从start开始截取count个字符组成子字符串
             const std::string& substring=str.substr(start,count);
             if(!hasDuplication(substring,position))
             {
                   if(count>longest)
                        longest=count;

             }
             else
             
                 break;
             
             
         }
     }

     delete[] position;
     return longest;

 }

 bool hasDuplication(const std::string& str, int position[])
 {   
     //每个字符上次出现在字符串中的下标
     for(int i=0;i<26;++i)
        position[i]=-1;

    for(int i=0;i<str.length();++i)
    {
        int indexInPosition=str[i]-'a';
       if(position[indexInPosition]>=0)
                     return true;

        position[indexInPosition]=indexInPosition;

    }

    return false;
     

    
 }


int main()
{  
  const std::string input = "acfrarabc";
   int result=longestSub(input);
  cout<<result<<endl;

    return 0;

}