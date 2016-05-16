typedef struct
{
    char key[15];	//关键字(设置姓名为关键字)
    char addr[20];
    char telephone[15];
    char mobile[12];
}DATA; 	//数据结点类型 
#include <stdio.h>
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
        printf("姓名:%s\n",data.key);
        printf("地址:%s\n",data.addr);
        printf("电话:%s\n",data.telephone);
        printf("手机:%s\n",data.mobile);
        h=h->next;//处理下一结点 
    }
    return;
}
ChainListType *input(ChainListType *head) //向通讯录中输入的信息
{
    DATA data;
    printf("请输入联系人信息\n");
    printf("姓名:");
    scanf("%s",data.key);
    printf("地址:");
    scanf("%s",data.addr);
    printf("电话:");
    scanf("%s",data.telephone);
    printf("手机:");
    scanf("%s",data.mobile);
    return ChainListAddFirst(head,data); //调用添加函数 
}
void find(ChainListType *head)
{
    ChainListType *h;
    DATA data;
    char name[15];
    printf("请输入查找姓名:");
    scanf("%s",name);
    h=ChainListFind(head,name);
    if(h)//查找结点指针有效
    { 
        data=h->data;//获取结点数据 
        printf("姓名:%s\n",data.key);
        printf("地址:%s\n",data.addr);
        printf("电话:%s\n",data.telephone);
        printf("手机:%s\n",data.mobile);    
    }
}
void delete(ChainListType *head)
{
    ChainListType *h=head;
    char name[15];
    printf("请输入要删除的姓名:");
    scanf("%s",name);
    ChainListDelete(head,name); 
}
int main()
{
    ChainListType *node, *head=NULL;
    int select;//选择菜单的序号 
    do{
        printf("\n_____________________\n");
        printf("1.添加联系人\n");
        printf("2.查找联系人\n");
        printf("3.删除联系人\n"); 
        printf("4.显示所有联系人\n"); 
        printf("0.退出\n");
        printf("_____________________\n");
        select=getch();
        switch(select) 
        {
            case '1':
                printf("\n添加联系人\n"); 
                head=input(head);
                break;
            case '2':
                 printf("\n查找联系人\n"); 
                 find(head);
                 break;
           case '3':
                printf("\n删除联系人\n"); 
                delete(head);
                break;
           case '4':
                printf("\n显示联系人\n"); 
                ChainListAll(head);
                break;
           case '0':
                return 0;
        }
    }while(select != '0');
}
