
// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

#include <cstdio>
#include "ListNode.h"

//思路：将被删除节点的值的下一个值拷贝给被删除节点，而此时被删除节点的指向其
//下一个节点的下一个节点
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // 要删除的结点不是尾结点
    if(pToBeDeleted->next!= nullptr)
    {
        ListNode* pNext = pToBeDeleted->next;
        pToBeDeleted->value = pNext->value;
        pToBeDeleted->next = pNext->next;
 
        delete pNext;
        pNext = nullptr;
    }
    // 链表只有一个结点，删除头结点（也是尾结点）
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    // 链表中有多个结点，删除尾结点
    else
    {
        ListNode* pNode = *pListHead;//双重指针
        while(pNode->next!= pToBeDeleted)
        {
            pNode = pNode->next;            
        }
 
        pNode->next= nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}


void PrintfOri(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");

    ListNode* phead=pListHead;
    while(phead!=NULL)
    {
        PrintListNode(phead);
        phead=phead->next;
    }
   
    printf("The node to be deleted is: \n");
    PrintListNode(pNode);
 
}

void PrintfDel(ListNode* pListHead, ListNode* pNode)
{
     DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    ListNode* phead=pListHead;
    while(phead!=NULL)
    {
        PrintListNode(phead);
        phead=phead->next;
    }
 
}

//补充知识
void change1(int *a,int &b)
{
     a=&b;//10
} 


void change2(int *a,int &b)
{
    *a=b;//20
}

void change3(int **a,int &b)
{
    *a=&b;//20
}

void change4(int& a)
{
    a=20;//20
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
   
    PrintfOri(pNode1, pNode3);

    PrintfDel(pNode1, pNode3);

    //补充结果
    int a1=10,b1=20;
    int *p_a1=&a1;
    change1(p_a1,b1);
    printf("%d\n",*p_a1);//10
    
    /*
    其实系统有一个隐含的操作，就是_a=p_a,让_a也指向p_a所指向的地址，
    而我们对_a的指向进行改变的时候并不会影响p_a的指向。
    但是如果对_a指向的地址所存放的数据进行操作的话，
    p_a指向的地址所存放的数据也会改变，因为他们指向的同一地址
    */
    
    //这样输出就变成了20，因为是对_a和p_a共同指向的地址所存放的数据进行操作。
    int a2=10,b2=20;
    int *p_a2=&a2;
    change2(p_a2,b2);
    printf("%d\n",*p_a2);//20
    
    /*
    但有时候我们需要的是把p_a的指向改变，让p_a=&b,
    而不仅仅是对p_a所指向的地址所存放的数据进行改变。
    这时候我们就需要用到双重指针，顾名思义，即指向指针的指针，
    就是指向一个指针的地址,这样就可以把一个指针的地址传递进去，
    从而直接对那个指针进行操作，比如
    */

   //这里面隐含操作就是 int** _a=&p_a;这样*_a就是p_a了，所以输出为20
    int a3=10,b3=20;
    int *p_a3=&a3;
    change3(&p_a3,b3);
    printf("%d\n",*p_a3);//20
    
    int a4=10,b4=20;
    int *p_a4=&a4;
    change4(a4);
    printf("%d\n",a4);//20


    return 0;
}
