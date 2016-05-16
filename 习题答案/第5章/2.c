#include <stdio.h>
#define MAX 15

int source[]={75, 85, 7, 13, 9, 10, 19,91, 21, 37, 56, 64, 80, 33, 88};

typedef struct bst
{
    int data;
    struct bst *left;
    struct bst * right;
}BSTree;

void InsertBST(BSTree *t,int key)//在二叉排序树中插入查找关键字key
{
    BSTree *p,*parent,*head;
    if(!(p=(BSTree *)malloc(sizeof(BSTree *)))) //申请内存空间 
    {
        printf("申请内存出错!\n");
        exit(0); 
    }
    p->data=key; //保存结点数据 
    p->left=p->right=NULL; //左右子树置空    
    head=t;
    while(head) //查找需要添加的父结点 
    {
        parent=head;
        if(key<head->data) //若关键字小于结点的数据 
            head=head->left; //在左子树上查找 
        else                 //若关键字大于结点的数据 
            head=head->right;  //在右子树上查找                             
    }
    //判断添加到左子树还是右子树 
    if(key<parent->data) //小于父结点 
        parent->left=p; //添加到左子树
    else           //大于父结点 
        parent->right=p; //添加到右子树 
}

void CreateBST(BSTree *t,int data[],int n)//n个数据在数组d中，tree为二叉排序树根
{
    int i;
    t->data=data[0];
    t->left=t->right=NULL;
    for(i=1;i<n;i++)
    {
        InsertBST(t,data[i]);
    }
}
void BST_LDR(BSTree *t)  //中序遍历 
{
     if(t)//树不为空，则执行如下操作 
     {
         BST_LDR(t->left); //中序遍历左子树
         printf("%d ",t->data); //输出结点数据 
         BST_LDR(t->right); //中序遍历右子树/
     }
     return; 
} 

int main()
{
    BSTree bst; //保存二叉排序树根结点

    CreateBST(&bst,source,MAX);
    printf("遍历二叉排序树:"); 
    BST_LDR(&bst);

    getch();
    return 0;
}