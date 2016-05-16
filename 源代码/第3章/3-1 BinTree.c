#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //����Ԫ������ 
typedef struct ChainTree  //���������������� 
{
    DATA data;	//Ԫ������
    struct ChainTree *left;	//���������ָ��
    struct ChainTree *right;	//���������ָ��
}ChainBinTree;
ChainBinTree *BinTreeInit(ChainBinTree *node) //��ʼ������������� 
{
     if(node!=NULL) //������������㲻Ϊ�� 
         return node;
     else
         return NULL;
}
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n) //������ݵ������� 
//btΪ����㣬nodeΪ�ӽ��,n=1��ʾ�����������n=2��ʾ��������� 
{
    if(bt==NULL)
    {
        printf("����㲻���ڣ��������ø����!\n");
        return 0;
    } 
    switch(n)
    {
        case 1: //��ӵ����� 
            if(bt->left) //��������Ϊ�� 
            {
                printf("��������㲻Ϊ��!\n");
                return 0;
            }else
                bt->left=node;
            break;
        case 2://��ӵ��ҽ��
            if( bt->right) //��������Ϊ�� 
            {
                printf("��������㲻Ϊ��!\n"); 
                return 0;
            }else
                bt->right=node;
            break;
        default:
            printf("��������!\n");
            return 0;
    }
    return 1;
}
ChainBinTree *BinTreeLeft(ChainBinTree *bt) //�������ӽ�� 
{
    if(bt)
        return bt->left;
    else
        return NULL;
}
ChainBinTree *BinTreeRight(ChainBinTree *bt) //�������ӽ�� 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}
int BinTreeIsEmpty(ChainBinTree *bt) //���������Ƿ�Ϊ�գ�Ϊ���򷵻�1,���򷵻�0 
{
    if(bt)
        return 0;
    else
        return 1;
} 
int BinTreeDepth(ChainBinTree *bt) //����������
{
    int dep1,dep2;
    if(bt==NULL)
        return 0; //���ڿ��������Ϊ0
    else
    {
        dep1 = BinTreeDepth(bt->left); //��������� (�ݹ����)
        dep2 = BinTreeDepth(bt->right); //��������� (�ݹ����)
        if(dep1>dep2)
           return dep1 + 1; 
        else
            return dep2 + 1; 
    } 
} 
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data) //�ڶ������в���ֵΪdata�Ľ�� 
{
    ChainBinTree *p;
    if(bt==NULL)
        return NULL;
    else
    {
        if(bt->data==data)
            return bt; 
        else{ // �ֱ������������ݹ���� 
            if(p=BinTreeFind(bt->left,data))
                return p;
            else if(p=BinTreeFind(bt->right, data)) 
                return p;
            else
                return NULL; 
        } 
    } 
} 
void BinTreeClear(ChainBinTree *bt) // ��ն�������ʹ֮��Ϊһ�ÿ���
{
     if(bt)
     {
         BinTreeClear(bt->left); //��������� 
         BinTreeClear(bt->right);//��������� 
         free(bt);//�ͷŵ�ǰ�����ռ�ڴ� 
         bt=NULL;
     }
     return; 
}
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p))  //������� 
{     
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         oper(bt); //����������� 
         BinTree_DLR(bt->left,oper);
         BinTree_DLR(bt->right,oper);
     }
     return; 
} 
void BinTree_LDR(ChainBinTree *bt,void(*oper)(ChainBinTree *p))  //������� 
{
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         BinTree_LDR(bt->left,oper); //�������������
         oper(bt);//���������� 
         BinTree_LDR(bt->right,oper); //�������������/
     }
     return; 
} 
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p)) //�������
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //������������� 
         BinTree_LRD(bt->right,oper); //�������������/
         oper(bt); //����������
     }
     return; 
}

void oper(ChainBinTree *p) //����������������� 
{
     printf("%c ",p->data); //�������
     return;
}

void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)) //������� 
{
     ChainBinTree *p;
     ChainBinTree *q[QUEUE_MAXSIZE]; //����һ��˳��ջ 
     int head=0,tail=0;//���ס���β��� 
     if(bt)//������ָ�벻Ϊ��     
     {
         tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����ж�β��� 
         q[tail] = bt;//����������ָ�����
     }
     while(head!=tail) //���в�Ϊ�գ�����ѭ�� 
     {
         head=(head+1)%QUEUE_MAXSIZE; //����ѭ�����еĶ������ 
         p=q[head]; //��ȡ����Ԫ�� 
         oper(p);//�������Ԫ�� 
         if(p->left!=NULL) //������������������������ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->left;//��������ָ����� 
         }
                 
         if(p->right!=NULL)//���������Һ��ӣ����Һ��ӽ��ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->right;//��������ָ����� 
         }
     }
     return; 
}
