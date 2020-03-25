
/*
// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"
#include <vector>


//反向考虑，判断数组是不是后序排列的二叉树
bool HaveHouxuOfTree(int data[],int leng)
{
    if(data==NULL || leng<=0)
        return false;
    
    //后序遍历中根节点的值是最后一个
    int root=data[leng-1];

    //左子树节点的值小于根节点
    int i=0;
    for(;i<leng-1;++i)
    {
        if(data[i]>root)
            break;
    }

    //右子树的值大于根节点
    int j=i;
    for(;j<leng-1;++j)
    {
        if(data[j]<root)
            return false;
    }

    //判断左子树是不是二叉树
    bool left=true;
    if(i>0)
        left=HaveHouxuOfTree(data,i);
    
    //判断右子树是不是二叉树
    bool right=true;
    if(j<leng-1)
      right=HaveHouxuOfTree(data+i,leng-i-1);

    return (left && right);

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
    Connect(p3, p6, p7);
    PrintTree(p1);
   
   int data[20]={5,7,6,9,11,10,8};
   int leng=sizeof(data)/sizeof(int);
   
   bool result=false;
   result=HaveHouxuOfTree( data, leng);
   cout<<result<<endl;


}