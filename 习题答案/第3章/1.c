int sum;    //����˳Ҷ�ӽ������� 

int DLR(tree *root)     //�������
{
    if(root!=NULL)
    {
        if((root->lchild==NULL) && (root->rchild==NULL))
        {
            sum++;
            printf("%d\n",root->data);
        }
        DLR(root->lchild);
        DLR(root->rchild);
    }
    return 0;
}
