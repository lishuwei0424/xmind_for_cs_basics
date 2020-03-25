
/*
// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印
*/

#include <iostream>
using namespace std;

#include <deque>

#include "BinaryTree.h"

void PrintFromTopToBottom(BinaryTreeNode* root)
{
    if(root==NULL)
        return;
    
    //建立一个队列，存储打印节点的左右节点，
    //当打印此节点后，陆续打印左右节点
    std::deque<BinaryTreeNode*> deque;

    deque.push_back(root);

    while(deque.size())
    {
        BinaryTreeNode* pNode=deque.front();//返回队列中最早元素，并未删除
        deque.pop_front();//删除最早元素

        cout<<pNode->value<<endl;

        if(root->left)
            deque.push_back(pNode->left);
        
        if(root->right)
            deque.push_back(pNode->right);
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
    Connect(p2, p4,p5);
    Connect(p3,p6,p7);
    PrintTree(p1);
  
  PrintFromTopToBottom(p1);


}