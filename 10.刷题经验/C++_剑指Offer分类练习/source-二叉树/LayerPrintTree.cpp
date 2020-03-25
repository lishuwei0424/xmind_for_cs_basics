#include "stdio.h"
#include <queue>
#include <iostream>
using namespace std;

typedef struct BiTNode
{
    char data;   /*结点的数据域*/
    struct BiTNode *lchild , *rchild;  /*指向左孩子和右孩子*/
} BiTNode , *BiTree;

/*创建一棵二叉树*/
void CreatBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));  /*创建根结点*/
        (*T)->data = c;    /*向根结点中输入数据*/
        CreatBiTree(&((*T)->lchild));  /*递归地创建左子树*/
        CreatBiTree(&((*T)->rchild));  /*递归地创建右子树*/
    }
}

/*遍历二叉树*/
void PreOrderTraverse(BiTree T )
{
    if(T)
    {   /*递归结束条件，T为空*/
        printf("%3c",T->data);  /*访问根结点,将根结点内容输出*/
        PreOrderTraverse(T->lchild);  /*先序遍历T的左子树*/
        PreOrderTraverse(T->rchild);  /*先序遍历T的右子数*/
    }
}

void visit(BiTree p) 
{
	printf("%3c",p->data);
}

//队列实现层序打印二茶树
void layerOrderTraverse(BiTree T)
{
    BiTree p;
    queue<BiTree> q;
    if(T!=NULL)
    {
        q.push(T);//将根节点的指针指针入队列
        while(!q.empty())//队列不为空进入循环
        {
            p=q.front();//取出队头元素
            q.pop();//从队列中删除头元素
            visit(p);//访问p指向的节点

            if(p->lchild!=NULL)
                q.push(p->lchild);
            if(p->rchild!=NULL)
                q.push(p->rchild);
        }
    }
}

int main()
{
   BiTree T = NULL;  /*最开始T指向空*/
   printf("Input some characters to create a binary tree\n");
   CreatBiTree(&T);  /*创建二叉树*/
  
   printf("\nThe squence of layerorder traversaling binary tree\n");
   layerOrderTraverse(T); 
   getchar();
   getchar();

   return 0;
}