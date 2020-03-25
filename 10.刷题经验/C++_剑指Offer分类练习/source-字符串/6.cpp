/*
删除字符串中指定的所有字符串
输入：”this is a test"      "tes"
输出：“hi i a"
*/
#include <iostream>
using namespace std;

#include <cstring>


void removeChars(char str[], const char remove[]) {
	int i, src=0, dst=0;
	int removeCharsArray[256];

	for (i = 0; i<256; i++) 
    {
		removeCharsArray[i] = 0;     /*初始化数组removeCharsArray，全部赋值为0*/
	}
   
   //remove[i]自动转换成ASCII
	for (i=0; remove[i]!='\0'; i++) 
    {
		removeCharsArray[remove[i]] = 1;  /*构造removeCharsArray数组*/
	}
   
	do
    {
		if (removeCharsArray[str[src]] == 0) 
        {
			/*str[src]需要保留，不删除*/
			str[dst] = str[src];//hi i 
			dst++;
		}
		src++;
	} while(str[src] != '\0');
	str[dst] = '\0';
}

int main() 
{
	char str[] = "this is a test";
	char remove[] = "test";

	removeChars(str,remove);

	printf("%s\n",str);
	getchar();
}