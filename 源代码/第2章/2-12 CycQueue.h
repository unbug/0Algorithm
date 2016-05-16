//ѭ������ 
#define QUEUEMAX 15
typedef struct
{
    DATA data[QUEUEMAX]; //�������� 
    int head; //��ͷ 
    int tail; //��β 
}CycQueue;
CycQueue *CycQueueInit()
{
    CycQueue *q;
    if(q=(CycQueue *)malloc(sizeof(CycQueue))) //���뱣����е��ڴ� 
    {
        q->head = 0;//���ö�ͷ 
        q->tail = 0;//���ö�β 
        return q;
    }else
        return NULL; //���ؿ� 
}
void CycQueueFree(CycQueue *q) //�ͷŶ���
{
    if (q!=NULL)
        free(q);
} 
int CycQueueIsEmpty(CycQueue *q)  //�����Ƿ�Ϊ�� 
{
    return (q->head==q->tail);
}
int CycQueueIsFull(CycQueue *q)//�����Ƿ����� 
{
    return ((q->tail+1)%QUEUEMAX==q->head);
}
int CycQueueIn(CycQueue *q,DATA data)//��Ӻ���
{
    if((q->tail+1)%QUEUEMAX == q->head )
    { 
        printf("����������\n");
        return 0;
    }else{
        q->tail=(q->tail+1)%QUEUEMAX;//����β��� 
        q->data[q->tail]=data;
        return 1;
    }
}
DATA *CycQueueOut(CycQueue *q)//ѭ�����еĳ��Ӻ���
{
    if(q->head==q->tail) //����Ϊ�� 
    {
        printf("�����ѿգ�\n");
        return NULL;
    }else{
        q->head=(q->head+1)%QUEUEMAX;
        return &(q->data[q->head]);
    }
}
int CycQueueLen(CycQueue *q) //��ȡ���г��� 
{
    int n;
    n=q->tail-q->head;
    if(n<0)
        n=QUEUEMAX+n;
    return n;
}
DATA *CycQueuePeek(CycQueue *q) //��ȡ�Ӷ��е�1��λ�õ�����
{
    if(q->head==q->tail)
    {
        printf("�����Ѿ�Ϊ��!\n");
        return NULL; 
    }else{
        return &(q->data[(q->head+1)%QUEUEMAX]);
    }
} 
