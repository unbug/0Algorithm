//˳����в��� 
#define QUEUEMAX 15
typedef struct
{
    DATA data[QUEUEMAX]; //�������� 
    int head; //��ͷ 
    int tail; //��β 
}SeqQueue;
SeqQueue *SeqQueueInit()
{
    SeqQueue *q;
    if(q=(SeqQueue *)malloc(sizeof(SeqQueue))) //���뱣����е��ڴ� 
    {
        q->head = 0;//���ö�ͷ 
        q->tail = 0;//���ö�β 
        return q;
    }else
        return NULL; //���ؿ� 
}
void SeqQueueFree(SeqQueue *q) //�ͷŶ���
{
    if (q!=NULL)
        free(q);
} 
int SeqQueueIsEmpty(SeqQueue *q)  //�����Ƿ�Ϊ�� 
{
    return (q->head==q->tail);
}
int SeqQueueIsFull(SeqQueue *q)//�����Ƿ����� 
{
    return (q->tail==QUEUEMAX);
}
int SeqQueueLen(SeqQueue *q) //��ȡ���г��� 
{
    return(q->tail-q->head);
}
int SeqQueueIn(SeqQueue *q,DATA data)//˳����е���Ӻ���
{
    if(q->tail==QUEUEMAX)
    { 
        printf("����������\n");
        return(0);
    }else{
        q->data[q->tail++]=data;
        return(1);
    }
}
DATA *SeqQueueOut(SeqQueue *q)//˳����еĳ���
{
    if(q->head==q->tail)
    {
        printf("\n�����ѿգ�\n");
        return NULL;
    }else{
        return &(q->data[q->head++]);
    }
}
DATA *SeqQueuePeek(SeqQueue *q) //��ȡ��ͷԪ��
{
    if(SeqQueueIsEmpty(q))
    {
        printf("\n����Ϊ��!\n");
        return NULL; 
    }else{
        return &(q->data[q->head]);
    }
} 
