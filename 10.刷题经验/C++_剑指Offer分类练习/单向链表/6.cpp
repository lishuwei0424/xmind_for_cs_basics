#include <iostream>
#include <stack>//栈
#include "ListNode.h"

using namespace std;

//顺序打印
void PrintList(ListNode* root)
{
    if(root==nullptr)
       return;

    ListNode* phead=root;
    while(phead!=NULL)
    {
        PrintListNode(phead);
        phead=phead->next;
    }
}

//逆序打印
//利用栈的先进后出原理，链表入栈，出栈就完成逆序打印
void PrintList_Return(ListNode* root)
{  
    if(root==NULL)
        return;

   std::stack<int> stk;
   ListNode* phead=root;
   while(phead!=NULL)
   {
       stk.push(phead->value);
       phead=phead->next;
   }

   while(!stk.empty())
   {
       cout<<stk.top()<<endl;
       stk.pop();
   }

}

//递归实现
//每访问到一个节点的时候，先递归输出它后面的节点，再输出该节点
void PrintList_DiGui(ListNode* root)
{
    if(root==NULL)
        return;
    cout<<"222"<<endl;
   ListNode* phead=root;
   if(phead!=NULL)
   {   
       if(phead->next!=NULL)
       {
         PrintList_DiGui(phead->next);
         cout<<"111"<<endl;
       }
       cout<<"333"<<endl;
       cout<<phead->value<<endl;
   }
/*
222
222
222
222
222
333
5
111
333
4
111
333
3
111
333
2
111
333
1
*/
   
}

int main()
{   

    ListNode* pNode1 =  CreateListNode(1);
    ListNode* pNode2 =  CreateListNode(2);
    ListNode* pNode3 =  CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

     ConnectListNodes(pNode1, pNode2);
     ConnectListNodes(pNode2, pNode3);
     ConnectListNodes(pNode3, pNode4);
     ConnectListNodes(pNode4, pNode5);
     
     PrintList(pNode1);
     PrintList_Return(pNode1);
     PrintList_DiGui(pNode1);

    return 0;

} 