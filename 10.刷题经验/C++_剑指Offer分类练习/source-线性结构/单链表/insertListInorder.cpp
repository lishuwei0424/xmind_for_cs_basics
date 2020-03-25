/*
编程实现一个按值排序（递增）的整型单链表中插入一个节点
要求插入后的链表仍然按值排序
*/

#include "Link.h"

//找到插入节点的位置pos，并使指针r指向第pos-1个节点
//然后再将新的节点插入r指向节点的后面
 void insertListInorder(LinkList *list, int e)
 {
     LinkList p,q,r;

     //指向头节点
     q=*list;
       
     p=(LinkList)malloc(sizeof(LNode));//生成一个新节点，由p指向它
     p->data=e;//向该节点的数据阈赋值

     //边界判断
     //将p指向的新节点插入链表的第一个位置
     if(*list==NULL || e<(*list)->data)
     {
         p->next =*list;
         *list=p;
             
     }
   
     //循环找到插入节点的位置
     else if(e>(*list)->data)

     {
          
         while(q!=NULL && e>=q->data)
         {
             r=q;//r指向q的前驱节点
             q=q->next;
             
         }

         //插入新节点
         p->next=q;
         r->next=p;
     }
        
 }



 int main()
 {
     LinkList list=NULL;
     list=CreatLinkList(5);
     printLink(list);

     insertListInorder(&list,3);
  
     printLink(list);

     return 0;
 }