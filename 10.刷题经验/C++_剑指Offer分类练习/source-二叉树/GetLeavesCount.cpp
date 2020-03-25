
#include "string.h" 
#include "stdio.h" 
#include "malloc.h"

typedef struct BiTNode{
    char data;   /*结点的数据域*/
    struct BiTNode *lchild , *rchild;  /*指向左孩子和右孩子*/
} BiTNode , *BiTree;

void CreatBiTree(BiTree *T){
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

//方法1
void getLeavesConut (BiTree T,int *count){
    if(T!=NULL && T->lchild==NULL && T->rchild==NULL){   /*访问到叶结点*/
        *count = *count + 1;
    }
    if(T){
        getLeavesConut (T->lchild,count);  /*先序遍历T的左子树*/
        getLeavesConut (T->rchild,count);  /*先序遍历T的右子数*/
    }
}

int getBiTreeLeavesCount(BiTree T) {
	int count = 0;				/*在主调函数中定义变量count，初始值为0*/
	getLeavesConut(T, &count);	/*调用递归函数getLeavesConut计算叶子结点个数*/
	return count;				/*返回叶子结点个数*/
}

//方法2
int getLeavesCount(BiTree T)
{
    int leftLeavesCount;
    int rightLeavesCount;
    if(T==NULL)
    {
        return 0;
    }

    else if(T->lchild==NULL && T->rchild==NULL)
        return 1;

    else
    {
        leftLeavesCount=getLeavesCount(T->lchild);
        rightLeavesCount=getLeavesCount(T->rchild);

        return leftLeavesCount+rightLeavesCount;
    }
}

main()
{
   BiTree T = NULL;				/*初始化T */
   int count = 0;
   printf("Input some characters to create a binary tree \n");
   CreatBiTree(&T);				/*创建一棵二叉树*/
   getLeavesConut (T,&count);	/*计算二叉树中叶子结点的个数 */
   printf("The number of leaves of BTree are %d\n",count);
   getchar();
   getchar();
}