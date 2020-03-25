/*
向顺序表中的第i个位置插入元素
*/


#include "stdio.h"
#include "malloc.h"
#define MAXSIZE 10
#define LISTINCREMENT 10

//动态顺序表
typedef struct{
	int *elem;
	int length;
	int listsize; //顺序表的存储空间，初始大小为MAXSIZE
	int incrementsize;//顺序表空间不足时候追加的空间量
} Sqlist;

//初始化
int initSqlist(Sqlist *L)
{	
    L->elem=(int *)malloc(MAXSIZE*sizeof(int));
    if(L->elem == NULL) return 0;		   /*内存分配失败，返回false*/
    L->length=0;						   /*最初顺序表的长度为0*/
	L->listsize= MAXSIZE;				   /*当前分配的数组容量*/
	L-> incrementsize = LISTINCREMENT;	   /*约定的增补空间大小*/
	return 1;						       /*初始化成功*，返回ture*/
}

int InsertElem(Sqlist *L,int i,int item)   /* InsertElem 函数实现*/
{
    int *base,* insertPtr,*p;
	if (i<1||i>L->length+1)
     {
		return 0;						   /*非法插入*/
	}


    if (L->length>=L->listsize) 
    {
        base=(int*)realloc(L->elem,(L->listsize+10)*sizeof(int));
										  /*重新追加空间*/
        if(base == NULL) return 0;		  /*内存分配失败*/
        L->elem = base;					  /*更新内存基地址*/
		L->listsize = L->listsize + L-> incrementsize;	
		/*存储空间增大L-> incrementsize个存储单元*/
    }

    insertPtr = &(L->elem[i-1]); 		 /*insertPtr 为插入位置*/

    for(p=&(L->elem[L->length-1]);p>= insertPtr;p--)
     {
		 *(p+1) = *p;				    /*将i-1以后的元素顺序后移一个元素的位置*/
	} 

    
    * insertPtr = item;					/*在第i个位置上插入元素item */
	L->length++;						/*表长加1*/
	return 1;
}


int main()							 	 /*测试函数*/
{
	Sqlist l;							 /* 定义一个顺序表l */
	int i;
	initSqlist(&l);						/* 初始化该顺序表 */
	for(i=0;i<15;i++) 
    {
		InsertElem(&l,i+1,i+1);			 /* 向顺序表中插入1…15 */
	}

	printf("\nThe content of the list is\n");
	for(i=0;i<l.length;i++) {
        printf("%d ",l.elem[i]);		/*打印出顺序表中的内容*/
	}

	/*打印出顺序表的长度*/
	printf("\nThe length of the Sqlist is %d\n",l.length);
	/*打印出顺序表的当前容量*/
	printf("The ListSize of the Sqlist is %d\n",l.listsize);
	getchar();

    return 0;
}