/*
循环链表，约瑟夫环问题
*/


#include <iostream>
#include "malloc.h"

using namespace std;

typedef struct node
{
    int id;//成员编号
    int key;//报数出去的那个
    struct node *next;

}LNode,*LoopLinkList;

//创建约瑟夫环
LoopLinkList CreatJosephRing(int n)
{
    LoopLinkList list,p,r;
    int e;
    int i;
    
    cout<<"get the first node"<<endl;
    scanf("%d",&e);//得到第一个元素的节点
    r=list=(LoopLinkList)malloc(sizeof(LNode));
    list->next=list;//指针指向自身
    list->key=e;//复制第一个节点的数据元素
    list->id=1;

    for(i=2;i<=n;i++)
    {
        //循环创建后续的n-1个节点
        cout<<"sencod to last node"<<endl;
        scanf("%d",&e);
        p=(LoopLinkList)malloc(sizeof(LNode));
        p->key=e;

        p->id=e;
        p->next=list;//指向链表的第一个节点
        r->next=p;//将新节点连入循环链表
        r=r->next;
    }

    return list;
}


int main()
{
    LoopLinkList list=NULL, p_front=NULL,p=NULL;
    int n,m,i;
    cout<<"the number of people in Joseph Ring"<<endl;
    scanf("%d",&n);

   // cout<<"remove the people "<<endl;
    list=CreatJosephRing(n);
    cout<<"the first Maximum Number M"<<endl;
    scanf("%d",&m);

    cout<<"the order of leave Joseph Ring"<<endl;

    p_front=p=list;
    while(p_front->next!=list)
    {
        p_front=p_front->next;//p_front指向p的前驱节点
    }

    while(p!=p->next)
    {
        for(i=0;i<m-1;i++)
        {
            p=p->next;
            p_front=p_front->next;
        }

        cout<<"come out"<<p->id<<endl;

        //留下下一次出去的上限
        m=p->key;
        //把p空出来
        p_front->next=p->next;
        free(p);

        //永远保持前后关系
        p=p_front->next;
    }

    //最后一个出来把
    cout<<"last come out"<<p->id<<endl;
    free(p);
    list=p_front=p=NULL;

    return 0;
}