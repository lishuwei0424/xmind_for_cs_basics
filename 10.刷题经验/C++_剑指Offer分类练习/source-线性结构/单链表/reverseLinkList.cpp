/*
反转单向链表
*/

#include "Link.h"

//定义多个辅助链表
 void reverseLinkList(LinkList *list)
 {
    LinkList p,q,r;
    p=*list;//指向头节点
    q=NULL;
    r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;//q随着p移动
        p=p->next;

        q->next=r;//第一次时候使第一个节点和第二个节点断开，第二次时候使第二个节点指向第一个节点实现反转
    }

    *list=q;
     
 }



 int main()
 {
     LinkList list;
     
     
     //创建包含10个元素的单链表并初始化它
     list=CreatLinkList(10);
     printLink(list);
     reverseLinkList(&list);
     printLink(list);

     return 0;
 }