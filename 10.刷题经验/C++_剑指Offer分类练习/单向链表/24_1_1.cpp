
// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include <cstdio>
#include "ListNode.h"

//定义三个节点，一个当前节点，一个前一个，一个后一个

ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = nullptr;//返回的翻转链表节点的头节点
    ListNode* pNode = pHead;//当前节点
    ListNode* pPrev = nullptr;//前一个节点
    while(pNode != nullptr)
    {   

        ListNode* pNext = pNode->next;//后一个节点
        cout<<"00  "<<pNext->value<<endl;

        if(pNext == nullptr)
        {
            pReversedHead = pNode;
           // cout<<"0 "<<pReversedHead->value<<endl;
        }


       // cout<<"1 "<<pPrev->value<<endl;
       //当前节点的下一个为空，为了留给他的前一个节点空间，下面把当前节点的值给他的前一个
       //而自己指向下一节点
       //完成翻转
        pNode->next = pPrev;
       // cout<<"2 "<<pNode->value<<endl;
       
       // cout<<"33 "<<pPrev->value<<endl;//此时第一次还是空

        pPrev = pNode;
        cout<<"3 "<<pNode->value<<endl;
        cout<<"4 "<<pPrev->value<<endl;
        pNode = pNext;
        cout<<"5 "<<pNode->value<<endl;
    }

    return pReversedHead;
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


    ListNode* pReversedHead = ReverseList(pNode1);

    printf("The reversed list is: \n");

    while(pReversedHead!=NULL)
    {
        PrintListNode(pReversedHead);
        pReversedHead=pReversedHead->next; 
    }
   

    return 0;
}
