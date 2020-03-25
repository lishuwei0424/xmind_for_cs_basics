/*
// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"

//  中序遍历可以排序，把根节点取出与左子树和右子树分别链接
//遍历和转换都是一样的，用递归
void  ConvertNode(BinaryTreeNode* root, BinaryTreeNode** LastNodeList);

BinaryTreeNode* Convert(BinaryTreeNode* root)
{
    //定义一个指向双向链表尾部节点的指针
    BinaryTreeNode* LastNodeList=NULL;
    ConvertNode(root, &LastNodeList);
     
     //cout<<"LastNodeList 3 "<<(*LastNodeList)->value<<endl;
    //返回双向链表的头节点
    BinaryTreeNode* pHeadOfList=LastNodeList;
    while(pHeadOfList!=NULL && pHeadOfList->left!=NULL)
        pHeadOfList=pHeadOfList->left;

    return pHeadOfList;
}


void  ConvertNode(BinaryTreeNode* root, BinaryTreeNode** LastNodeList)
{
    if(root==NULL)
        return;

    //定义指向当前节点的指针
    BinaryTreeNode* pCurrent=root;
    
   // cout<<"LastNodeList "<<(*LastNodeList)->value<<endl;//扔进来是空的
    
    if(pCurrent->left!=NULL)
    {
        ConvertNode(pCurrent->left,LastNodeList);
        cout<<"pCurrent 1 "<<pCurrent->value<<endl;
        cout<<"pCurrent->left "<<pCurrent->left->value<<endl;
        cout<<"LastNodeList 1 "<<(*LastNodeList)->value<<endl;
        cout<<endl;
    }

    //当当前节点指向根节点的时候，拿它与左右链接
    pCurrent->left=*LastNodeList;
  //  cout<<"pCurrent->left "<<pCurrent->left->value<<endl;//此时为空
    if(*LastNodeList!=NULL)
    {
        (*LastNodeList)->right=pCurrent;
         cout<<"(*LastNodeList)->right "<<(*LastNodeList)->right->value<<endl;
         cout<<endl;
    }
        
    
    *LastNodeList=pCurrent;//最后使其指向根节点，作为右子树的最小值，开始遍历右子数
    cout<<"(*LastNodeList) "<<(*LastNodeList)->value<<endl;
    cout<<endl;

    if(pCurrent->right!=NULL)
    {
         ConvertNode(pCurrent->right,LastNodeList);
        cout<<"pCurrent 2 "<<pCurrent->value<<endl;
        cout<<"pCurrent->right "<<pCurrent->right->value<<endl;
        cout<<"LastNodeList 2 "<<(*LastNodeList)->value<<endl;
        cout<<endl;
    }
}

/*
(*LastNodeList) 4

pCurrent 1 6
pCurrent->left 4
LastNodeList 1 4

(*LastNodeList)->right 6

(*LastNodeList) 6

(*LastNodeList)->right 8

(*LastNodeList) 8

pCurrent 2 6
pCurrent->right 8
LastNodeList 2 8

pCurrent 1 10
pCurrent->left 6
LastNodeList 1 8

(*LastNodeList)->right 10

(*LastNodeList) 10

(*LastNodeList)->right 12

(*LastNodeList) 12

pCurrent 1 14
pCurrent->left 12
LastNodeList 1 12

(*LastNodeList)->right 14

(*LastNodeList) 14

(*LastNodeList)->right 16

(*LastNodeList) 16

pCurrent 2 14
pCurrent->right 16
LastNodeList 2 16

pCurrent 2 10
pCurrent->right 12
LastNodeList 2 16
*/

void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->value);

        if(pNode->right== nullptr)
            break;
        pNode = pNode->right;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->value);

        if(pNode->left == nullptr)
            break;
        pNode = pNode->left;
    }

    printf("\n");
}


int main()
{
    BinaryTreeNode* p1=Create(10);
    BinaryTreeNode* p2=Create(6);
    BinaryTreeNode* p3=Create(14);
    BinaryTreeNode* p4=Create(4);
    BinaryTreeNode* p5=Create(8);
    BinaryTreeNode* p6=Create(12);
    BinaryTreeNode* p7=Create(16);

    Connect(p1, p2, p3); 
    Connect(p2, p4, p5);
    Connect(p3,p6,p7);
   // PrintTree(p1);
  
  BinaryTreeNode* result=Convert(p1);
   PrintDoubleLinkedList(result);
   
   return 0;


}