#include <stdio.h>
#include <string.h>
#define MAXSIZE 100  //�������Ա����󳤶�

typedef struct    //����˳���ṹ
{
    DATA ListData[MAXSIZE+1]; //����˳�������� 
    int ListLen;              //˳����Ѵ��� ������ 
}SeqListType;

void SeqListInit(SeqListType *SL); //��ʼ��˳���
int SeqListLength(SeqListType *SL);  //����˳����Ԫ������ 
int SeqListAdd(SeqListType *SL,DATA data); //��˳��������Ԫ�� 
int SeqListInsert(SeqListType *SL,int n,DATA data); //��˳����в���Ԫ�� 
int SeqListDelete(SeqListType *SL,int n);  //ɾ��˳����еľ�Ԫ�� 
DATA *SeqListFindByNum(SeqListType *SL,int n);  //������ŷ���Ԫ��
int SeqListFindByCont(SeqListType *SL,char *key); //���ؼ��ֲ��� 
int SeqListAll(SeqListType *SL);//����˳����е����� 
