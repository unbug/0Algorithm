//循环队列 
#define QUEUEMAX 15
typedef struct
{
    DATA data[QUEUEMAX]; //队列数组 
    int head; //队头 
    int tail; //队尾 
}CycQueue;
CycQueue *CycQueueInit()
{
    CycQueue *q;
    if(q=(CycQueue *)malloc(sizeof(CycQueue))) //申请保存队列的内存 
    {
        q->head = 0;//设置队头 
        q->tail = 0;//设置队尾 
        return q;
    }else
        return NULL; //返回空 
}
void CycQueueFree(CycQueue *q) //释放队列
{
    if (q!=NULL)
        free(q);
} 
int CycQueueIsEmpty(CycQueue *q)  //队列是否为空 
{
    return (q->head==q->tail);
}
int CycQueueIsFull(CycQueue *q)//队列是否已满 
{
    return ((q->tail+1)%QUEUEMAX==q->head);
}
int CycQueueIn(CycQueue *q,DATA data)//入队函数
{
    if((q->tail+1)%QUEUEMAX == q->head )
    { 
        printf("队列已满！\n");
        return 0;
    }else{
        q->tail=(q->tail+1)%QUEUEMAX;//求列尾序号 
        q->data[q->tail]=data;
        return 1;
    }
}
DATA *CycQueueOut(CycQueue *q)//循环队列的出队函数
{
    if(q->head==q->tail) //队列为空 
    {
        printf("队列已空！\n");
        return NULL;
    }else{
        q->head=(q->head+1)%QUEUEMAX;
        return &(q->data[q->head]);
    }
}
int CycQueueLen(CycQueue *q) //获取队列长度 
{
    int n;
    n=q->tail-q->head;
    if(n<0)
        n=QUEUEMAX+n;
    return n;
}
DATA *CycQueuePeek(CycQueue *q) //获取队定中第1个位置的数据
{
    if(q->head==q->tail)
    {
        printf("队列已经为空!\n");
        return NULL; 
    }else{
        return &(q->data[(q->head+1)%QUEUEMAX]);
    }
} 
