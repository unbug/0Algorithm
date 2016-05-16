#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//顺序队列操作 
#define QUEUEMAX 15
#define COUNT 5

typedef struct{
   char name[20];
   char sex;  //性别，'F'表示女性，'M'表示男性
}Person;
typedef Person DATA;  //将队列中元素的数据类型改为Person

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

//结构数组dancer中存放跳舞的男女，num是跳舞的人数。
void DancePartner(Person dancer[],int num)
{
    int i;
    DATA *p,p1;
    SeqQueue *Mdancers,*Fdancers;
    Mdancers=SeqQueueInit();//男士队列初始化
    Fdancers=SeqQueueInit();//女士队列初始化
    for(i=0;i<num;i++)//将跳舞者依其性别入队
    {
         p1=dancer[i];       
         if(p1.sex=='F' || p1.sex=='f')
             SeqQueueIn(Fdancers,p1);   //排入女队
         else
             SeqQueueIn(Mdancers,p1);   //排入男队
     }
     printf("\n舞伴配对如下: \n \n");
     while(!SeqQueueIsEmpty(Fdancers)&&!SeqQueueIsEmpty(Mdancers))
     {
           //依次输入男女舞伴名
           p=SeqQueueOut(Fdancers);     //女士出队
           printf("%s --> ",p->name);//打印出队女士名
           p=SeqQueueOut(Mdancers);     //男士出队
           printf("%s\n",p->name);    //打印出队男士名
     }
     if(!SeqQueueIsEmpty(Fdancers)){ //输出女士剩余人数及队头女士的名字
           printf("\n 还有 %d 位女士在等待下一曲。\n",SeqQueueLen(Fdancers));
           p=SeqQueuePeek(Fdancers);  //取队头
           printf("%s 将首先配对舞伴。 \n",p->name);
      }else
          if(!SeqQueueIsEmpty(Mdancers)){//输出男队剩余人数及队头者名字
                 printf("\n还有 %d 位男士在等待下一曲。\n",SeqQueueLen(Mdancers));
                 p=SeqQueuePeek(Mdancers);
                 printf("%s 将首先配对舞伴。\n",p->name);
           }
}

int main()
{
    Person dancer[COUNT];
    int num=0,i;
    for(i=0;i<COUNT;i++)
    {
        printf("\n请输入姓名:");
        gets(&dancer[i].name);
        printf("请输入性别(F为女性,M为男性):");
        dancer[i].sex=getch();
        printf("%c\n",dancer[i].sex);
        num++;
    }
    DancePartner(dancer,num) ;
    getch();   
    return 0;    
}
