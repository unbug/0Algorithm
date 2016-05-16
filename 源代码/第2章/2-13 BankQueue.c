#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    int num; //�˿ͱ�� 
    long time;//�������ʱ�� 
}DATA;
#include "2-9 CycQueue.h"
int num;//�˿���� 
void add(CycQueue *q) //�����˿����� 
{
    DATA data;
    if(!CycQueueIsFull(q)) //�������δ��
    {
        data.num=++num;
        data.time=time(NULL);
        CycQueueIn(q,data);
    }
    else
        printf("\n�Ŷӵ���̫�࣬���Ժ����Ŷ�!\n"); 
}
void next(CycQueue *q) //֪ͨ��һ�˿�׼�� 
{
    DATA *data;
    if(!CycQueueIsEmpty(q)) //�����в�Ϊ�� 
    {
        data=CycQueueOut(q); //ȡ����ͷ�������� 
        printf("\n����Ϊ%d�Ĺ˿Ͱ���ҵ��!\n",data->num);
    }
    if(!CycQueueIsEmpty(q)) //�����в�Ϊ�� 
    {
        data=CycQueuePeek(q);//ȡ������ָ��λ�õ����� 
        printf("����Ϊ%d�Ĺ˿�׼�������Ͻ�Ϊ����ҵ��!\n",data->num);      
    }
}
int main()
{
    CycQueue *queue1;
    int i,n;
    char select;
    num=0;//�˿���� 
    queue1=CycQueueInit(); //��ʼ������ 
    if(queue1==NULL)
    {
        printf("��������ʱ����\n");
        getch();
        return 0;
    }
    do{
        printf("\n��ѡ��������:\n");
        printf("1.�µ��˿�\n");
        printf("2.��һ���˿�\n");
        printf("0.�˳�\n") ;
        fflush(stdin);
        select=getch();
        switch(select)
        {
            case '1':
                add(queue1);
                printf("\n���ڹ���%dλ�˿��ڵȺ�!\n",CycQueueLen(queue1));
                break;
            case '2':
                next(queue1);
                printf("\n���ڹ���%dλ�˿��ڵȺ�!\n",CycQueueLen(queue1));
                break;
            case '0':
                break;
        }        
    }while(select!='0');
    CycQueueFree(queue1); //�ͷŶ���
    getch();
    return 0;
}
