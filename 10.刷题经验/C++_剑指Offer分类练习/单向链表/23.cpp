#include <iostream>
using namespace std;

#include "ListNode.h"

ListNode* HunRuKouNode(ListNode* root)
{
    if(root==NULL)
        return NULL;

    ListNode* pslow=root;
    ListNode* pfast=root;
    
    ListNode* pmeet=NULL;
     int huanleng=0;

    while(pslow!=NULL)
    {
       pslow=pslow->next;
       pfast=pfast->next->next;
       
       cout<<"0"<<endl;
       cout<<"slow "<<pslow->value<<endl;
       cout<<"fast "<<pfast->value<<endl;

       if(pslow->value==pfast->value)
       {   cout<<"1"<<endl;
           pmeet=pslow;
           cout<<"pmeet "<<pmeet->value<<endl;
          
            break;
       }
    }
    
    //缺少这个
    if(pmeet==NULL)
        return NULL;

    ListNode* pslow2=NULL;
    pslow2=pslow->next;
    while(pslow2->value!=pmeet->value)
     {
           huanleng++;
          pslow2=pslow2->next;
    }
    cout<<"huanleng "<<huanleng<<endl;
    
    ListNode* pNode1=root;
    ListNode* pNode2=root;
    for(int i=0;i<=huanleng;i++)
    {
        pNode1=pNode1->next;
    }
        
    while(pNode1!=NULL && pNode1->value!=pNode2->value)
    { 
        pNode1=pNode1->next;
        pNode2=pNode2->next;

    }
    ListNode* huanrukounode=pNode1;

    return huanrukounode;
    
}



int main(int argc, char* argv[])
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    //ListNode* pNode7 = CreateListNode(3);
    
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    
    //环都建错啦啦啦啦啦啦
    //ConnectListNodes(pNode6, pNode7);

     ConnectListNodes(pNode6, pNode5);
    
     printf("The FirstNode list is: \n");
    ListNode* huanrukounode=HunRuKouNode(pNode1);
   
   
    PrintListNode( huanrukounode);

    return 0;
}
