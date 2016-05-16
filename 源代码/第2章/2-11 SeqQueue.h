//顺序队列操作 
#define QUEUEMAX 15
typedef struct
{
    DATA data[QUEUEMAX]; //队列数组 
    int head; //队头 
    int tail; //队尾 
}SeqQueue;
SeqQueue *SeqQueueInit()
{
    SeqQueue *q;
    if(q=(SeqQueue *)malloc(sizeof(SeqQueue))) //申请保存队列的内存 
    {
        q->head = 0;//设置队头 
        q->tail = 0;//设置队尾 
        return q;
    }else
        return NULL; //返回空 
}
void SeqQueueFree(SeqQueue *q) //释放队列
{
    if (q!=NULL)
        free(q);
} 
int SeqQueueIsEmpty(SeqQueue *q)  //队列是否为空 
{
    return (q->head==q->tail);
}
int SeqQueueIsFull(SeqQueue *q)//队列是否已满 
{
    return (q->tail==QUEUEMAX);
}
int SeqQueueLen(SeqQueue *q) //获取队列长度 
{
    return(q->tail-q->head);
}
int SeqQueueIn(SeqQueue *q,DATA data)//顺序队列的入队函数
{
    if(q->tail==QUEUEMAX)
    { 
        printf("队列已满！\n");
        return(0);
    }else{
        q->data[q->tail++]=data;
        return(1);
    }
}
DATA *SeqQueueOut(SeqQueue *q)//顺序队列的出队
{
    if(q->head==q->tail)
    {
        printf("\n队列已空！\n");
        return NULL;
    }else{
        return &(q->data[q->head++]);
    }
}
DATA *SeqQueuePeek(SeqQueue *q) //获取队头元素
{
    if(SeqQueueIsEmpty(q))
    {
        printf("\n队列为空!\n");
        return NULL; 
    }else{
        return &(q->data[q->head]);
    }
} 
