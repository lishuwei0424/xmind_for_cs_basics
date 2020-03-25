#include "ListNode.h"
#include <iostream>
using namespace std;

void DeleteDup(ListNode* root)
{
     if(root==NULL)
        return;

    
    ListNode* phead=root;
    ListNode* pPreNode=NULL;
   
    while(phead->next!=NULL)
    {   
   
        bool needDelete=false;
       
         ListNode* pNext=NULL;
         pNext=phead->next;
        
        //仅仅已知删除3或者4
        if( phead->value==3 || phead->value==4 )
        {  
            needDelete=true;
        }
       
       if(!needDelete)
        {
            pPreNode=phead;
            phead=phead->next; 
          
        }

        if(phead->value==3 || phead->value==4 ) 
        { 
          cout<<"phead=="<<phead->value<<endl;

          ListNode* nextp =phead->next;
          phead->value = nextp->value;
          phead->next = nextp->next;
         
        
          delete nextp;
          nextp = nullptr;
        
          phead=pPreNode->next;
          //因为是单向链表，没法返回去将phead=2,所以无法在此进入if
          //因此需再定义一个链表，是他指向需删除节点的前一个节点，删除后
          //把前一个节点给他，就相当于双向链表了
         
        }
        
     
    }
  
}

void PrintfOri(ListNode* pListHead)
{
    printf("The original list is: \n");

    ListNode* phead=pListHead;
    while(phead!=NULL)
    {
        PrintListNode(phead);
        phead=phead->next;
    }
    
}

void PrintfDel(ListNode* pListHead)
{
     DeleteDup(pListHead);
    
    printf("The result list is: \n");
    ListNode* phead=pListHead;
    while(phead!=NULL)
    {
        PrintListNode(phead);
        phead=phead->next;
    }
 
}


int main(int argc, char* argv[])
{   
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
     
     PrintfOri(pNode1);
     PrintfDel(pNode1);

    return 0;
}
