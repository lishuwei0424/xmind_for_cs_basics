#include <iostream>
using namespace std;

#include "ListNode.h"

ListNode* HeBingLiangList(ListNode* root1,ListNode* root2, ListNode* pHead)
{
    if(root1==NULL && root2==NULL)
        return NULL;

    if(root1!=NULL && root2==NULL)
       return root1;

    //ListNode* p1=root1;//递归函数当然在这里不能在初始化了
  //  ListNode* p2=root2;
  //HeBingLiangList(root1,root2,pHead);

     ListNode* pMergedHead = NULL;
         
         if(root1==NULL && root2!=NULL)
        {
            pHead=root2;
          cout<<"2 "<<pHead->value<<endl; 
        }

        if(root1->value<root2->value)
        {
           pHead=root1;
          cout<<"0 "<<pHead->value<<endl;
           root1=root1->next;
          // if(root1==NULL)
               // continue;//没有直接跳出if的
              // root1=pHead;
          // else
               // HeBingLiangList(root1,root2,pHead);//傻逼呀，写的递归为啥没有返回值

                 pMergedHead=HeBingLiangList(root1,root2,pHead);//傻逼呀，写的递归为啥没有返回值
           
        }
       
        if(root1->value > root2->value )
        {
            pHead=root2;
           cout<<"1 "<<pHead->value<<endl;
           root2=root2->next;

           pMergedHead= HeBingLiangList(root1,root2,pHead);
        }


    return  pMergedHead;
}

ListNode* List1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(3);
    ListNode* pNode3 = CreateListNode(5);
    ListNode* pNode4 = CreateListNode(7);
    
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);

    return pNode1;
}

ListNode* List2()
{
   
    ListNode* pd1 = CreateListNode(2);
    ListNode* pd2 = CreateListNode(4);
    ListNode* pd3 = CreateListNode(6);
    ListNode* pd4 = CreateListNode(8);

    ConnectListNodes(pd1, pd2);
    ConnectListNodes(pd2, pd3);
    ConnectListNodes(pd3, pd4);

    return pd1;
}

int main(int argc, char* argv[])
{
    
    ListNode* pNode1=List1();
    ListNode* pd1=List2();
    
        ListNode* pH=NULL;
   ListNode* pHead=HeBingLiangList(pNode1,pd1,pH);
   
    printf("The HeBing list is: \n");
    
    while(pHead!=NULL)
    {
        PrintListNode(pHead);
        pHead=pHead->next; 
    }
   

    return 0;
}
