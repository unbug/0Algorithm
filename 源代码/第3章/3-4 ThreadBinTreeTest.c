#include <stdio.h> 
#include "3-3 ThreadBinTree.c"
void oper(ThreadBinTree *p) //�����������������
{
     printf("%c ",p->data); //�������
     return;
}
ThreadBinTree *InitRoot()  //��ʼ���������ĸ� 
{
    ThreadBinTree *node;
    if(node=(ThreadBinTree *)malloc(sizeof(ThreadBinTree))) //�����ڴ�
    {
        printf("\n������������:");
        scanf("%s",&node->data);
        node->left=NULL;
        node->right=NULL;
        return BinTreeInit(node);
    }
    return NULL;
}
void AddNode(ThreadBinTree *bt)
{
     ThreadBinTree *node,*parent;
     DATA data;
     char select;
    if(node=(ThreadBinTree *)malloc(sizeof(ThreadBinTree))) //�����ڴ�
    {
        printf("\n����������������:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&node->data);
        node->left=NULL; //������������Ϊ�� 
        node->right=NULL;
        

        printf("���븸�������:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&data);
        parent=BinTreeFind(bt,data);//����ָ�����ݵĽ�� 
        if(!parent)//��δ�ҵ�ָ�����ݵĽ�� 
        {
            printf("δ�ҵ������!\n");
            free(node); //�ͷŴ����Ľ���ڴ� 
            return;
         }
         printf("1.��ӵ�������\n2.��ӵ�������\n");
         do{
            select=getch();
            select-='0';
            if(select==1 || select==2)
                BinTreeAddNode(parent,node,select); //��ӽ�㵽������ 
         }while(select!=1 && select!=2);
    }
    return ;
}
int main() 
{
    ThreadBinTree *root=NULL; //rootΪָ�������������ָ�� 
    char select;
    void (*oper1)(); //ָ������ָ�� 
    oper1=oper; //ָ���������ĺ��� 
    do{
        printf("\n1.���ö�������Ԫ��    2.��Ӷ��������\n");
        printf("3.������������������  4.��������������\n");
        printf("0.�˳�\n");
        select=getch();
        switch(select){
        case '1': //���ø�Ԫ�� 
             root=InitRoot();
             break;
        case '2': //��ӽ�� 
             AddNode(root);
             break;
        case '3'://������������������
             BinTreeThreading_LDR(root);
             printf("\n��������������������ϣ�\n");
             break;
        case '4'://������������������ 
             printf("\n�������������������Ľ����");
             ThreadBinTree_LDR(root,oper1);
             printf("\n");
             break;
        case '0':
             break;
        }
    }while(select!='0');
    BinTreeClear(root);//��ն����� 
    root=NULL;
    getch();
    return 0;
}
