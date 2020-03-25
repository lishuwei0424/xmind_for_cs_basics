#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
using namespace std;

struct BinaryTreeNode
{
   int value;
   BinaryTreeNode* left;
   BinaryTreeNode* right;

   //指向父节点的
   BinaryTreeNode* parent;
};

BinaryTreeNode* Create(int val)
{
    BinaryTreeNode* pNode=new BinaryTreeNode();
    pNode->value=val;
    pNode->left=NULL;
    pNode->right=NULL;

    //////////
    pNode->parent=NULL;

    return pNode;
}

void Connect(BinaryTreeNode* pParent,BinaryTreeNode* pLeft,
BinaryTreeNode* pRight)
{
    if(pParent!=NULL)
    {
        pParent->left=pLeft;
        pParent->right=pRight;

        /////////
        if(pLeft!=NULL)
            pLeft->parent=pParent;
        if(pRight!=NULL)
            pRight->parent=pParent;
    }
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode!=NULL)
    {
       cout<<"node: "<<pNode->value<<endl;

       if(pNode->left!=NULL)
            cout<<"left: "<<pNode->left->value<<endl;
        else
            cout<<"left is NULL"<<endl;
        
        if(pNode->right!=NULL)
             cout<<"right: "<<pNode->right->value<<endl;
        else
             cout<<"right is NULL"<<endl;    
    }

    else
      cout<<"node is NULL "<<endl;
    
    cout<<endl;           
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot!=NULL)
    {
        if(pRoot->left!=NULL)
            PrintTree(pRoot->left);
        if(pRoot->right!=NULL)
             PrintTree(pRoot->right);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot!=NULL)
    {
        BinaryTreeNode* pLeft=pRoot->left;
        BinaryTreeNode* pRight=pRoot->right;

        delete pRoot;
        pRoot=NULL;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

#endif
