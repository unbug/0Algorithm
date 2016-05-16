#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    int num; //顾客编号 
    long time;//进入队列时间 
}DATA;
#include "2-9 CycQueue.h"
int num;//顾客序号 
void add(CycQueue *q) //新增顾客排列 
{
    DATA data;
    if(!CycQueueIsFull(q)) //如果队列未满
    {
        data.num=++num;
        data.time=time(NULL);
        CycQueueIn(q,data);
    }
    else
        printf("\n排队的人太多，请稍候再排队!\n"); 
}
void next(CycQueue *q) //通知下一顾客准备 
{
    DATA *data;
    if(!CycQueueIsEmpty(q)) //若队列不为空 
    {
        data=CycQueueOut(q); //取队列头部的数据 
        printf("\n请编号为%d的顾客办理业务!\n",data->num);
    }
    if(!CycQueueIsEmpty(q)) //若队列不为空 
    {
        data=CycQueuePeek(q);//取队列中指定位置的数据 
        printf("请编号为%d的顾客准备，马上将为您理业务!\n",data->num);      
    }
}
int main()
{
    CycQueue *queue1;
    int i,n;
    char select;
    num=0;//顾客序号 
    queue1=CycQueueInit(); //初始化队列 
    if(queue1==NULL)
    {
        printf("创建队列时出错！\n");
        getch();
        return 0;
    }
    do{
        printf("\n请选择具体操作:\n");
        printf("1.新到顾客\n");
        printf("2.下一个顾客\n");
        printf("0.退出\n") ;
        fflush(stdin);
        select=getch();
        switch(select)
        {
            case '1':
                add(queue1);
                printf("\n现在共有%d位顾客在等候!\n",CycQueueLen(queue1));
                break;
            case '2':
                next(queue1);
                printf("\n现在共有%d位顾客在等候!\n",CycQueueLen(queue1));
                break;
            case '0':
                break;
        }        
    }while(select!='0');
    CycQueueFree(queue1); //释放队列
    getch();
    return 0;
}
