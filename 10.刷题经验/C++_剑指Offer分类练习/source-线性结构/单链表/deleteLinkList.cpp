/*
编程销毁一个单链表
*/

#include "Link.h"


 void deleteLinkList(LinkList *list)
 {
     LinkList p=*list;//*p指向第一个节点
     while(p!=NULL)
     {
         *list=p->next;//*list指向p的下一个节点
         free(p);

         p=*list;//×p再指向第一个节点
     }

     
     
 }



 int main()
 {
     LinkList list;
     
     
     //创建包含10个元素的单链表并初始化它
     list=CreatLinkList(5);
     printLink(list);

     deleteLinkList(&list);
     printLink(list);

     if (list == NULL) {
		printf( " This Linklist have been deleted\n");
	}

     return 0;
 }