#include "stdio.h"

typedef struct node{
        int data; 
        struct node *next ;
}LNode,*LinkList;

void GreatLinkList(LinkList *list,int n)    //建立一个长度为n的链表
{    
    LinkList p,r;
    int e;
    int i;
    r = *list = (LinkList) malloc(sizeof(LNode));
    (*list)->next = NULL;
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=e;
        p->next=NULL;
            r->next=p;
        r=p;
    }
}

void reverse(LinkList list)
{
    LinkList p,q,r;
    if(list == NULL)
    {
        printf("This linklist is NULL!\n");
        return;
    }
    p = list->next;
    q = p->next;

    p->next = NULL;
    while(q!=NULL)
    {
       r = q->next;
       q->next = p;
       p = q;
       q = r;
    }
    list->next = p;
}

void  printlinklist(LinkList list)         //打印出链表list中的内容*/
{    
    list = list->next;
    while(list != NULL)
    {
        printf("%3d",list->data);
        list = list->next;
    }
}

int main()
{
    LinkList list;
    int len=10;
    printf("输入 %d 个整数创建链表:\n",len);
    GreatLinkList(&list,len);		//创建一个包含10个结点的单链表
    printf("创建的链表:\n");
    printlinklist(list);
    printf("\n");
    reverse(list);
    printf("逆置后的链表:\n");
    printlinklist(list);
    printf("\n");
    getche();
    return 0;
}