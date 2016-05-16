#include <stdio.h>
#define ARRAYLEN 10
int source[]={54,90,6,69,12,37,92,28,65,83};
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
//ɾ�����
void BST_Delete(BSTree *t,int key)
{
    BSTree *p,*parent,*l,*l1;
    int child=0;//0��ʾ��������1��ʾ������ 
    if(!t) return;     //����������Ϊ�գ����˳�
    p=t;
    parent=p;
    while(p)           //������������Ч 
    {        
        if(p->data==key)
        {
            if(!p->left && !p->right) //Ҷ���(����������Ϊ��) 
            {
                if(p==t) //��ɾ�����Ǹ���� 
                {
                    free(p);//�ͷű�ɾ����� 
                }
                else if(child==0) //�����Ϊ������ 
                {
                    parent->left=NULL; //���ø����������Ϊ�� 
                    free(p); //�ͷŽ��ռ� 
                }
                else //�����Ϊ������ 
                {
                    parent->right=NULL; //���ø����������Ϊ�� 
                    free(p); //�ͷŽ��ռ� 
                }
            }
            else if(!p->left) //������Ϊ�գ���������Ϊ��
            {
                if(child==0) //�Ǹ�����������
                    parent->left=p->right;
                else //�Ǹ�����������             
                    parent->left=p->left;
                free(p); //�ͷű�ɾ�����
            }
            else if(!p->right)//������Ϊ�գ���������Ϊ��
            {
                 if(child==0) //�Ǹ�����������
                    parent->right=p->right;
                else //�Ǹ�����������             
                    parent->right=p->left;
                free(p); //�ͷű�ɾ�����       
            }
            else  //������������Ϊ�� 
            {
                l1=p; //�����������ĸ���� 
                l=p->right; //�ӵ�ǰ�������������в��� 
                while(l->left) //��������Ϊ�� 
                {
                    l1=l;
                    l=l->left; //���������� 
                }
                p->data=l->data; //�������������ݱ��浽��ɾ�����
                l1->left=NULL; //���ø�����������ָ��Ϊ�� 
                free(l1); //�ͷ�������ռ���ڴ�ռ�
            }
            p=NULL;
        }
        else if(key<p->data) //��ɾ����¼�Ĺؼ���С�ڽ������� 
        {
            child=0;//����ڵ�ǰ�������������
            parent=p; //���浱ǰ���������� 
            p=p->left; //���������� 
        }
        else //��ɾ����¼�Ĺؼ��ִ��ڽ������� 
        {
            child=1;//����ڵ�ǰ�������������
            parent=p;//���浱ǰ���������� 
            p=p->right; //���������� 
        }    
    } 
}
int main()
{
    int i,key;
    BSTree bst,*pos; //������������������
    printf("ԭ����:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",source[i]);
    printf("\n");
    CreateBST(&bst,source,ARRAYLEN);
    printf("��������������:"); 
    BST_LDR(&bst);
    BST_Delete(&bst,37);
    printf("\nɾ������Ľ��:"); 
    BST_LDR(&bst);    
    printf("\n������ؼ���:");
    scanf("%d",&key); 
   pos=SearchBST(&bst,key);
    if(pos)
       printf("���ҳɹ����ý��ĵ�ַ��%x\n",pos);
    else
        printf("����ʧ��!\n");
    getch();
    return 0;
}
