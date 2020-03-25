/*------------------------------------------------- 17-8.c  -------------------------------------------*/
#include "stdio.h"
#include "malloc.h"
#include "string.h"

typedef struct BiTNode
{
    int data;   /*结点的数据域*/
    struct BiTNode *lchild;
    struct BiTNode *rchild;  /*指向左孩子和右孩子*/
} BiTNode , *BiTree;

int findLowestCommonAncestor(BiTree T,int value1, int value2) 
{
	BiTree curNode = T;  /*curNode为当前访问结点，初始化为T*/
	if(T->data == value1 || T->data == value2) {
		return -1;    /*value1和value2有一个为根结点，因此没有公共祖先，返回-1*/
	}
	while(curNode != NULL)
    {
		if (curNode->data > value1 &&
			curNode->data > value2 && curNode->lchild->data != value1 &&
			curNode->lchild->data != value2) 
            {
/*当前结点的值同时大于value1和value2，且不是value1和value2的父结点*/
				curNode = curNode->lchild;  
		}
         else if (curNode->data < value1 &&
			curNode->data < value2 && curNode->rchild->data != value1 &&
			curNode->rchild->data != value2) 
            {
/*当前结点的值同时小于value1和value2，且不是value1和value2的父结点*/
				curNode = curNode->rchild;
		}
         else 
         {
			return curNode->data;	/*找到最低公共祖先*/
		}
	}
}

void CreatBiTree(BiTree *T){
    int d;
    scanf("%d",&d);
    if(d == 0) *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));  /*创建根结点*/
        (*T)->data = d;    /*向根结点中输入数据*/
        CreatBiTree(&((*T)->lchild));  /*递归地创建左子树*/
        CreatBiTree(&((*T)->rchild));  /*递归地创建右子树*/
    }
}

main()
{
	BiTree T;
	int value1,value2;
	int ancestorValue;
	printf("Please create a binary sort tree\n");
	CreatBiTree(&T);
	printf("Input two values for searching lowest common ancestor\n");
	scanf("%d,%d",&value1,&value2);
	ancestorValue = findLowestCommonAncestor(T,value1,value2);
	if (ancestorValue != -1) {
		printf("The  lowest common ancestor is %d\n", ancestorValue);
	} else {
		printf("There is no ancestor\n");
	}
	getchar();
}