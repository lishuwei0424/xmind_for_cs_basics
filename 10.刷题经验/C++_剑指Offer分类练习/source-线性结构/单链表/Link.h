#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList(int n)
{
    LinkList p,r,list=NULL;
    int e;
    int i;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&e);//获取链表节点元素
        p=(LinkList)malloc(sizeof(LNode));//分配一个新节点
        p->data=e;
        p->next=NULL;
    
    if(list==NULL)
    {
        list=p;//list指向第一个节点，list是头指针
    }
    else
    {
        r->next=p;//将新节点链接到链表尾部
    }

    r=p;//指针r始终指向链表的最后一个节点

    }

    return list;//返回链表头节点
    
}

 void printLink(LinkList list)
 {
     while(list!=NULL)
     {
         cout<<list->data<<endl;
         list=list->next;
     }
 }