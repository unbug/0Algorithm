#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//˳����в��� 
#define QUEUEMAX 15
#define COUNT 5

typedef struct{
   char name[20];
   char sex;  //�Ա�'F'��ʾŮ�ԣ�'M'��ʾ����
}Person;
typedef Person DATA;  //��������Ԫ�ص��������͸�ΪPerson

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

//�ṹ����dancer�д���������Ů��num�������������
void DancePartner(Person dancer[],int num)
{
    int i;
    DATA *p,p1;
    SeqQueue *Mdancers,*Fdancers;
    Mdancers=SeqQueueInit();//��ʿ���г�ʼ��
    Fdancers=SeqQueueInit();//Ůʿ���г�ʼ��
    for(i=0;i<num;i++)//�������������Ա����
    {
         p1=dancer[i];       
         if(p1.sex=='F' || p1.sex=='f')
             SeqQueueIn(Fdancers,p1);   //����Ů��
         else
             SeqQueueIn(Mdancers,p1);   //�����ж�
     }
     printf("\n����������: \n \n");
     while(!SeqQueueIsEmpty(Fdancers)&&!SeqQueueIsEmpty(Mdancers))
     {
           //����������Ů�����
           p=SeqQueueOut(Fdancers);     //Ůʿ����
           printf("%s --> ",p->name);//��ӡ����Ůʿ��
           p=SeqQueueOut(Mdancers);     //��ʿ����
           printf("%s\n",p->name);    //��ӡ������ʿ��
     }
     if(!SeqQueueIsEmpty(Fdancers)){ //���Ůʿʣ����������ͷŮʿ������
           printf("\n ���� %d λŮʿ�ڵȴ���һ����\n",SeqQueueLen(Fdancers));
           p=SeqQueuePeek(Fdancers);  //ȡ��ͷ
           printf("%s �����������顣 \n",p->name);
      }else
          if(!SeqQueueIsEmpty(Mdancers)){//����ж�ʣ����������ͷ������
                 printf("\n���� %d λ��ʿ�ڵȴ���һ����\n",SeqQueueLen(Mdancers));
                 p=SeqQueuePeek(Mdancers);
                 printf("%s �����������顣\n",p->name);
           }
}

int main()
{
    Person dancer[COUNT];
    int num=0,i;
    for(i=0;i<COUNT;i++)
    {
        printf("\n����������:");
        gets(&dancer[i].name);
        printf("�������Ա�(FΪŮ��,MΪ����):");
        dancer[i].sex=getch();
        printf("%c\n",dancer[i].sex);
        num++;
    }
    DancePartner(dancer,num) ;
    getch();   
    return 0;    
}
