#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //����Ԫ������ 

typedef struct ChainTree  //���������������� 
{
    DATA data;	//Ԫ������
    struct ChainTree *left;	//���������ָ��
    struct ChainTree *right;	//���������ָ��
}ChainBinTree;

void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)) //������� 
{
     ChainBinTree *p;
     ChainBinTree *q[QUEUE_MAXSIZE]; //����һ��˳��ջ 
     int head=0,tail=0;//���ס���β��� 
     if(bt)//������ָ�벻Ϊ��     
     {
         tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����ж�β��� 
         q[tail] = bt;//����������ָ�����
     }
     while(head!=tail) //���в�Ϊ�գ�����ѭ�� 
     {
         head=(head+1)%QUEUE_MAXSIZE; //����ѭ�����еĶ������ 
         p=q[head]; //��ȡ����Ԫ�� 
         oper(p);//�������Ԫ�� 
         if(p->left!=NULL) //������������������������ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->left;//��������ָ����� 
         }
                 
         if(p->right!=NULL)//���������Һ��ӣ����Һ��ӽ��ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->right;//��������ָ����� 
         }
     }
     return; 
}
