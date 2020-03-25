#include <iostream>
using namespace std;

#include "ListNode.h"
#include <stack>

void FanZhuanList(ListNode* root)
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

      ListNode* fan1=CreateListNode(stk.top());
      stk.pop();
      ListNode* fan2=CreateListNode(stk.top());
      stk.pop();
      ListNode* fan3=CreateListNode(stk.top());
      stk.pop();
      ListNode* fan4=CreateListNode(stk.top());
      stk.pop();
      ListNode* fan5=CreateListNode(stk.top());
      stk.pop();
      ListNode* fan6=CreateListNode(stk.top());
     
     
     ConnectListNodes(fan1, fan2);
     ConnectListNodes(fan2, fan3);
     ConnectListNodes(fan3, fan4);
     ConnectListNodes(fan4, fan5);
     ConnectListNodes(fan5, fan6);

    ListNode* pfan=fan1;
    while(pfan!=NULL)
    {
        PrintListNode(pfan);
        pfan=pfan->next;
    }


}





  int main()
{   

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);

     ConnectListNodes(pNode1, pNode2);
     ConnectListNodes(pNode2, pNode3);
     ConnectListNodes(pNode3, pNode4);
     ConnectListNodes(pNode4, pNode5);
     ConnectListNodes(pNode5, pNode6);
     
    FanZhuanList(pNode1);

    return 0;

} 