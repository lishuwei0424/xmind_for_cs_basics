/*
找出一个单链表中倒数第k个元素，并返回该节点的指针
*/

#include "Link.h"

//定义两个指针fast和slow，fast先走k部，然后slow从0和fast一起往后走
//当fast到达结束时候，slow到达倒数第k个节点
 LinkList findKToLastElem(LinkList list,int k)
 {
     LinkList slow,fast;
     int i;

     fast=list;
     for(i=1;i<k && fast!=NULL;i++)
     {
         fast=fast->next;
     }

     if(i==k && fast!=NULL)
     {
         slow=list;

     }
     else
     {
         return NULL;//链表长度小于K
     }

     while(fast->next!=NULL)
     {
         fast=fast->next;
         slow=slow->next;
     }

     return slow;
     
     
 }



 int main()
 {
     LinkList list=NULL,list3;
     list=CreatLinkList(5);
 
     list3=findKToLastElem( list,3);

     cout<<list3->data<<endl;

     return 0;
 }