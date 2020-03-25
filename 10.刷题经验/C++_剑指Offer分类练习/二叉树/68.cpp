/*
// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。
*/

#include <iostream>
using namespace std;

#include "Tree.h"
#include <list>

//得到从根节点root开始到达节点node的路径，保存在path中。
bool GetNodePath(TreeNode* root,TreeNode* node, list<TreeNode*>& path)
{
    if(root==node)
        return true;

    path.push_back(root);

    bool found=false;

    vector<TreeNode*>::iterator i=root->children.begin();
    while(!found && i<root->children.end())
    {
        found=GetNodePath(*i, node,path);
        ++i;
    }

    if(!found)
        path.pop_back();
    
    return found;
}

//得到两条路径的最后一个公共节点
TreeNode* GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2)
{
    list<TreeNode*>::const_iterator iterator1=path1.begin();
    list<TreeNode*>::const_iterator iterator2=path2.begin();

    TreeNode* pLast=NULL;

    while(iterator1 !=path1.end() && iterator2 !=path2.end())
    {
        if(*iterator1==*iterator2)
            pLast=*iterator1;
        
        iterator1++;
        iterator2++;
    }

    return pLast;
}


TreeNode* GetLastCommonParent(TreeNode* root, TreeNode* node1, TreeNode* node2)
{
    if(root==NULL || node1==NULL || node2==NULL)
        return NULL;

    list<TreeNode*> path1;
    GetNodePath(root,node1,path1);

    list<TreeNode*> path2;
    GetNodePath(root,node2,path2);

    return GetLastCommonNode(path1,path2);
}


// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10

int main()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    PrintTree(pNode1);

TreeNode* pResult = GetLastCommonParent(pNode1, pNode6, pNode8);
cout<<"pResult "<<pResult->value<<endl;

return 0;
}