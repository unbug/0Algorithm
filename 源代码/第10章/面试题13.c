#include "stdio.h"

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild , *rchild;
} BNode , *BTree;

void CreatBTree(BTree *T)
{
    char c;
    scanf("%c",&c);
    if(' '==c) 
        *T = NULL;
    else
    {
        *T = (BNode * )malloc(sizeof(BNode)); 
        (*T)->data = c;
        CreatBTree(&((*T)->lchild));
        CreatBTree(&((*T)->rchild));
    }
}

void DLR(BTree T )  //ǰ����� 
{
    if(T)
    {
        printf("%3c",T->data);
        DLR(T->lchild);
        DLR(T->rchild);
    }
}

void LDR(BTree T)//�������
{
    if(T)
    {
        LDR(T->lchild); 
        printf("%3c",T->data);
        LDR(T->rchild);
    }
}

void LRD(BTree T)//�������
{
    if(T)
    {
        LRD(T->lchild);
        LRD(T->rchild);
        printf("%3c",T->data);
    }
}

int main()
{
   BTree T = NULL;	
   printf("���봴�����������ַ�����");
   CreatBTree(&T); 
   printf("\nǰ�������������");
   DLR(T);
   printf("\n���������������");
   LDR(T);
   printf("\n���������������");
   LRD(T);
   getche();
   return 0;
}