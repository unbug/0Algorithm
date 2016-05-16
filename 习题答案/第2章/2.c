#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}ChainListType;

ChainListType *ChainListInsert(ChainListType *head,char *findkey,int data)  //�����㵽����ָ��λ�� 
{
    ChainListType *node,*node1;    
    if(!(node=(ChainListType *)malloc(sizeof(ChainListType)))) //���䱣��������� 
    {
        printf("Ϊ���������������ڴ�ʧ�ܣ�\n"); 
        return 0;  //�����ڴ�ʧ�� 
    }
    node->data=data;  //�������е����� 
    node1=ChainListFind(head,findkey);
    if(node1)  //���ҵ�Ҫ����Ľ�� 
    {
        node->next=node1->next;  //�²�����ָ��ؼ�������һ��� 
        node1->next=node;    //���ùؼ����ָ���²����� 
    }else{
        free(node);//�ͷ��ڴ�
        printf("δ�ҵ�����λ�ã�\n"); 
    }
    return head;//����ͷָ��
}
