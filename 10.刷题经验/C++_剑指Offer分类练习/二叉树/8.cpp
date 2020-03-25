
#include <iostream>
using namespace std;

#include "BinaryTree.h"

BinaryTreeNode* GetNext(BinaryTreeNode* root)
{
    if(root==NULL)
        return NULL;
    
    BinaryTreeNode* phead=root;

    //如果一个节点有右子树，那么他的下一个节点就是他的右子树中的
    //最左子节点
    if(phead->right!=NULL)
    {   

        BinaryTreeNode* pRight=phead->right;
        while(pRight->left!=NULL)
        {
           // phead=phead->right->left;
           pRight=pRight->left;
        }
        
        return pRight;
    }
    
    //没有右子树，节点是他父节点的左子节点，
    //下一个节点就是他的父节点
   // if(phead->right==NULL)
   // {
     //   BinaryTreeNode* pParent=phead->parent;
     //   if(phead==pParent->left)
    //       return pParent;
       
   // }

   //以上合并到下面了
   
   //该节点没有右子树，并且他还是他父节点的右子节点
   //沿着指向父节点的指针一直向上遍历，直到找到一个是他父节点的左子节点的节点
   //如果这样的节点存在，那么这个节点的父节点就是要找的节点
   else if(phead->right==NULL)
   {
        BinaryTreeNode* pParent=phead->parent;
        if(phead==pParent->left)
            return pParent;

       // cout<<"00"<<endl;
        if(phead==pParent->right)
         {
           while(pParent->parent!=NULL)
           {

            if(pParent==pParent->parent->left)
                 return pParent->parent;
        
            pParent=pParent->parent;

           }  
         }         
         
   }
   
   return phead;

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