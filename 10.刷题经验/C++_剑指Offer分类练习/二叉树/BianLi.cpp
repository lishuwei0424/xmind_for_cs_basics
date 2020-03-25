#include <iostream>
using namespace std;

#include "BinaryTree.h"

#include <stack>

//前序遍历 ,递归实现，根左右
void QianXu(BinaryTreeNode* root)
{
    if(root==NULL)
        return;

   // BinaryTreeNode* pNode=root;
    if(root!=NULL)
     cout<<root->value<<endl;
    if(root->left!=NULL)
        QianXu(root->left);
    if(root->right!=NULL)
        QianXu(root->right);

}

//使用栈的前序遍历 
/*
栈实现前序遍历较简单，由于每次先输出根节点，再输出左节点随后是右节点。
算法是：
1、若栈非空输出根节点，并出栈
2、将右节点压栈（如果存在）
3、将左节点压栈（如果存在）
4、重复第1步直到栈空
注意：之所以先压右节点是考虑了栈的特性，这样在迭代过程中可以先拿到左节点处理。（栈的先入后出）
*/
void StackQianXu(BinaryTreeNode* root)
{   
    if(root==NULL)
        return;

    std::stack<BinaryTreeNode*> QianStack;
    BinaryTreeNode* p=root;

    QianStack.push(p);
    while(!QianStack.empty())
        {
            p=QianStack.top();
            cout<<p->value<<endl;
            QianStack.pop();
            if(p->right!=NULL)
                QianStack.push(p->right);
            if(p->left!=NULL)
                QianStack.push(p->left);
        }
    
}

//中序遍历 ,递归实现，左根右
void ZhongXu(BinaryTreeNode* root)
{
    if(root==NULL)
        return;

   // BinaryTreeNode* pNode=root;
    
        if(root->left!=NULL)
           ZhongXu(root->left);
        cout<<root->value<<endl;
         //if(root!=NULL)
          // ZhongXu(root);
         if(root->right!=NULL)
          ZhongXu(root->right);   

}

/*
栈的中序遍历需要套两层循环，由于需要先输出左节点，
因此必须向下查找直到左节点为空才能输出。处理逻辑如下：

1、如果栈顶元素非空且左节点存在，将其入栈，重复该过程。若不存在则进入第2步
2、若栈非空，输出栈顶元素并出栈。判断刚出栈的元素的右节点是否存在，
不存在重复第2步，存在则将右节点入栈，跳至第1步
*/

//思路没问题，写的代码有问题，没出正确结果？？？？？？
void StackZhongXu(BinaryTreeNode* root)
{   
    if(root==NULL)
        return;

    std::stack<BinaryTreeNode*> ZhongStack;
    BinaryTreeNode* p=root;
    ZhongStack.push(p);

    while(!ZhongStack.empty())
        {  

            while(ZhongStack.top()->left!=NULL)
            {  
              ZhongStack.push(ZhongStack.top()->left);
            }
                 
            while(!ZhongStack.empty() )
            {   
                BinaryTreeNode* p=ZhongStack.top();
                cout<<p->value<<endl;
                ZhongStack.pop();

               if(p->right!=NULL)
                {
                   ZhongStack.push(p->right);
                    break;
                }
                    
            }

 /*
    while(p!=NULL)
        {  

            while(p!=NULL)
            {  
              //  if(p->right)
                //{
                    // ZhongStack.push(p->right);
               // }
                ZhongStack.push(p);
                cout<<"top "<<ZhongStack.top()->value<<endl;
                p=p->left;  
            }
                 
            p=ZhongStack.top();
            //cout<<"00"<<endl;
            cout<<"p "<<p->value<<endl;
            while(!ZhongStack.empty() )
            {
                // cout<<"00"<<endl;
                cout<<p->value<<endl;
                if(p->right==NULL)
                {
                    ZhongStack.pop();
                    p=ZhongStack.top();  
                }
               else if(p->right!=NULL)
               {
                  ZhongStack.push(p->right); 
                  cout<<"00 "<<p->right->value<<endl;
                  // p=p->right;
                   break;
               }       
            }
         
           if(p->right!=NULL)
             {
                  ZhongStack.push(p->right); 
                  cout<<"00 "<<p->right->value<<endl;
                   p=p->right;
                   break;
             }  
             */                 
       }  
}

//后序遍历 ,递归实现，左根右
void HouXu(BinaryTreeNode* root)
{
    if(root==NULL)
        return;

     if(root->left!=NULL)
        HouXu(root->left);
         //if(root!=NULL)
          // ZhongXu(root);
    if(root->right!=NULL)
        HouXu(root->right); 
    cout<<root->value<<endl;  

}

/*
后序遍历在中序的双层循环的基础上需要加入一个记录，专门记录上一次出栈的节点。步骤如下：

1、如果栈顶元素非空且左节点存在，将其入栈，重复该过程。若不存在则进入第2步（该过程和中序遍历一致）
2、判断上一次出栈节点是否当前节点的右节点，或者当前节点是否存在右节点，
满足任一条件，将当前节点输出，并出栈。否则将右节点压栈。跳至第1步
*/

//具体没有用图画出来 ？？？？？？？
void StackHouXu(BinaryTreeNode* root)
{   
    if(root==NULL)
        return;

    std::stack<BinaryTreeNode*> HouStack;
    HouStack.push(root);

     BinaryTreeNode* lastpop=NULL;

    while(!HouStack.empty())
        {  

            while(HouStack.top()->left!=NULL)
            {  
               HouStack.push(HouStack.top()->left);
            }
                 
            while(!HouStack.empty() )
            {
                if(lastpop==HouStack.top()->right ||
                 HouStack.top()->right==NULL )
                 {
                     cout<< HouStack.top()->value<<endl;
                     lastpop= HouStack.top();
                    HouStack.pop(); 
                 }
                
                else if( HouStack.top()->right!=NULL)
                {
                    HouStack.push(HouStack.top()->right);
                    break;
                }
                    
            }
                           
       }  
}

int main()
{   
  
    BinaryTreeNode* node1= Create(10);
    BinaryTreeNode* node2= Create(6);
    BinaryTreeNode* node3= Create(14);
    BinaryTreeNode* node4= Create(4);
    BinaryTreeNode* node5= Create(8);
    BinaryTreeNode* node6= Create(12);
    BinaryTreeNode* node7= Create(16);

    Connect(node1,node2,node3);
    Connect(node2,node4,node5);
    Connect(node3,node6,node7);

   // PrintTree(node1);
    QianXu(node1);
    cout<<endl;
    StackQianXu(node1);
    cout<<endl;

    ZhongXu(node1);
    cout<<endl;
    StackZhongXu(node1);
    cout<<endl;
 
    HouXu(node1);
    cout<<endl;
    StackHouXu(node1);


    return 0;

}