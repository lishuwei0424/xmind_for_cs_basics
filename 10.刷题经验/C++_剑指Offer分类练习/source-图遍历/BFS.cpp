#include "stdio.h"
#include "malloc.h"

#define MAX_VERTEX_NUM 8

typedef struct ArcNode{
	/*单链表中的结点的类型*/
	int  adjvex;				/*该边指向的顶点在顺序表中的位置*/
	struct ArcNode  *next;		/*下一条边*/
}ArcNode;

typedef struct VNode{
	/*顶点类型*/
	int  data;					/*顶点中的数据信息*/
	ArcNode  *firstarc;			/*指向单链表，即指向第一条边*/
}VNode;

typedef struct QNode{
	int data;			//链队列结点中的数据域
	struct QNode *next;		//链队列结点中的指针域
} QNode , *QueuePtr;

typedef struct{
	QueuePtr front;		//队头指针
	QueuePtr rear;		//队尾指针
}LinkQueue;

int visited[MAX_VERTEX_NUM]={0,0,0,0,0};

void CreatGraph(int n , VNode G[] ){
   int i,e;
   ArcNode *p , *q;
   printf("Input the information of the vertex\n");
   for(i=0;i<n;i++){
       scanf("%d",&G[i]);
       G[i].firstarc = NULL;							/*初始化第一条边为空*/
   }
   for(i=0;i<n;i++){
   printf("Creat the edges for the %dth vertex\n",i) ;
   scanf("%d",&e);
    while(e!=-1){
      p = (ArcNode *)malloc(sizeof(ArcNode));		/*创建一条边*/
      p->next = NULL;
      p->adjvex = e;
      if(G[i].firstarc == NULL) G[i].firstarc = p;	/*i结点的第一条边*/
      else q->next = p;								/*下一条边*/
      q = p;
      scanf("%d",&e);
      }
   }
}

void initQueue(LinkQueue *q){
	/*初始化一个空队列*/
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	/*创建一个头结点，队头队尾指针指向该结点*/
	if( !q->front) return;		/*创建头结点失败*/
	q->front->next = NULL;		/*头结点指针域置NULL*/
}

void EnQueue(LinkQueue *q, int e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));		/*创建一个队列元素结点*/
	if(p==NULL)return;							/*创建元素结点失败*/
	p->data = e;				/*将数据e存放到队列结点的data域中*/
	p->next = NULL;				/*指针域置NULL*/
	q->rear ->next = p;			/*从队尾插入结点*/
	q->rear = p;				/*修改队尾指针*/
}

void DeQueue(LinkQueue *q, int *e){
	/*如果队列q不为空，删除q的队头元素，用e返回其值*/
	QueuePtr p;
	if(q->front == q->rear) return;	   /*队列为空，返回*/
	p = q->front->next;					   /*p指向队列的第一个元素*/
	*e = p->data;						   /*将队首元素的数据赋值给e返回*/
	q->front->next = p->next;			   /*删除头结点*/
	if(q->rear == p) q->rear = q->front;  /*如果此时队列为空，则修改队尾指针*/
	free(p);
}

int emptyQ(LinkQueue q) {
	if (q.rear == q.front) {
		return 1;
	}
	return 0;
}

void BFS(VNode G[],int v){
   int w;
   LinkQueue q;
   initQueue(&q);

   printf("%d ",G[v]);		/*访问顶点v*/
   visited[v] = 1;			/*将顶点v对应的访问标记置1*/
   EnQueue(&q,v);			/*顶点v入队列*/
   while(!emptyQ(q)){
      DeQueue(&q, &v);		/*出队列，元素由v返回*/
      w = FirstAdj(G, v);	/*找到顶点v的第一个邻接点，如果无邻接点，返回-1*/
      while(w != -1){
			 if(visited[w] == 0) {
				   printf("%d ",G[w]);
				   EnQueue(&q,w);		/*顶点w入队列*/
				   visited[w] = 1;
			 }
			 w = NextAdj(G, v, w);	/*找到顶点v的下一个邻接点，如果无邻接点，返回-1*/
      }
   }
}

void Travel_BFS(VNode G[], int n){
   int i;
   for(i=0;i<n;i++)
      visited[i] = 0;		/*将标记数组初始化为0*/
   for(i=0;i<n;i++)
     if(visited[i] == 0)		/*若有顶点未被访问，从该顶点开始继续广度优先搜索*/
        BFS(G,i);
}


void resetVisitedTrace() {
	int i;
	for (i=0; i<MAX_VERTEX_NUM; i++) {
		visited[i] = 0;
	}
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