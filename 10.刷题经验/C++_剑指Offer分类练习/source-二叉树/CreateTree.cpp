#include <iostream>
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;

}BiTNode,*BiTree;

void CreatBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if(c==' ') *T=NULL;
    else
    {
        *T=(BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data=c;
        CreatBiTree(&((*T)->lchild));
        CreatBiTree(&((*T)->rchild));

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

void InOrderTraverse(BiTree T)
{
	if(T)
    {   /*如果二叉树为空，递归遍历结束*/
		InOrderTraverse(T->lchild);  /*中序遍历T的左子树*/ 
		printf("%3c",T->data);       /*访问根结点*/
		InOrderTraverse(T->rchild);  /*中序遍历T的右子数*/
	}
}

void PosOrderTraverse(BiTree T)
{
	if(T)
    {   /*如果二叉树为空，递归遍历结束*/
		PosOrderTraverse(T->lchild);  /*后序遍历T的左子树*/ 
		PosOrderTraverse(T->rchild);  /*后序遍历T的右子数*/
		printf("%3c",T->data);        /*访问根结点*/
	}
}



int main()
{
   BiTree T = NULL;  /*最开始T指向空*/
   printf("Input some characters to create a binary tree\n");
   CreatBiTree(&T);  /*创建二叉树*/
   printf("The squence of preorder traversaling binary tree\n");
   PreOrderTraverse(T); /*先序遍历二叉树*/
   printf("\nThe squence of inorder traversaling binary tree\n");
   InOrderTraverse(T);  /*中序遍历二叉树*/
   printf("\nThe squence of posorder traversaling binary tree\n");
   PosOrderTraverse(T); /*后序遍历二叉树*/
   getchar();
   getchar();

   return 0;
}