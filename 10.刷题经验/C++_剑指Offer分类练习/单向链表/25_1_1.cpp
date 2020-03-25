

// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

#include <cstdio>
#include "ListNode.h"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;

    ListNode* pMergedHead = nullptr;

    if(pHead1->value< pHead2->value)
    {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);//下一个节点跟上
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }

    return pMergedHead;//利用这样的返回
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
    
    ListNode* pHead = Merge(pNode1,pd1);
   
    printf("The HeBing list is: \n");
    
    while(pHead!=NULL)
    {
        PrintListNode(pHead);
        pHead=pHead->next; 
    }
   

    return 0;
}
