#include <iostream>
using namespace std;

typedef struct BiTNode{
    char data;   /*结点的数据域*/
    struct BiTNode *lchild , *rchild;  /*指向左孩子和右孩子*/
} BiTNode , *BiTree;

/*创建一棵二叉树*/
void CreatBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else
    {
       *T = (BiTNode * )malloc(sizeof(BiTNode));  /*创建根结点*/
        (*T)->data = c;    /*向根结点中输入数据*/
        CreatBiTree(&((*T)->lchild));  /*递归地创建左子树*/
        CreatBiTree(&((*T)->rchild));  /*递归地创建右子树*/
    }
}

/*计算二叉树的深度*/
//方法1
int getBitreeDepth(BiTree T)
{
   int leftHeight, rightHeight, maxHeight;
   if (T != NULL) 
   {
	   leftHeight = getBitreeDepth(T->lchild);
	   rightHeight = getBitreeDepth(T->rchild);
	   maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;
	   return maxHeight+1;
   } 
   else 
   {
		return 0;
   }
}


//方法2
void getDepth(BiTree T,int n,int *level)
{
    //递归遍历二叉树，用变量level记录下二叉树的最深节点的深度
    if(T!=NULL)
    {
        if(n>*level)//较大的深度值赋值给level
            *level=n;

        getDepth(T->lchild,n+1,level);//
        getDepth(T->rchild,n+1,level);
    }
}

int getBitreeDepth(BiTree T)
{
    int level=0;
    int n=1;
    getDepth(T,n,&level);
    return level;
}

main()
{
    BiTree T = NULL;    /*最开始T指向空*/
    printf("Input some characters to create a binary tree \n");
    CreatBiTree(&T);    /*创建二叉树*/
    printf("\nThe depth of the binary tree is %d\n",getBitreeDepth(T));
    getchar() ;
	getchar() ;
}