
// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

#include <cstdio>
#include "ListNode.h"

ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    // 得到两个链表的长度
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);
    int nLengthDif = nLength1 - nLength2;

    ListNode* pListHeadLong = pHead1;
    ListNode* pListHeadShort = pHead2;
    if(nLength2 > nLength1)
    {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }
   
   cout<<"leng1 "<<nLength1<<endl;
   cout<<"leng2 "<<nLength2<<endl;

    // 先在长链表上走几步，再同时在两个链表上遍历
    for(int i = 0; i < nLengthDif; ++i)
        pListHeadLong = pListHeadLong->next;

    while((pListHeadLong != nullptr) &&
        (pListHeadLong->value != pListHeadShort->value))
    {
        pListHeadLong = pListHeadLong->next;
        pListHeadShort = pListHeadShort->next;
    }

    // 得到第一个公共结点
    ListNode* pFisrtCommonNode = pListHeadLong;
   
    return pFisrtCommonNode;
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
    ListNode* pd2 = CreateListNode(2);
    ListNode* pd3 = CreateListNode(7);
  

    ConnectListNodes(pd1, pd2);
    ConnectListNodes(pd2, pd3);
   
    return pd1;
}

int main(int argc, char* argv[])
{
    ListNode* pNode1=List1();
    ListNode* pd1=List2();
    
    ListNode* pResult = FindFirstCommonNode(pNode1, pd1);
    PrintListNode(pResult);


    return 0;
}
