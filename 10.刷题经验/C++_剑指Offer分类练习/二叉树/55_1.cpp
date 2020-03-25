/*
// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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

//方法2
int FindPath(BinaryTreeNode *root, std::vector<int> &path,int &size,int &maxsize)
{
  
   path.push_back(root->value);

   //如果到达叶子节点，并且路径上的和满足sum。则打印
   bool isLeaf=root->left==NULL && root->right==NULL;
   if(isLeaf)
   {  
     cout<<"path.size= "<<path.size()<<endl;
     size=path.size();
     if(maxsize<size)
     {
         maxsize=size;
     }
   }
   
   //非叶子节点
   if(root->left !=NULL)
    FindPath(root->left,path,size,maxsize);
   
   if(root->right !=NULL)
    FindPath(root->right,path,size,maxsize);

   //在返回父节点之前，在路径上删除该节点
   path.pop_back();

   return maxsize;

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

    int result;
    result=TreeDepth(p1);
    cout<<result<<endl;

    std::vector<int> path;
    int size=0;
    int maxsize=0;
    size=FindPath(p1, path,size,maxsize);
    cout<<size<<endl;



}