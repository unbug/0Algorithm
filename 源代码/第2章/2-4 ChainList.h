#include <stdlib.h>
typedef struct Node
{
    DATA data;
    struct Node *next;
}ChainListType;
ChainListType *ChainListAddEnd(ChainListType *head,DATA data);  //添加结点到链表末尾 
ChainListType *ChainListAddFirst(ChainListType *head,DATA data);  //添加结点到链表首部 
ChainListType *ChainListFind(ChainListType *head,char *key); //按关键字在链表中查找内容 
ChainListType *ChainListInsert(ChainListType *head,char *findkey,DATA data);  //插入结点到链表指定位置 
int ChainListDelete(ChainListType *head,char *key);//删除指定关键字的结点 
int ChainListLength(ChainListType *head);//获取链表结点数量 
