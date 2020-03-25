/*
// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"
#include <vector>

//左右子树的最大值加1（1是根的那个）
//方法1
int TreeDepth(BinaryTreeNode *root)
{
    if(root==NULL)
        return 0;

    int nleft=TreeDepth(root->left);
    int nright=TreeDepth(root->right);

    return (nleft>nright) ? (nleft+1) :(nright+1);
}

//遍历树的每个节点时候，得到它的左右节点深度
//如果每个节点的左，右子树的深度相差都不超过1,即可
bool IsBalanced(BinaryTreeNode *root)
{
    if(root==NULL)
        return true;
    
    int left=TreeDepth(root->left);
    int right=TreeDepth(root->right);
    int diff=left-right;

    if(diff>1 || diff<-1)
        return false;

    return IsBalanced(root->left) && IsBalanced(root->right);
}


//方法2
bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth);

bool IsBalanced2(const BinaryTreeNode* pRoot)
{
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}

bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth)
{
    if(pRoot == nullptr)
    {
        *pDepth = 0;
        return true;
    }

    int left, right;
    if(IsBalanced(pRoot->left, &left) 
        && IsBalanced(pRoot->right, &right))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1)
        {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }

    return false;
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
    Connect(p2, p4, p5);
    Connect(p3, NULL, p6);
     Connect(p5,p7,NULL);
    PrintTree(p1);

    bool result=false;
  result=IsBalanced(p1);
  cout<<result<<endl;

   bool result2=false;
  result2=IsBalanced(p1);
  cout<<result2<<endl;


}