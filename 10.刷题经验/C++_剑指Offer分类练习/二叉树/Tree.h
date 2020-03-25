#pragma once

#include <vector>

//普通树的定义
struct TreeNode 
{
    int                       value;    
    std::vector<TreeNode*>    children;    
};

TreeNode* CreateTreeNode(int value)
{
    TreeNode* pNode = new TreeNode();
    pNode->value = value;

    return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild)
{
    if(pParent != nullptr)
    {
        pParent->children.push_back(pChild);
    }
}

void PrintTreeNode(const TreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d.\n", pNode->value);

        printf("its children is as the following:\n");
        std::vector<TreeNode*>::const_iterator i = pNode->children.begin();
        for(;i < pNode->children.end();i++)
        {
            if(*i != nullptr)
                printf("%d\t", (*i)->value);
            
            //  if(*i == nullptr)
            //      printf("its children is NULL");
        }
        if(!pNode->children.size())
        {
             printf("its children is NULL");
        }
       
        printf("\n");
    }

    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const TreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        std::vector<TreeNode*>::const_iterator i = pRoot->children.begin();
        while(i < pRoot->children.end())
        {
            PrintTree(*i);
            ++i;
        }
    }
}

void DestroyTree(TreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        std::vector<TreeNode*>::iterator i = pRoot->children.begin();
        while(i < pRoot->children.end())
        {
            DestroyTree(*i);
            ++i;
        }

        delete pRoot;
    }
}