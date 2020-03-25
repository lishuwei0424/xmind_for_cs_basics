/*
判断一个链表是不是循环链表;
不局限与指向第一个节点
*/

#include <iostream>
#include "malloc.h"

using namespace std;

typedef struct node
{
    int data;
    struct node *next;

}LNode,*LinkList;


LinkList CreatLinkList(int n)
{
    //建立长度为n的链表
    LinkList p,r,list=NULL;
    int e;
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);//获取链表节点元素

        p=(LinkList)malloc(sizeof(LNode));//分配一个新的链表节点
        p->data=e;
        p->next=NULL;

    if(list==NULL)
    {
        list=p;//list指向第一个节点，list是头指针
    }
    else
    {
        r->next=p;//将新节点链接到链表的尾部
    }
    r=p;//指针r始终指向链表的最后一个节点
    }

    return list;
    
}

LinkList CreatLoopLinkList(int n, int k)
{
	/*建立一个长度为n的链表*/
	LinkList p, r, q, list = NULL;
	int e;
	int i;
	for (i=1;i<=n;i++)
    {
		scanf("%d",&e);						/*获取链表结点中的数据元素*/
		p=(LinkList)malloc(sizeof(LNode));	/*分配一个新的链表结点*/
		p->data=e;
		p->next=NULL;
         if (list == NULL) 
         {
				list = p;			/*list指向第一个结点，list是头指针*/
		}
         else
        {
				r->next = p;		/*将新结点连接到链表的尾部*/
		}
		r = p;						/*指针r始终指向链表的最后一个结点*/
	}

	q = list;

	for (i=0 ; i<k-1; i++)
     {
		q = q->next;
	}
	r->next = q;

	return list;					/*返回链表的头指针*/
}

//定一个两个指针，快的一次走两步，慢的一次走一步，两者相遇肯定回环
int isLoopLinkList(LinkList list) 
{
	LinkList fast, slow;
	fast = list->next;
	slow = list;
	
	while (1)
     {
		if (fast == NULL || fast->next == NULL)
         {
			return 0;
		} 
        else if (fast == slow || fast->next == slow) 
        {
			return 1;
		}
         else
          {
			fast = fast->next->next;
			slow = slow->next;
		}
	}
}

int main()
 {
	LinkList list;
	printf("Create a 10 elems linklist without loop\n");
	list = CreatLinkList(10);
	printf("This linklist is %s\n", isLoopLinkList(list) == 1?"LoopLinkList":"NOT LoopLinkList");
	printf("Create a 10 elems loop linklist\n");
	list = CreatLoopLinkList(10,5);
	printf("This linklist is %s\n", isLoopLinkList(list) == 1?"LoopLinkList":"NOT LoopLinkList");
	getchar();
	getchar();

    return 0;
}
