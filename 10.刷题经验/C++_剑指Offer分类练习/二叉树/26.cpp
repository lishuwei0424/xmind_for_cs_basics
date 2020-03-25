
/*
// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"

bool Equal(double num1,double num2);
bool Tree1HaveTree2(BinaryTreeNode* p1,BinaryTreeNode* l8);

//在树1中查找与树2中根节点一样的节点
bool EqualRoot2(BinaryTreeNode* p1,BinaryTreeNode* l8)
{   
    bool result=false;

    // if(p1==NULL || l8==NULL)
    //     return false;
    
    if(p1!=NULL && l8!=NULL)
    {    
        //如果找到根相等，继续判断左右
         if(Equal(p1->value,l8->value))
            result=Tree1HaveTree2(p1,l8);
        
        //根不等
         if(!result)
            result=EqualRoot2(p1->left,l8);
        if(!result)
            result=EqualRoot2(p1->right,l8);      
    }

    return result;
}

//根相等找到后，接着找左右是否相等
bool Tree1HaveTree2(BinaryTreeNode* p1,BinaryTreeNode* l8)
{    
    bool equal=false;

    if(p1==NULL)
        return false;
    if(l8==NULL)
        return true;

    //不等时候
    if(!Equal(p1->value,l8->value))
        return false;
    
    //递归
    if(Equal(p1->value,l8->value))
    {
        Tree1HaveTree2(p1->left,l8->left);
        equal=true;
    }

    if(equal)
    {
        Tree1HaveTree2(p1->right,l8->right);
    }

    return equal;
       
    // return Tree1HaveTree2(p1->left,l8->left)
    // && Tree1HaveTree2(p1->right,l8->right);
}


//比较两者是否相等
bool Equal(double num1,double num2)
{
    if((num1-num2)>-0.000001 && (num1-num2)<0.0000001)
        return true;
    else
        return false;
    
}


int main()
{
    BinaryTreeNode* p1=Create(8);
    BinaryTreeNode* p2=Create(8);
    BinaryTreeNode* p3=Create(7);
    BinaryTreeNode* p4=Create(9);
    BinaryTreeNode* p5=Create(2);
    BinaryTreeNode* p6=Create(4);
    BinaryTreeNode* p7=Create(7);

    Connect(p1, p2, p3);
    Connect(p2, p4, p5);
    Connect(p5, p6, p7);
    PrintTree( p1);

   BinaryTreeNode* l8=Create(8);
   BinaryTreeNode* l9=Create(9);
   BinaryTreeNode* l2=Create(2);
    Connect(l8, l9, l2);
    PrintTree(l8);
   
   bool finalresult=true;
   finalresult=EqualRoot2(p1,l8);
   cout<<"finalresult  "<<finalresult<<endl;

   DestroyTree(p1);
    DestroyTree(l8);
} 