/*
// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"

//前序遍历这个树的每个节点，若此节点有子节点，就交换它的两个子节点
//当交换完所有非叶子节点的左，右子节点之后，得到树的镜像

void MirrorRecursively(BinaryTreeNode *root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        return;
    
    //交换根节点的6,10
    BinaryTreeNode *temp=root->left;
    root->left=root->right;
    root->right=temp;
   
   //交换10的左右子节点
    if(root->left)
    {   
        cout<<"000"<<endl;
        MirrorRecursively(root->left);
        
    }

    //交换6的左右子节点
    if(root->right)
    {  
        cout<<"111"<<endl;
       MirrorRecursively(root->right);

    }
        


}


int main()
{
    BinaryTreeNode* p1=Create(8);
    BinaryTreeNode* p2=Create(6);
    BinaryTreeNode* p3=Create(10);
    BinaryTreeNode* p4=Create(5);
    BinaryTreeNode* p5=Create(7);
    BinaryTreeNode* p6=Create(9);
    BinaryTreeNode* p7=Create(11);

    Connect(p1, p2, p3); 
    Connect(p2, p4, p5);
    Connect(p3,p6,p7);
    PrintTree(p1);
   
   MirrorRecursively(p1);
     PrintTree(p1);
   return 0;


}