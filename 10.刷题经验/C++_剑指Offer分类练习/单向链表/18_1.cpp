#include <iostream>
using namespace std;

#include "ListNode.h"


void DeleteNode(ListNode* root,ListNode* deletenode)
{
    if(root==NULL)
        return;

    //统计链表长度
    ListNode* phead=root;
    int leng=0;
    int data[]={};
    while(phead!=NULL)
    {   
        data[leng]=phead->value;

        leng++;
        phead=phead->next;
    }

    cout<<leng<<endl;
    //统计deletenode的前面长度
     ListNode* pheaddelete=root;
    int lengdelete=0;
    while(pheaddelete!=NULL && pheaddelete!=deletenode)
    {
        lengdelete++;
        pheaddelete=pheaddelete->next;
    } 

    cout<<lengdelete<<endl;
    //计算deletenode所在位
    int k=0;
    if(lengdelete<=leng)
    {
        k=leng-lengdelete;
    }

    //打印删除后的链表元素
    for(int i=0;i<k-1;i++)
    {
        cout<<data[i]<<endl;
    }

    for(int j=k;j<leng;j++)
    {
        cout<<data[j]<<endl;
    }
     
}

int main()
{
    ListNode* pNode1=CreateListNode(1);
    ListNode* pNode2=CreateListNode(2);
    ListNode* pNode3=CreateListNode(3);
    ListNode* pNode4=CreateListNode(4);
    ListNode* pNode5=CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    
    DeleteNode(pNode1,pNode3);

    return 0;
}
