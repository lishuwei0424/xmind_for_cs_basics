#include <iostream>
using namespace std;

#include "ListNode.h"

void FirstNode(ListNode* root1,ListNode* root2)
{
    if(root1==NULL || root2==NULL)
        return ;

   // int firstnode=0;

    ListNode* p1=root1;
    ListNode* p2=root2;
    
    int data1[]={};
    int i=0;
    int data2[]={};
    int j=0;
    
    while(p1!=NULL)
    {  
       data1[i]=p1->value;
       i++;
       p1=p1->next;
    }

    cout<<"i"<<i<<endl;
    for(int w=0;w<i;w++)
    {
        cout<<data1[w]<<endl;
    }

     while(p2!=NULL)
    {  
       data2[j]=p2->value;
       j++;
       p2=p2->next;
    }

    cout<<"j"<<j<<endl;
       for(int w=0;w<i;w++)
    {
        cout<<data2[w]<<endl;
    }
   //以上没错


    for(int k1=0;k1<i;k1++)
    {   
           cout<<"data1 "<<k1<<" "<<data1[k1]<<endl;//这里有bug
        for(int k2=0;k2<j;k2++)
        {    
         
            cout<<"data2 "<<k2<<" "<<data2[k2]<<endl;
            if(data1[k1]==data2[k2])
            {   
              // firstnode=data1[k1];
               cout<<"firstnode"<<data1[k1]<<endl;
            }
        }
    }
  


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
    ListNode* pd3 = CreateListNode(5);
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
    
    FirstNode(pNode1,pd1);
   
   // printf("The HeBing list is: \n");
   
  // cout<<"firstnode= "<<pHead<<endl;

    return 0;
}
