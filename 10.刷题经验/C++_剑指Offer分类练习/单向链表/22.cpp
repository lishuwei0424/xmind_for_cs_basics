#include <iostream>
#include <stack>//栈
#include "ListNode.h"

using namespace std;

void DaoShuList(ListNode* root,const int k)
{
    if(root==NULL)
        return;
    
    ListNode* phead=root;
    std::stack<int> stk;
    int leng=0;
    while(phead!=NULL)
    {
        stk.push(phead->value);
        leng++;
        phead=phead->next;
    }
     cout<<leng<<endl;

     int i=1;
    for(;i<=k;i++)
    {    
         stk.top();//取出但不删除，可有可无
         stk.pop();
         cout<<"i"<<i<<endl;
      if(i==k-1)
      { 
       cout<<stk.top()<<endl;
      }
         
    }         
}



    int main()
{   

    ListNode* pNode1 =  CreateListNode(1);
    ListNode* pNode2 =  CreateListNode(2);
    ListNode* pNode3 =  CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
     ListNode* pNode6 = CreateListNode(6);

     ConnectListNodes(pNode1, pNode2);
     ConnectListNodes(pNode2, pNode3);
     ConnectListNodes(pNode3, pNode4);
     ConnectListNodes(pNode4, pNode5);
     ConnectListNodes(pNode5, pNode6);
     
     DaoShuList(pNode1,3);

    return 0;

} 
