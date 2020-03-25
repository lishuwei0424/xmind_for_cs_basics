
// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#include <cstdio>
#include "ListNode.h"

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{ 
     //
    if(pListHead == nullptr || k == 0)
        return nullptr;

    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;
    
    //快的先往前走k-1之后，慢的开始从0走
    //当快的走到头，慢的就找到了k
    for(unsigned int i = 0; i < k - 1; ++ i)
    {
        if(pAhead->next != nullptr)
            pAhead = pAhead->next;
        else
        {
            return nullptr;
        }
    }

    pBehind = pListHead;
    while(pAhead->next != nullptr)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;
}



int main(int argc, char* argv[])
{
    
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);

    return 0;
}
