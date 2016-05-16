#include "stdio.h"

typedef struct node{
        int data; 
        struct node *next ;
}LNode,*LinkList;

void GreatLinkList(LinkList *list,int n)    //����һ������Ϊn������
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

void  printlinklist(LinkList list)         //��ӡ������list�е�����*/
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
    printf("���� %d ��������������:\n",len);
    GreatLinkList(&list,len);		//����һ������10�����ĵ�����
    printf("����������:\n");
    printlinklist(list);
    printf("\n");
    reverse(list);
    printf("���ú������:\n");
    printlinklist(list);
    printf("\n");
    getche();
    return 0;
}