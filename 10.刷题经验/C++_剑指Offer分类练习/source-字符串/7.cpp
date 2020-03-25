/*
字符串按照一定规则顺序重新排列
输入：”A,2.d?3!e4r87we79"，字母，数字，符号顺序
输出：“Ad.............."
*/
#include <iostream>
using namespace std;

#include <cstring>

//简单粗暴
void parseString1(char *pstr) 
{
	int  letterCount = 0, digitCount = 0;
	int i, index1=0, index2=0, index3=0;
	char *tmp = (char *)malloc(strlen(pstr));
	for (i=0; i<strlen(pstr); i++) 
    {
		/*统计字符串中字母，数字的个数*/
		if ((pstr[i]>='a' && pstr[i]<='z')||
			(pstr[i]>='A' && pstr[i]<='Z')) 
        {
			letterCount++;
		} 
        
        else if (pstr[i]>='0' && pstr[i]<='9') 
        {
			digitCount++;
		} 
	}

	for (i=0; i<strlen(pstr); i++) 
    {  /*通过一次循环扫描将字符串内容重新排列*/
		
        if ((pstr[i]>='a' && pstr[i]<='z')||
			(pstr[i]>='A' && pstr[i]<='Z')) 
        {
			tmp[index1++] = pstr[i];	/*保存字母字符*/
		}
        
         else if (pstr[i]>='0' && pstr[i]<='9')
        {
			tmp[letterCount + (index2++)] =  pstr[i];  /*保存数字字符*/
		}
        
         else 
        {
			tmp[letterCount + digitCount + (index3++)] =  pstr[i]; /*保存其他字符*/
		}
	}

	for (i=0; i<strlen(pstr); i++)
    {
		pstr[i] = tmp[i];		/*将临时缓冲区中的字符拷贝到源字符数组中*/
	}
}

//判断C是否是字母字符
int isalpha(char c) 
{
	if ((c>='a' && c<='z') ||
		(c>='A' && c<='Z')) 
    {
		return 1;
	} 
    
    else
    {
		return 0;
	}
}

//判断是否是数字字符
int isdigit(char c) 
{
	if (c>='0' && c<='9') 
    {
		return 1;
	}

	return 0;
}

//比较字符a ,b
int compare(char a,char b)
{   
    //a是字母，b是字母，返回0
    //a是字母，b不是字母，返回1
	if(isalpha(a))
	{
		if(isalpha(b))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}


    
	else if(isdigit(a))
	{   
        //a是数字，b是字母，返回-1
		if(isalpha(b))
		{
			return -1;
		}

        //都是数字，返回0 
		else if(isdigit(b))
		{
			return 0;
		}

        //a是数字，b是其他符号返回1
		else 
		{
			return 1;
		}

	}


	else
	{    
        //a是其他符号，b是数字或字母，返回-1
		if(isalpha(b) || isdigit(b))
		{
			return -1;
		}

        //a是其他符号，b是其他符号
		else 
		{
			return 0;
		}
	}
}

void swap(char *a, char *b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void parseString2(char* pstr)
{
	int i, changed = 0;
	int n = strlen(pstr);

	do 
	{	changed = 0;
		for(i=1;i<n;++i)
		{   
            //-1
			if( compare(pstr[i-1],pstr[i])<0 )
			{
				changed =1;
				swap(&pstr[i-1],&pstr[i]);
			}
		}
		--n;
	} while (changed);
}

int main()
{
	char str[]="a123bc^&de456fg**98s#";
    parseString2(str);
    printf("%s\n",str);
    getchar();
}