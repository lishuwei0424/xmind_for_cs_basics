/*
实现两个有序链表合并成一个链表，返回合并链表的头指针
要求合并后的链表依然按值有序，并且不能额外开辟空间
*/

#include "Link.h"

//定义三个额外指针，和一个链表list3,r指向合并后list3的尾部
//p1指向list1的和p2指向list2的值比较
 LinkList MergeList(LinkList list1,LinkList list2)
 {
     LinkList list3;
     LinkList p1=list1,p2=list2;
     LinkList r;

     //找到list3的起始位置
     if(list1->data <= list2->data)
     {
         list3=list1;//×list1的第一个元素值最小，list3指向它
         r=list1;//指针r指向list1的第一个元素
         p1=list1->next;//p1指向list1的第二个元素

     }
     else
     {
         list3=list2;
         r=list2;
         p2=list2->next;
     }

     //开始比较之后的元素
     while(p1!=NULL && p2!=NULL)
     {
         if(p1->data <= p2->data)
         {
             r->next=p1;//当前p1指向的节点链接到r所指向的节点的后面
            
             r=p1;//指针后移动
              
             p1=p1->next;
         }

         else
         {
             r->next=p2;
             
             r=p2;
           
             p2=p2->next;
         }
         
     }

     //需要把剩余的不到NULL的list1或者list2继续链接到list3后面
     r->next=p1?p1:p2;
     

     return list3;
     
 }



 int main()
 {
     LinkList list1=NULL,list2=NULL,list3;
     list1=CreatLinkList(3);
     list2=CreatLinkList(3);
     list3=MergeList( list1,list2);

     //以上代码输出有问题
     printLink(list3);

     return 0;
 }