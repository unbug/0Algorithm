#include <stdio.h>
#include <string.h>
#define MAXSIZE 100  //定义线性表的最大长度

typedef struct    //定义顺序表结构
{
    DATA ListData[MAXSIZE+1]; //保存顺序表的数组 
    int ListLen;              //顺序表已存结点 的数量 
}SeqListType;

void SeqListInit(SeqListType *SL); //初始化顺序表
int SeqListLength(SeqListType *SL);  //返回顺序表的元素数量 
int SeqListAdd(SeqListType *SL,DATA data); //向顺序表中添加元素 
int SeqListInsert(SeqListType *SL,int n,DATA data); //向顺序表中插入元素 
int SeqListDelete(SeqListType *SL,int n);  //删除顺序表中的据元素 
DATA *SeqListFindByNum(SeqListType *SL,int n);  //根据序号返回元素
int SeqListFindByCont(SeqListType *SL,char *key); //按关键字查找 
int SeqListAll(SeqListType *SL);//遍历顺序表中的内容 
