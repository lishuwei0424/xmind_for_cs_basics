
#include <iostream>
using namespace std;

#include "ListNode.h"

//逻辑有点乱，妈的，缓缓再看，看完更新

//这一步是在链表后面加同样的数字，把N'放在N后面
void CopyList(ListNode* root)
{
     if(root==NULL)
        return ;

   
    ListNode* p=root;

    while(p!=NULL)
    {   
      ListNode* pCloned=new ListNode();

      pCloned->value=p->value;
      //cout<<pCloned->value<<endl;

      pCloned->next=p->next;
      pCloned->random=NULL;

      p->next=pCloned;

      p=pCloned->next;
    }

   // return pCopy;
}

//复制随机链表,原始链表上N的随机指向S，那么其对应复制出来的N'是N的next节点，同样S'也是S的next
void ConnectRandomNode(ListNode* root)
{
    ListNode* pNode=root;
    while(pNode!=NULL)
    {
        ListNode* pCloned=pNode->next;
        if(pNode->random!=NULL)
        {
            pCloned->random=pNode->random->next;
        }

        pNode=pCloned->next;
    }
}

//拆开，偶数拿出来就是拉
ListNode* ChaiKai(ListNode* root)
{
    ListNode* pNode=root;
    ListNode* pClonedHead=NULL;
    ListNode* pClonedNode=NULL;
    

    //这里只走啦一步
    if(pNode!=NULL)
    {   //11 22 33 44 55
        pClonedHead=pClonedNode=pNode->next;//1
         cout<<"p "<<pNode->value<<endl;//1
          cout<<"p "<<pNode->next->value<<endl;//B
   
        pNode->next=pClonedNode->next;

        cout<<"p "<<pNode->value<<endl;//A
        cout<<"p "<<pNode->next->value<<endl;//A'

        pNode=pNode->next;//1
        cout<<" pNode "<< pNode->value<<endl;//B
        cout<<" pNode->next "<< pNode->next->value<<endl;//B'
         cout<<" pNode->next "<< pNode->next->next->value<<endl;
    } 

    while(pNode!=NULL)
    {
        pClonedNode->next=pNode->next;
        pClonedNode=pClonedNode->next;

        pNode->next=pClonedNode->next;
        pNode=pNode->next;
    }

    return pClonedHead;//仅仅记录了头节点
}

ListNode* Clone(ListNode* root)
{
     CopyList(root);
     ConnectRandomNode(root);

     return  ChaiKai(root);

}


//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------

int main(int argc, char* argv[])
{
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);
   
     printf("The original list is:\n");
     PrintComplexList(pNode1);
     cout<<endl;
   
     ListNode* clone=Clone(pNode1);
      PrintComplexList(clone);


    return 0;
}