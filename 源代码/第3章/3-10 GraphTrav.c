#include <stdio.h>
#include "3-6 AdjMatrixGraph.c"
#define QUEUE_MAXSIZE 30 //队列的最大容量 
typedef struct
{
    int Data[QUEUE_MAXSIZE]; //数据域
    int head; //队头指针
    int tail; //队尾指针
}SeqQueue; //队列结构
//队列操作函数 
void QueueInit(SeqQueue *q); //初始化一个队列   
int QueueIsEmpty(SeqQueue q); //判断队列是否空   
int QueueIn(SeqQueue *q,int n); //将一个元素入队列   
int QueueOut(SeqQueue *q,int *ch); //将一个元素出队列  

//图操作函数 
void DFSTraverse(MatrixGraph *G); //深度优先遍历 
void BFSTraverse(MatrixGraph *G); //广度优先遍历 
void DFSM(MatrixGraph *G,int i);
void BFSM(MatrixGraph *G,int i);

void QueueInit(SeqQueue *Q)    //队列初始化  
{
    Q->head=Q->tail=0;
}
int QueueIsEmpty(SeqQueue Q)   //判断队列是否已空，若空返回1,否则返回0 
{
    return Q.head==Q.tail; 
}
int QueueIn(SeqQueue *Q,int ch)   //入队列，成功返回1，失败返回0   
{
    if((Q->tail+1) % QUEUE_MAXSIZE ==Q->head) //若队列已满 
        return 0;  //返回错误; 
    Q->Data[Q->tail]=ch; //将数据ch入队列 
    Q->tail=(Q->tail+1) % QUEUE_MAXSIZE; //调整队尾指针 
    return 1; //成功，返回1 
}
int QueueOut(SeqQueue *Q,int *ch)   //出队列,成功返回1，并用ch返回该元素值，失败返回0  
{
    if(Q->head==Q->tail) //若队列为空 
        return 0; //返回错误 
    *ch=Q->Data[Q->head]; //返回队首元素 
    Q->head=(Q->head+1) % QUEUE_MAXSIZE; //调整队首指针 
    return 1; //成功出队列，返回1   
}   

void DFSTraverse(MatrixGraph *G) //深度优先遍历 
{
    int i;
    for(i=0;i<G->VertexNum;i++) //清除各顶点遍历标志 
        G->isTrav[i]=0;
    printf("深度优先遍历结点:"); 
    for(i=0;i<G->VertexNum;i++)
        if(!G->isTrav[i]) //若该点未遍历 
            DFSM(G,i); //调用函数遍历 
    printf("\n"); 

}
void DFSM(MatrixGraph *G,int i) //从第i个结点开始，深度遍历图 
{
    int j;
    G->isTrav[i]=1; //标记该顶点已处理过 
    printf("->%c",G->Vertex[i]);//输出结点数据 
//    printf("%d->",i); //输出结点序号 

    //添加处理节点的操作 
    for(j=0;j<G->VertexNum;j++)
        if(G->Edges[i][j]!=MAXVALUE && !G->isTrav[i])
            DFSM(G,j); //递归进行遍历 
}
void BFSTraverse(MatrixGraph *G) //广度优先 
{
    int i;
    for (i=0;i<G->VertexNum;i++) //清除各顶点遍历标志 
        G->isTrav[i]=0;
    printf("广度优先遍历结点:"); 
    for (i=0;i<G->VertexNum;i++)
        if (!G->isTrav[i])
            BFSM(G,i);
    printf("\n");
}
void BFSM(MatrixGraph *G,int k) //广度优先遍历 
{
    int i,j;
    SeqQueue Q; //创建循环队列 
    QueueInit(&Q); //初始化循环队列 

    G->isTrav[k]=1; //标记该顶点 
    printf("->%c",G->Vertex[k]);  //输出第一个顶点 

    //添加处理节点的操作 
    QueueIn(&Q,k); //入队列 
    while (!QueueIsEmpty(Q)) //队列不为空 
    {
        QueueOut(&Q,&i); //出队列 
        for (j=0;j<G->VertexNum;j++)
            if(G->Edges[i][j]!=MAXVALUE && !G->isTrav[j])
            {
                printf("->%c",G->Vertex[j]);
                G->isTrav[j]=1;  //标记该顶点
                //处理顶点 
                QueueIn(&Q,j); //出队列 
            }
    }
}

