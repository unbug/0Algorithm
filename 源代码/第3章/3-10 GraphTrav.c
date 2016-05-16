#include <stdio.h>
#include "3-6 AdjMatrixGraph.c"
#define QUEUE_MAXSIZE 30 //���е�������� 
typedef struct
{
    int Data[QUEUE_MAXSIZE]; //������
    int head; //��ͷָ��
    int tail; //��βָ��
}SeqQueue; //���нṹ
//���в������� 
void QueueInit(SeqQueue *q); //��ʼ��һ������   
int QueueIsEmpty(SeqQueue q); //�ж϶����Ƿ��   
int QueueIn(SeqQueue *q,int n); //��һ��Ԫ�������   
int QueueOut(SeqQueue *q,int *ch); //��һ��Ԫ�س�����  

//ͼ�������� 
void DFSTraverse(MatrixGraph *G); //������ȱ��� 
void BFSTraverse(MatrixGraph *G); //������ȱ��� 
void DFSM(MatrixGraph *G,int i);
void BFSM(MatrixGraph *G,int i);

void QueueInit(SeqQueue *Q)    //���г�ʼ��  
{
    Q->head=Q->tail=0;
}
int QueueIsEmpty(SeqQueue Q)   //�ж϶����Ƿ��ѿգ����շ���1,���򷵻�0 
{
    return Q.head==Q.tail; 
}
int QueueIn(SeqQueue *Q,int ch)   //����У��ɹ�����1��ʧ�ܷ���0   
{
    if((Q->tail+1) % QUEUE_MAXSIZE ==Q->head) //���������� 
        return 0;  //���ش���; 
    Q->Data[Q->tail]=ch; //������ch����� 
    Q->tail=(Q->tail+1) % QUEUE_MAXSIZE; //������βָ�� 
    return 1; //�ɹ�������1 
}
int QueueOut(SeqQueue *Q,int *ch)   //������,�ɹ�����1������ch���ظ�Ԫ��ֵ��ʧ�ܷ���0  
{
    if(Q->head==Q->tail) //������Ϊ�� 
        return 0; //���ش��� 
    *ch=Q->Data[Q->head]; //���ض���Ԫ�� 
    Q->head=(Q->head+1) % QUEUE_MAXSIZE; //��������ָ�� 
    return 1; //�ɹ������У�����1   
}   

void DFSTraverse(MatrixGraph *G) //������ȱ��� 
{
    int i;
    for(i=0;i<G->VertexNum;i++) //��������������־ 
        G->isTrav[i]=0;
    printf("������ȱ������:"); 
    for(i=0;i<G->VertexNum;i++)
        if(!G->isTrav[i]) //���õ�δ���� 
            DFSM(G,i); //���ú������� 
    printf("\n"); 

}
void DFSM(MatrixGraph *G,int i) //�ӵ�i����㿪ʼ����ȱ���ͼ 
{
    int j;
    G->isTrav[i]=1; //��Ǹö����Ѵ���� 
    printf("->%c",G->Vertex[i]);//���������� 
//    printf("%d->",i); //��������� 

    //��Ӵ���ڵ�Ĳ��� 
    for(j=0;j<G->VertexNum;j++)
        if(G->Edges[i][j]!=MAXVALUE && !G->isTrav[i])
            DFSM(G,j); //�ݹ���б��� 
}
void BFSTraverse(MatrixGraph *G) //������� 
{
    int i;
    for (i=0;i<G->VertexNum;i++) //��������������־ 
        G->isTrav[i]=0;
    printf("������ȱ������:"); 
    for (i=0;i<G->VertexNum;i++)
        if (!G->isTrav[i])
            BFSM(G,i);
    printf("\n");
}
void BFSM(MatrixGraph *G,int k) //������ȱ��� 
{
    int i,j;
    SeqQueue Q; //����ѭ������ 
    QueueInit(&Q); //��ʼ��ѭ������ 

    G->isTrav[k]=1; //��Ǹö��� 
    printf("->%c",G->Vertex[k]);  //�����һ������ 

    //��Ӵ���ڵ�Ĳ��� 
    QueueIn(&Q,k); //����� 
    while (!QueueIsEmpty(Q)) //���в�Ϊ�� 
    {
        QueueOut(&Q,&i); //������ 
        for (j=0;j<G->VertexNum;j++)
            if(G->Edges[i][j]!=MAXVALUE && !G->isTrav[j])
            {
                printf("->%c",G->Vertex[j]);
                G->isTrav[j]=1;  //��Ǹö���
                //������ 
                QueueIn(&Q,j); //������ 
            }
    }
}

