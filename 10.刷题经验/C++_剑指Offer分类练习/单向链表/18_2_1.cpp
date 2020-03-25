
// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。

#include <iostream>
using namespace std;

#include "ListNode.h"

void DeleteDuplication(ListNode** pHead)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;
    
    //1233445
    ListNode* pPreNode = nullptr;
    ListNode* pNode = *pHead;//1
    while(pNode != nullptr)
    {
        ListNode *pNext = pNode->next;//2
        bool needDelete = false;

        if(pNext != nullptr && pNext->value == pNode->value)
            needDelete = true;

        if(!needDelete)
        {
            pPreNode = pNode;//1
            pNode = pNode->next;//2
        }
        else
        {   //定义需要删除的节点
            int value = pNode->value;
            ListNode* pToBeDel = pNode;
           
           //删除当前节点
            while(pToBeDel != nullptr && pToBeDel->value == value)
            {
                pNext = pToBeDel->next;
               
                delete pToBeDel;
                pToBeDel = nullptr;

                pToBeDel = pNext;
            }
         
            
            if(pPreNode == nullptr)
                *pHead = pNext;
            else
                pPreNode->next = pNext;

          //将删除节点的下一个节点给pNode。继续循环下去
            pNode = pNext;
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
    DeleteDuplication(&pListHead);
    
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