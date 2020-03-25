#include <iostream>
using namespace std;

#include "ListNode.h"

ListNode* HeBingLiangList(ListNode* root1,ListNode* root2)
{
    if(root1==NULL && root2==NULL)
        return NULL;

    if(root1==NULL && root2!=NULL)
        return root2;

    if(root1!=NULL && root2==NULL)
        return root1;

    ListNode* pHead=NULL;
    ListNode* p1=root1;
    ListNode* p2=root2;
    
    /*
    while(p1!=NULL)
    {
        cout<<"@ "<<p1->value<<endl;
        p1=p1->next;

    }*/
    while(p2!=NULL)
    {
       // ListNode* pnext1=p1;
        //ListNode* pNext2=p2;
     
        if(p1->value<p2->value)
        {
            pHead=p1;
            pHead->next=p2;

            cout<<pHead->value<<endl;

              
           
        }
          // cout<<"p1"<<p1->value<<endl;//??????，妈的不是1357了，为啥？
         
           cout<<"p2"<<p2->value<<endl;
           p1=p1->next;
           p2=p2->next; 
            
    }

    return pHead;
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
    
    ListNode* pHead = HeBingLiangList(pNode1,pd1);
   
    printf("The HeBing list is: \n");
    
    while(pHead!=NULL)
    {
        PrintListNode(pHead);
        pHead=pHead->next; 
    }
   

    return 0;
}
