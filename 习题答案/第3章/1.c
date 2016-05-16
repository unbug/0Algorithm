int sum;    //保存顺叶子结点的数量 

int DLR(tree *root)     //中序遍历
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
