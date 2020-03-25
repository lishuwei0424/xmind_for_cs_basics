/*
非空单链表list, 每个节点中存放一个整型数据。
指针q指向链表中的某一个节点，编写函数，删除q指向的节点
*/

#include "Link.h"

//删除一个节点，必须获得这个节点的前驱节点，令他指向该节点的下一个节点就好
 void deLink(LinkList *list, LinkList q)
 {
     LinkList r;

     //如果q指向的节点为第一个节点，则需要修改list的值
     if(q==*list)
     {
         *list=q->next;
         free(q);
     }

     else
     {
         r=*list;
         //通过循环找到q所指节点的前驱节点
         while((r->next !=q) && (r->next !=NULL))
         {
             r=r->next;
         }

         //找到r就是q的前驱节点
         if(r->next !=NULL)
         {
             r->next=q->next;
             free(q);
         }
     }
     
 }



 int main()
 {
     LinkList list,q;
     int i;
     
     //创建包含10个元素的单链表并初始化它
     q=list=CreatLinkList(10);
     deLink(&list,q);
     printLink(list);

     q=list;
     for(i=0;i<4;i++)
     {
         q=q->next;//指针q指向链表中的第5个元素
     }
    
     deLink(&list,q);
     printLink(list);

     return 0;
 }