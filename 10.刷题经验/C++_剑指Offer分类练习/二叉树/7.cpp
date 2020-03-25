/*
// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
*/


#include <iostream>
using namespace std;

#include "BinaryTree.h"

#include <exception>


BinaryTreeNode* ConstructCore(int* startPre,int* endPre,int* startMid,int* endMid);

BinaryTreeNode* Construct(int* pre,int* mid,int leng)
{
    if(pre==NULL || mid==NULL || leng<=0)
        return NULL;
    
    return ConstructCore(pre,pre+leng-1,mid,mid+leng-1);
}

BinaryTreeNode* ConstructCore(int* startPre,int* endPre,int* startMid,int* endMid)
{
    //前序遍历第一个数字是根节点
    int rootValue=startPre[0];
    BinaryTreeNode* root=new BinaryTreeNode();
    root->value=rootValue;
    root->left=root->right=NULL;

    if(startPre==endPre)
    {
        if(startMid==endMid && *startPre==*startMid)
            return root;

        else
         //throw std::exception("Invalid input.");
         return NULL;
    
    }

    //中序遍历中找到根节点的值
    int* rootMid=startMid;
    while(rootMid<=endMid && *rootMid !=rootValue)
        ++rootMid;

    if(rootMid == endMid && *rootMid!=rootValue)
        //throw std::exception("Invalid input.");
        return NULL;
   
   int leftLeng=rootMid-startMid;
   int* leftPreEnd=startPre+leftLeng;//左树的最后一个节点

   //构建左子树
   if(leftLeng>0)
   {
       root->left=ConstructCore(startPre+1,leftPreEnd,
       startMid,rootMid-1);
   }
   
   //构建右子树
   if(leftLeng<endPre-startPre)
   {
       root->right=ConstructCore(leftPreEnd+1,endPre,
       rootMid+1,endMid);
   }

   return root;
}



int main()
{
    const int leng= 8;
    int pre[leng] = {1, 2, 4, 7, 3, 5, 6, 8};
    int mid[leng] = {4, 7, 2, 1, 5, 3, 8, 6};

    BinaryTreeNode* root=Construct(pre,mid,leng);
    PrintTree(root);



}