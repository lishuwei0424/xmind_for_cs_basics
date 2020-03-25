/*
// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"

//前序遍历和对称前序遍历来判断

bool isSymmetrical(BinaryTreeNode* root1, BinaryTreeNode* root2);

bool isSymmetrical(BinaryTreeNode* root)
{
    return isSymmetrical(root,root);
}

bool isSymmetrical(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;

    if(root1->value!=root2->value)
        return false;

    return isSymmetrical(root1->left,root2->right) && isSymmetrical(root1->right,root2->left);
}

int main()
{
    BinaryTreeNode* p1=Create(8);
    BinaryTreeNode* p2=Create(6);
    BinaryTreeNode* p3=Create(6);
    BinaryTreeNode* p4=Create(5);
    BinaryTreeNode* p5=Create(7);
    BinaryTreeNode* p6=Create(7);
    BinaryTreeNode* p7=Create(5);

    Connect(p1, p2, p3); 
    Connect(p2, p4, p5);
    Connect(p3,p6,p7);
    PrintTree(p1);
   
  bool result=isSymmetrical(p1);
  cout<<"result "<<result<<endl;

   return 0;


}