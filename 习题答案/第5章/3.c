#include <stdio.h>
#define MAX 15

int source[]={75, 85, 7, 13, 9, 10, 19,91, 21, 37, 56, 64, 80, 33, 88};

typedef struct bst
{
    int data;
    struct bst *left;
    struct bst * right;
}BSTree;

void InsertBST(BSTree *t,int key)//�ڶ����������в�����ҹؼ���key
{
    BSTree *p,*parent,*head;
    if(!(p=(BSTree *)malloc(sizeof(BSTree *)))) //�����ڴ�ռ� 
    {
        printf("�����ڴ����!\n");
        exit(0); 
    }
    p->data=key; //���������� 
    p->left=p->right=NULL; //���������ÿ�    
    head=t;
    while(head) //������Ҫ��ӵĸ���� 
    {
        parent=head;
        if(key<head->data) //���ؼ���С�ڽ������� 
            head=head->left; //���������ϲ��� 
        else                 //���ؼ��ִ��ڽ������� 
            head=head->right;  //���������ϲ���                             
    }
    //�ж���ӵ����������������� 
    if(key<parent->data) //С�ڸ���� 
        parent->left=p; //��ӵ�������
    else           //���ڸ���� 
        parent->right=p; //��ӵ������� 
}

BSTree *SearchBST(BSTree *t,int key)
{
    if(!t || t->data==key) //���Ϊ�գ���ؼ������ 
        return t;          //���ؽ��ָ��
    else if(key>t->data) //�ؼ��ִ��ڽ������
        return(SearchBST(t->right,key));
    else
        return(SearchBST(t->left,key));
}

void CreateBST(BSTree *t,int data[],int n)//n������������d�У�treeΪ������������
{
    int i;
    t->data=data[0];
    t->left=t->right=NULL;
    for(i=1;i<n;i++)
    {
        InsertBST(t,data[i]);
    }
}

void BST_LDR(BSTree *t)  //������� 
{
     if(t)//����Ϊ�գ���ִ�����²��� 
     {
         BST_LDR(t->left); //�������������
         printf("%d ",t->data); //���������� 
         BST_LDR(t->right); //�������������/
     }
     return; 
} 

int main()
{
    int key;
    BSTree bst,*pos; //������������������

    CreateBST(&bst,source,MAX);

    printf("\n������ؼ���:");
    scanf("%d",&key);
    
    pos=SearchBST(&bst,key);
    if(pos)
       printf("���ҳɹ����ý��ĵ�ַ��%x\n",pos);
    else
        printf("����ʧ�ܣ��޴˹ؼ���!\n");
    
    getch();
    return 0;
}