#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}ChainListType;

ChainListType *ChainListInsert(ChainListType *head,char *findkey,int data)  //插入结点到链表指定位置 
{
    ChainListType *node,*node1;    
    if(!(node=(ChainListType *)malloc(sizeof(ChainListType)))) //分配保存结点的内容 
    {
        printf("为保存结点数据申请内存失败！\n"); 
        return 0;  //分配内存失败 
    }
    node->data=data;  //保存结点中的数据 
    node1=ChainListFind(head,findkey);
    if(node1)  //若找到要插入的结点 
    {
        node->next=node1->next;  //新插入结点指向关键结点的下一结点 
        node1->next=node;    //设置关键结点指向新插入结点 
    }else{
        free(node);//释放内存
        printf("未找到插入位置！\n"); 
    }
    return head;//返回头指针
}
