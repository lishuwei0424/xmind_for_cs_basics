
/*
// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。
*/

#include <iostream>
using namespace std;

#include <stack>

#include "BinaryTree.h"

void Print(BinaryTreeNode* pRoot)
{
    if(pRoot == NULL)
        return;
    
    //建立两个栈，辅助存储打印当前行和下一行的数据
    std::stack<BinaryTreeNode*> levels[2];

    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();

        printf("%d ", pNode->value);
        
        //1,3,5.......层存储左，右边
        if(current == 0)
        {
            if(pNode->left != nullptr)
                levels[next].push(pNode->left);
            if(pNode->right != nullptr)
                levels[next].push(pNode->right);
        }

        //2,4,6......层存储右，左
        else
        {
            if(pNode->right != nullptr)
                levels[next].push(pNode->right);
            if(pNode->left != nullptr)
                levels[next].push(pNode->left);
        }

        if(levels[current].empty())
        {
            printf("\n");

            //交换两个栈继续打印下一层
            current = 1 - current;
            next = 1 - next;
        }
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
  
  Print(p1);


}