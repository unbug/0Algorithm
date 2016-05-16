#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //����Ԫ������ 
typedef enum 
{
    SubTree,
    Thread
}NodeFlag;  //ö��ֵSubTree(����)��Thread(����)�ֱ�Ϊ0��1
typedef struct ThreadTree  //��������������������� 
{
    DATA data;	//Ԫ������
    NodeFlag lflag; //���־ 
    NodeFlag rflag; //�ұ�־ 
    struct ThreadTree *left;	//���������ָ��
    struct ThreadTree *right;	//���������ָ��
}ThreadBinTree;

ThreadBinTree *Previous=NULL;     //ǰ�����ָ�� 

ThreadBinTree *BinTreeInit(ThreadBinTree *node) //��ʼ������������� 
{
     if(node!=NULL) //������������㲻Ϊ�� 
         return node;
     else
         return NULL;
}
int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) //������ݵ������� 
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
ThreadBinTree *BinTreeLeft(ThreadBinTree *bt) //�������ӽ�� 
{
    if(bt)
        return bt->left;
    else
        return NULL;
}
ThreadBinTree *BinTreeRight(ThreadBinTree *bt) //�������ӽ�� 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}
int BinTreeIsEmpty(ThreadBinTree *bt) //���������Ƿ�Ϊ�գ�Ϊ���򷵻�1,���򷵻�0 
{
    if(bt)
        return 0;
    else
        return 1;
} 
int BinTreeDepth(ThreadBinTree *bt) //����������
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
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data) //�ڶ������в���ֵΪdata�Ľ�� 
{
    ThreadBinTree *p;
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
void BinTreeClear(ThreadBinTree *bt) // ��ն�������ʹ֮��Ϊһ�ÿ���
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
void BinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p))  //������� 
{     
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         oper(bt); //����������� 
         BinTree_DLR(bt->left,oper);
         BinTree_DLR(bt->right,oper);
     }
     return; 
} 
void BinTree_LDR(ThreadBinTree *bt,void(*oper)(ThreadBinTree *p))  //������� 
{
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         BinTree_LDR(bt->left,oper); //�������������
         oper(bt);//���������� 
         BinTree_LDR(bt->right,oper); //�������������/
     }
     return; 
} 
void BinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //�������
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //������������� 
         BinTree_LRD(bt->right,oper); //�������������/
         oper(bt); //����������
     }
     return; 
} 
void BinTree_Level(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //������� 
{
     ThreadBinTree *p;
     ThreadBinTree *q[QUEUE_MAXSIZE]; //����һ��˳��ջ 
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
void BinTreeThreading_LDR(ThreadBinTree *bt)     //������������������
{
    if(bt) //���ǿ�ʱ����ǰ���ʽ��
    {
        BinTreeThreading_LDR(bt->left); //�ݹ���ã���������������
        bt->lflag=(bt->left)?SubTree:Thread; //������ָ����ı�־
        bt->rflag=(bt->right)?SubTree:Thread;//������ָ����ı�־
        if(Previous) //����ǰ����ǰ��Previous����
        {
            if(Previous->rflag==Thread) //����ǰ����ǰ���ұ�־Ϊ����
                Previous->right=bt;//��Previous��������ָ����
            if(bt->lflag==Thread) //����ǰ�������־Ϊ����
                bt->left=Previous;//�赱ǰ����������ָ������ǰ�� 
        }
        Previous=bt;//��Previous����շ��ʵĽ��
        BinTreeThreading_LDR(bt->right);//�ݹ���ã���������������
    }
}
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt) //��ָ�����ĺ�� 
{
    ThreadBinTree *nextnode;
    if(!bt) return NULL; //����ǰ���Ϊ�գ��򷵻ؿ� 
    if(bt->rflag==Thread) //����ǰ����������Ϊ��
        return bt->right; //������������ָ��������
    else{
        nextnode=bt->right; //�ӵ�ǰ������������ʼ����
        while(nextnode->lflag==SubTree) //ѭ������������������Ϊ�յĽ��
            nextnode=nextnode->left;
        return nextnode; //�������·��Ľ��
    }
}
ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt) //��ָ������ǰ�� 
{
    ThreadBinTree *prenode;
    if(!bt) return NULL; //����ǰ���Ϊ�գ��򷵻ؿ� 
    if(bt->lflag==Thread) //����ǰ����������Ϊ��
        return bt->left; //������������ָ��������
    else{
        prenode=bt->left; //�ӵ�ǰ������������ʼ����
        while(prenode->rflag==SubTree) //ѭ������������������Ϊ�յĽ��
            prenode=prenode->left;
        return prenode; //�������·��Ľ��
    }
}

void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //������������������
{
    if(bt) //��������Ϊ��
    {
        while(bt->lflag==SubTree)//�������� 
            bt=bt->left; //�Ӹ������������½�㣬���������еĿ�ʼ���
        do{
           oper(bt); //������ 
           bt=BinTreeNext_LDR(bt);//�������̽��
        }while(bt);
    }
}
