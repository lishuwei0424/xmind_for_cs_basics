
/*
// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。
*/


#include <iostream>
using namespace std;

#include "BinaryTree.h"



//中序遍历 ,递归实现，左根右
template <typename T>
void ZhongXu(BinaryTreeNode* root, T data[],int& i)
{
    if(root==NULL)
        return;

   // BinaryTreeNode* pNode=root;
    
        if(root->left!=NULL)
           ZhongXu(root->left,data,i);

        cout<<root->value<<endl;
        data[i]=root->value;
        i++;

         //if(root!=NULL)
          // ZhongXu(root);
         if(root->right!=NULL)
          ZhongXu(root->right,data,i);   
   
   
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
  
  int data[]={0};
  int i=0;
  ZhongXu(p1,data,i);
  cout<<data[2]<<endl;


}