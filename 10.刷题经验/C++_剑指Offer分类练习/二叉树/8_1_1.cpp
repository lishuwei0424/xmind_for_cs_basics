


// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。


#include <iostream>
using namespace std;

#include "BinaryTree.h"


BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;

    BinaryTreeNode* pNext = nullptr;//定义返回值，在函数里面赋值

    if(pNode->right!= nullptr)
    {
        BinaryTreeNode* pRight = pNode->right;
        while(pRight->left != nullptr)
            pRight = pRight->left;

        pNext = pRight;
    }

    else if(pNode->parent!= nullptr)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->parent;

   //该节点没有右子树，并且他还是他父节点的右子节点
   //沿着指向父节点的指针一直向上遍历，直到找到一个是他父节点的左子节点的节点
   //如果这样的节点存在，那么这个节点的父节点就是要找的节点
        while(pParent != nullptr && pCurrent == pParent->right)
        {
            pCurrent = pParent;
            pParent = pParent->parent;
        }
     //没有右子树，节点是他父节点的左子节点，
    //下一个节点就是他的父节点
        pNext = pParent;
    }

    return pNext;
}



int main()

{  
    //       8
//        6      10
//       5 7    9  11
    BinaryTreeNode* pNode8 = Create(8);
    BinaryTreeNode* pNode6 = Create(6);
    BinaryTreeNode* pNode10 = Create(10);
    BinaryTreeNode* pNode5 = Create(5);
    BinaryTreeNode* pNode7 = Create(7);
    BinaryTreeNode* pNode9 = Create(9);
    BinaryTreeNode* pNode11 = Create(11);

    Connect(pNode8, pNode6, pNode10);
    Connect(pNode6, pNode5, pNode7);
    Connect(pNode10, pNode9, pNode11);
   

 BinaryTreeNode* next=GetNext(pNode10);
 cout<<next->value<<endl;

}