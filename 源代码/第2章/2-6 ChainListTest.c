#include <stdio.h>
typedef struct
{
    char key[15];	//关键字
    char name[20];
    int age;
}DATA; 	//数据结点类型 
#include "2-4 ChainList.h"
#include "2-5 ChainList.c"
void ChainListAll(ChainListType *head) //遍历链表 
{
    ChainListType *h;
    DATA data;
    h=head;
    printf("链表所有数据如下：\n"); 
    while(h) //循环处理链表每个结点 
    {
        data=h->data;//获取结点数据 
        printf("(%s,%s,%d)\n",data.key,data.name,data.age); 
        h=h->next;//处理下一结点 
    }
    return;
}
int main()
{
    ChainListType *node, *head=NULL;
    DATA data;
    char key[15],findkey[15];
    
    printf("输入链表中的数据，包括关键字、姓名、年龄，关键字输入0，则退出：\n"); 
    do{
        fflush(stdin);  //清空输入缓冲区 
        scanf("%s",data.key);
        if(strcmp(data.key,"0")==0) break; //若输入0，则退出
        scanf("%s%d",data.name,&data.age);
        head=ChainListAddEnd(head,data);//在链表尾部添加结点数据 
    }while(1);
    
    printf("该链表共有%d个结点。\n",ChainListLength(head)); //返回结点数量 
    ChainListAll(head); //显示所有结点
 
    printf("\n插入结点，输入插入位置的关键字：") ;
    scanf("%s",&findkey);//输入插入位置关键字 
    printf("输入插入结点的数据(关键字 姓名 年龄):");
    scanf("%s%s%d",data.key,data.name,&data.age);//输入插入结点数据 
    head=ChainListInsert(head,findkey,data);//调用插入函数 
    
    ChainListAll(head); //显示所有结点
    
    printf("\n在链表中查找，输入查找关键字:");
    fflush(stdin);//清空输入缓冲区 
    scanf("%s",key);//输入查找关键字 
    node=ChainListFind(head,key);//调用查找函数，返回结点指针 
    if(node)//若返回结点指针有效 
    {
        data=node->data;//获取结点的数据 
        printf("关键字%s对应的结点数据为(%s,%s,%d)\n" ,key,data.key,data.name,data.age);        
    }else//若结点指针无效 
        printf("在链表中未找到关键字为%s的结点！\n",key); 
    
    printf("\n在链表中删除结点，输入要删除的关键字:");
    fflush(stdin);//清空输入缓冲区 
    scanf("%s",key);//输入删除结点关键字 
    ChainListDelete(head,key); //调用删除结点函数 
    ChainListAll(head); //显示所有结点   
    getch();
    return 0;
}
