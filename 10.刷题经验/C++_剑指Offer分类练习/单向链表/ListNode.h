#ifndef LIST_NODE
#define LIST_NODE

#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    ListNode* next;
    ListNode* random;//复杂链表增加一项
};

  
   ListNode* CreateListNode(int value)
   {
    ListNode* pNode = new ListNode();
    pNode->value= value;
    pNode->next= nullptr;

    return pNode;
   }

  void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
  {
    if(pCurrent == nullptr)
         return;

     pCurrent->next= pNext;
   }

     void PrintListNode(ListNode* pNode)
    { 
     if(pNode == nullptr)
         return;
    
     else
        cout<<pNode->value<<endl;
    }

   void DestroyNode(ListNode* pHead)
   {

    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
   }
    unsigned int GetListLength(ListNode* pHead)
   {
    unsigned int nLength = 0;
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        ++nLength;
        pNode = pNode->next;
    }

    return nLength;
   }

   //复杂链表的创建
   ListNode* CreatComplexNode(int val)
   {
       ListNode* pNode=new ListNode();
       pNode->value=val;
       pNode->next=NULL;
       pNode->random=NULL;

       return pNode;
   }
   
   void BuildNodes(ListNode* pNode,ListNode* pNext,ListNode* pRandom)
   {
       if(pNode!=NULL)
       {
           pNode->next=pNext;
           pNode->random=pRandom;
       }
   }
   
   void PrintComplexList(ListNode* phead)
   {
       ListNode* pNode=phead;
       while(pNode!=NULL)
       {
           cout<<pNode->value<<endl;
           if(pNode->random!=NULL)
            cout<<pNode->random->value<<endl;;

           pNode=pNode->next;
       }
   }

#endif