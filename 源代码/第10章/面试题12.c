#include "stdio.h"

typedef struct node{
	int id;	
	int key;
	struct node *next ;
}LNode,*LinkList;

void CreatRing(LinkList *list,int n)
{
	LinkList p,r;
	int e;
	int i;
	if(n<=0)
		return;
	scanf("%d",&e); 
	r = *list = (LinkList) malloc(sizeof(LNode)); 
	(*list)->next = *list;
	(*list)->key = e;
	(*list)->id = 1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&e);
        p=(LinkList)malloc(sizeof(LNode));
        p->key = e;
		p->id = i;
		p->next = *list;
		r->next = p;
		r = r->next;
	}
}

int main()
{
	LinkList list=NULL,p=NULL,q=NULL;
	int n,m,i;
	printf("������������");
	scanf("%d",&n);
	printf("����ÿ���˵����룺");
	CreatRing(&list,n);
	printf("���뱨������ֵ��");
	scanf("%d",&m);
	printf("���е�˳��Ϊ��");

	q = p = list;
	while(q->next!=list)
		q = q->next;
	while(p!=q)
	{
		for(i=0;i<m-1;i++)
		{
			p = p->next;
			q = q->next;
		}
		printf("%3d",p->id);
		m = p->key;	
		q->next = p->next;
		free(p);
		p = q->next;
	}
	printf("%3d",p->id);
	free(p);
	list = p = q = NULL;
	printf("\n");
	getch();
	return 0;
}