#include <string.h>
ChainListType *ChainListAddEnd(ChainListType *head,DATA data)  //��ӽ�㵽�����β 
{
    ChainListType *node,*h;
    if(!(node=(ChainListType *)malloc(sizeof(ChainListType))))
    {
        printf("Ϊ���������������ڴ�ʧ�ܣ�\n"); 
        return NULL;  //�����ڴ�ʧ�� 
    }
    node->data=data; //�������� 
    node->next=NULL;  //���ý��ָ��Ϊ�գ���Ϊ��β 
    if(head==NULL)  //��ͷָ�� 
    {
        head=node;
        return head;
    }
    h=head;
    while(h->next!=NULL) //���������ĩβ 
        h=h->next ;
    h->next=node;
    return head;
}
ChainListType *ChainListAddFirst(ChainListType *head,DATA data) 
{
    ChainListType *node,*h;
    if(!(node=(ChainListType *)malloc(sizeof(ChainListType))))
    {
        printf("Ϊ���������������ڴ�ʧ�ܣ�\n"); 
        return NULL;  //�����ڴ�ʧ�� 
    }
    node->data=data; //�������� 
    node->next=head;  //ָ��ͷָ����ָ��� 
    head=node;        //ͷָ��ָ���������
    return head; 
}
ChainListType *ChainListInsert(ChainListType *head,char *findkey,DATA data)  //�����㵽����ָ��λ�� 
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
ChainListType *ChainListFind(ChainListType *head,char *key) //���ؼ����������в������� 
{
    ChainListType *h;
    h=head;       //��������ͷָ�� 
    while(h)      //�������Ч������в��� 
    {
        if(strcmp(h->data.key,key)==0) //�����ؼ����봫��ؼ�����ͬ 
            return h;  //���ظý��ָ�� 
        h=h->next; //������һ��� 
    }
    return NULL; //���ؿ�ָ�� 
}
int ChainListDelete(ChainListType *head,char *key)
{
    ChainListType *node,*h; //node����ɾ������ǰһ��� 
    node=h=head;    
    while(h)
    {
        if(strcmp(h->data.key,key)==0) //�ҵ��ؼ��֣�ִ��ɾ������ 
        {
            node->next=h->next;  //ʹǰһ���ָ��ǰ������һ���
            free(h);  //�ͷ��ڴ� 
            return 1;
        }else{
            node=h;  //ָ��ǰ��� 
            h=h->next; //ָ����һ��� 
        }
     }
     return 0;//δɾ�� 
}
int ChainListLength(ChainListType *head)//��ȡ���������� 
{
    ChainListType *h;
    int i=0;
    h=head;
    while(h)      //������������ 
    {
        i++; //�ۼӽ������ 
        h=h->next;//������һ��� 
    }
    return i;//���ؽ������ 
}
