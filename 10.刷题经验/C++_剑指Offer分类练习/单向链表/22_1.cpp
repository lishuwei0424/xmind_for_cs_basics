#include <iostream>
#include <stack>//栈
#include "ListNode.h"

using namespace std;

void DaoShuList(ListNode* root,const int k)
{
    if(root==NULL)
        return;
    
    ListNode* pfast=root;
    ListNode* pslow=root;
    
    int i=1;
    while(pfast!=NULL)
    { 
       
      for( ;i<k;i++)
     {
        pfast=pfast->next;
        
     }
     cout<<pfast->value<<endl;
    
    
     pfast=pfast->next;

     if(pfast==NULL)
     {
         cout<<pslow->value<<endl;
     }
      pslow=pslow->next;

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
     
     DaoShuList(pNode1,3);

    return 0;

} 
