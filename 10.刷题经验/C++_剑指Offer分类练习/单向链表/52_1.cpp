#include <iostream>
using namespace std;

#include "ListNode.h"

ListNode* FirstNode(ListNode* root1,ListNode* root2)
{
    if(root1==NULL || root2==NULL)
        return NULL;

    ListNode* p1=root1;
    ListNode* p2=root2;
   // ListNode* firstnode=NULL;
    int leng1=0;
    int leng2=0;

    while(p1!=NULL)
    {
        leng1++;
        p1=p1->next;

    }

    while(p2!=NULL)
    {
        leng2++;
        p2=p2->next;
    }
    cout<<"leng1"<<leng1<<endl;
    cout<<"leng2"<<leng2<<endl;


   // ListNode* pNode1=root1;
   // ListNode* pNode2=root2;
    int leng=0;
    if(leng1>leng2)
    {
       leng=leng1-leng2;
       for(int i=0;i<leng;i++)
      {
        root1=root1->next;
      }
    }
    else
    {
        leng=leng2-leng1;
        for(int i=0;i<leng;i++)
       {
         root2=root2->next;
       }
    }
    cout<<"leng"<<leng<<endl;
    cout<<"pNode1 "<<root1->value<<endl;
    cout<<"pNode2 "<<root2->value<<endl;
   
   /*
    if(root1->value==root2->value)
    {
       root1=root1->next;
       root2=root2->next;
       
    }*/

    while(root1!=NULL && root1->value!=root2->value)
    { 
        root1=root1->next;
        root2=root2->next;

    }
    ListNode* firstnode=root1;

    return firstnode;
    
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
    ListNode* pd2 = CreateListNode(5);
    ListNode* pd3 = CreateListNode(6);
  

    ConnectListNodes(pd1, pd2);
    ConnectListNodes(pd2, pd3);
   
    return pd1;
}

int main(int argc, char* argv[])
{
    
    ListNode* pNode1=List1();
    ListNode* pd1=List2();
    
    ListNode* first=FirstNode(pNode1,pd1);
   
    printf("The FirstNode list is: \n");
   
    cout<<"firstnode= "<<first->value<<endl;

    return 0;
}
