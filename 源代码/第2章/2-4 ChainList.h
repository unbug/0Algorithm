#include <stdlib.h>
typedef struct Node
{
    DATA data;
    struct Node *next;
}ChainListType;
ChainListType *ChainListAddEnd(ChainListType *head,DATA data);  //��ӽ�㵽����ĩβ 
ChainListType *ChainListAddFirst(ChainListType *head,DATA data);  //��ӽ�㵽�����ײ� 
ChainListType *ChainListFind(ChainListType *head,char *key); //���ؼ����������в������� 
ChainListType *ChainListInsert(ChainListType *head,char *findkey,DATA data);  //�����㵽����ָ��λ�� 
int ChainListDelete(ChainListType *head,char *key);//ɾ��ָ���ؼ��ֵĽ�� 
int ChainListLength(ChainListType *head);//��ȡ���������� 
