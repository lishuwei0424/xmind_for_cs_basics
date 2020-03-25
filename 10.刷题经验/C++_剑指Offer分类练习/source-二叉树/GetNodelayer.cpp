
#include "stdio.h"

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

int getNodelayer (BiTree T,int level,char key) 
{
    int l;
	if(T) 
    {   
		if(T->data == key) 
        {
			return level;	/*找到与key值相同的结点，将层数level返回*/
		}  

		l = getNodelayer (T->lchild,level+1,key);  /*在左子树中查找key结点，并得到其层数*/
		if(l != -1)
         {
			return l;
		} 
        else 
        {
			/*在右子树中查找key结点，并得到其层数*/
			return getNodelayer (T->rchild,level+1,key) ;	   
		}		
    }
    return -1;	/*T为NULL，返回-1*/
}


int getBiTreeNodeLayer(BiTree T, char key)
 {
	int level = 1;
	return getNodelayer(T,level,key);
}
main()
{
   BiTree T = NULL;  /*最开始T指向空*/
   char key;
   int level;
   printf("Input some characters to create a binary tree \n");
   CreatBiTree(&T);  /*创建二叉树*/
   getchar();
   printf("Input the node element in this bitree \n");
   scanf("%c", &key);
   level = getBiTreeNodeLayer(T,key);
   if (level != -1) {
	   printf("The element %c is in the level %d in this bitree\n", key,level);
   } else {
		printf("There is no element %c is in this bitree\n",key);
   }
   getchar();
   getchar();
}