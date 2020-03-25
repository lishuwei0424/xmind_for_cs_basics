
/*
// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。
*/


#include <iostream>
using namespace std;

#include "BinaryTree.h"

BinaryTreeNode* ZhongXu(BinaryTreeNode* root, unsigned int& k);

BinaryTreeNode* Knode(BinaryTreeNode* root,unsigned int k)
{
    if(root==NULL || k==0)
        return NULL;


    return ZhongXu(root,k);
}

//中序遍历 ,递归实现，左根右
BinaryTreeNode* ZhongXu(BinaryTreeNode* root, unsigned int& k)
{
    if(root==NULL)
        return NULL;

    BinaryTreeNode* target=NULL;
    
        if(root->left!=NULL)
           target=ZhongXu(root->left,k);
     
    if(target==NULL)
    {
        if(k==1)
            target=root;
        
        k--;
    }
    

    if(target==NULL && root->right!=NULL)
          target=ZhongXu(root->right,k);   
    
    return target;
   
   
}

int main()
{
    BinaryTreeNode* p1=Create(1);
    BinaryTreeNode* p2=Create(2);
    BinaryTreeNode* p3=Create(3);
    BinaryTreeNode* p4=Create(4);
    BinaryTreeNode* p5=Create(5);
    BinaryTreeNode* p6=Create(6);
    BinaryTreeNode* p7=Create(7);

    Connect(p1, p2, p3); 
    Connect(p3, NULL, p6);
    Connect(p5,p7,NULL);
    PrintTree(p1);
  
  
    unsigned int i=2;
    BinaryTreeNode*  target1= Knode(p1,i);
    
    cout<<"target "<<target1->value<<endl;


}