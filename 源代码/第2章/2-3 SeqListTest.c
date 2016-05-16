#include <stdio.h>
typedef struct
{
    char key[15];  //结点的关键字 
    char name[20];
    int age;
} DATA;    //定义结点类型，可定义为简单类型，也可定义为结构
#include "2-1 SeqList.h"
#include "2-2 SeqList.c"
int SeqListAll(SeqListType *SL)  //遍历顺序表中的结点 
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
        printf("(%s,%s,%d)\n",SL->ListData[i].key,SL->ListData[i].name,SL->ListData[i].age);
}
int main()
{
	int i;
    SeqListType SL;         //定义顺序表变量 
    DATA data,*data1;       //定义结点保存数据类型变量和指针变量 
    char key[15];           //保存关键字 

    SeqListInit(&SL);       //初始化顺序表 

    do {                    //循环添加结点数据 
        printf("输入添加的结点(学号 姓名 年龄)："); 
        fflush(stdin);              //清空输入缓冲区 
        scanf("%s%s%d",&data.key,&data.name,&data.age); 
        if(data.age)                                    //若年龄不为0 
        {
            if(!SeqListAdd(&SL,data))                   //若添加结点失败 
                break;                                  //退出死循环 
        }else   //若年龄为0 
            break;          //退出死循环 
    }while(1);
    printf("\n顺序表中的结点顺序为：\n");
    SeqListAll(&SL);                     //显示所有结点数据 
    
    fflush(stdin);                       //清空输入缓冲区 
    printf("\n要取出结点的序号：");
    scanf("%d",&i);                 //输入结占点序号    
    data1=SeqListFindByNum(&SL,i);  //按序号查找结点 
    if(data1)                       //若返回的结点指针不为NULL 
        printf("第%d个结点为：(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);
    
    fflush(stdin);                                                             //清空输入缓冲区 
    printf("\n要查找结点的关键字：");
    scanf("%s",key);  //输入关键字     
    i=SeqListFindByCont(&SL,key);      //按关键字查找 ，返回结点序号 
    data1=SeqListFindByNum(&SL,i);     //按序号查询，返回结点指针 
    if(data1)                          //若结点指针不为NULL 
        printf("第%d个结点为：(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);           
  	getch();
	return 0;
}

