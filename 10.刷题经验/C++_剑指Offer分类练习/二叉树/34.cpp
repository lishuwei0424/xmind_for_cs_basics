
/*
// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"
#include <vector>

void FindPath(BinaryTreeNode *root,int sum, std::vector<int> &path,int currentsum);

void FindPath(BinaryTreeNode *root,int sum)
{
    if(root==NULL)
        return;
    
    std::vector<int> path;//利用vector实现栈，保证一次打印可出现多值
    int currentsum=0;
    FindPath(root,sum,path,currentsum);
}

void FindPath(BinaryTreeNode *root,int sum, std::vector<int> &path,int currentsum)
{
   currentsum+=root->value;
   path.push_back(root->value);

   //如果到达叶子节点，并且路径上的和满足sum。则打印
   bool isLeaf=root->left==NULL && root->right==NULL;
   if(currentsum == sum && isLeaf)
   {
       std::vector<int>::iterator iter=path.begin();
       for(;iter!=path.end();++iter)
            cout<<*iter<<endl;
   }
   

   //非叶子节点
   if(root->left !=NULL)
    FindPath(root->left,sum,path,currentsum);
   
   if(root->right !=NULL)
    FindPath(root->right,sum,path,currentsum);

   //在返回父节点之前，在路径上删除该节点
   path.pop_back();

}


int main()
{
    BinaryTreeNode* p1=Create(10);
    BinaryTreeNode* p2=Create(5);
    BinaryTreeNode* p3=Create(12);
    BinaryTreeNode* p4=Create(4);
    BinaryTreeNode* p5=Create(7);

    Connect(p1, p2, p3);
    Connect(p2, p4, p5);
    PrintTree(p1);
   
   FindPath(p1,22);

}