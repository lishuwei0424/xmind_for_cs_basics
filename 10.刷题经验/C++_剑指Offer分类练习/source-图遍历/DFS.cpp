//图的深度优先搜索
//从图的一个顶点出发，依次访问图的未访问的邻接顶点，如果访问过啦，则回退到上一顶点，继续访问

#include <isotream>
using namespace std;

#define Max_vertex_num 8

//单链表中节点类型
typedef struct ArcNode
{
    int adjex;//该边指向的顶点在顺序表中的位置（数组下标）
    struct ArcNode *next;//指向下一条边的指针

}ArcNode;

//定义图的节点
typedef struct VNode
{
    //顶点类型
    int data;
    //指向单链表，即指向第一条边
    ArcNode *firstarc;
}VNode;

//创建一队列
typedef struct QNode
{
    int data;
    struct QNode *next;

}QNode,*QueuePtr;

typedef struct
{
    //对头指针
    QueuePtr front;
    //对尾指针
    QueuePtr rear;
}LinkQueue;

//定义访问数组
int visited[Max_vertex_num]={0,0,0,0,0};

//创建图
void CreatGraph(int n,VNode G[])
{
    int i,e;
    ArcNode *p,*q;
    printf("Input vertex");
    for(i=0;i<n;i++)
    {
        cin>>G[i];
        //初始化第一条边为空
        G[i].firstarc=NULL;
    }

    for(i=0;i<n;i++)
    {
        printf("creat edge");
        cin>>e;
        while(e!=-1)
        {
           //创建一条边
           p=(ArcNode*)malloc(sizeof(ArcNode));
           p->next=NULL;
           p->adjvex=e;

           if(G[i].firstarc==NULL)
                G[i].firstarc=p;//i节点的第一条边
            else
                q->next=p;//下一条边
            q=p;
            cin>>e;
        }
    }

}

//开始深度优先

//返回第一邻节点在数组中的下表
int FirstAdj(VNode G[],int v)
{
    if(G[v].firstarc!=NULL)
            return (G[v].firstarc)->adjvex;

    return -1;
}

//返回下一个邻节点在数组中的下表
int NextAdj(VNode G[],int v,int w)
{
    ArcNode *p;
    p=G[v].firstarc;
    while(p!=NULL)
    {
        if(p->adjvex==w && p->next!=NULL)
            return p->next->adjvex;

        p=p->next;
    }

    return -1;
}

void DFS(VNode G[],int v){
   int w;
   printf("%d ",G[v]);		/*访问当前顶点,打印出该顶点中的数据信息*/
    visited[v] = 1;			/*将顶点v对应的访问标记置1*/
    w = FirstAdj(G,v);		/*找到顶点v的第一个邻接点，如果无邻接点，返回-1*/
    while(w != -1){
    if(visited[w] == 0)		/*该顶点未被访问*/
        DFS(G,w);			/*递归地进行深度优先搜索*/
		w = NextAdj(G,v,w);	/*找到顶点v的下一个邻接点，如果无邻接点，返回-1*/
    }
}

void Travel_DFS(VNode G[], int n){
   int i;
   for(i=0;i<n;i++)
      visited[i] = 0;		/*将标记数组初始化为0*/
   for(i=0;i<n;i++)
     if(visited[i] == 0)		/*若有顶点未被访问，从该顶点开始继续深度优先搜索*/
        DFS(G,i);
}


main()
{
    VNode G[MAX_VERTEX_NUM];
    CreatGraph(MAX_VERTEX_NUM,G);
	printf("DFS trace is\n");
	Travel_DFS(G,MAX_VERTEX_NUM);
	resetVisitedTrace();
	printf("\nBFS trace is\n");
	Travel_BFS(G,MAX_VERTEX_NUM);
    getchar();
	getchar();
}
