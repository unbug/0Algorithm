#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //定义元素类型 
typedef struct ChainTree  //定义二叉树结点类型 
{
    DATA data;	//元素数据
    struct ChainTree *left;	//左子树结点指针
    struct ChainTree *right;	//右子树结点指针
}ChainBinTree;
ChainBinTree *BinTreeInit(ChainBinTree *node) //初始化二叉树根结点 
{
     if(node!=NULL) //若二叉树根结点不为空 
         return node;
     else
         return NULL;
}
int BinTreeAddNode(ChainBinTree *bt,ChainBinTree *node,int n) //添加数据到二叉树 
//bt为父结点，node为子结点,n=1表示添加左子树，n=2表示添加右子树 
{
    if(bt==NULL)
    {
        printf("父结点不存在，请先设置父结点!\n");
        return 0;
    } 
    switch(n)
    {
        case 1: //添加到左结点 
            if(bt->left) //左子树不为空 
            {
                printf("左子树结点不为空!\n");
                return 0;
            }else
                bt->left=node;
            break;
        case 2://添加到右结点
            if( bt->right) //右子树不为空 
            {
                printf("右子树结点不为空!\n"); 
                return 0;
            }else
                bt->right=node;
            break;
        default:
            printf("参数错误!\n");
            return 0;
    }
    return 1;
}
ChainBinTree *BinTreeLeft(ChainBinTree *bt) //返回左子结点 
{
    if(bt)
        return bt->left;
    else
        return NULL;
}
ChainBinTree *BinTreeRight(ChainBinTree *bt) //返回右子结点 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}
int BinTreeIsEmpty(ChainBinTree *bt) //检查二叉树是否为空，为空则返回1,否则返回0 
{
    if(bt)
        return 0;
    else
        return 1;
} 
int BinTreeDepth(ChainBinTree *bt) //求二叉树深度
{
    int dep1,dep2;
    if(bt==NULL)
        return 0; //对于空树，深度为0
    else
    {
        dep1 = BinTreeDepth(bt->left); //左子树深度 (递归调用)
        dep2 = BinTreeDepth(bt->right); //右子树深度 (递归调用)
        if(dep1>dep2)
           return dep1 + 1; 
        else
            return dep2 + 1; 
    } 
} 
ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data) //在二叉树中查找值为data的结点 
{
    ChainBinTree *p;
    if(bt==NULL)
        return NULL;
    else
    {
        if(bt->data==data)
            return bt; 
        else{ // 分别向左右子树递归查找 
            if(p=BinTreeFind(bt->left,data))
                return p;
            else if(p=BinTreeFind(bt->right, data)) 
                return p;
            else
                return NULL; 
        } 
    } 
} 
void BinTreeClear(ChainBinTree *bt) // 清空二叉树，使之变为一棵空树
{
     if(bt)
     {
         BinTreeClear(bt->left); //清空左子树 
         BinTreeClear(bt->right);//清空右子树 
         free(bt);//释放当前结点所占内存 
         bt=NULL;
     }
     return; 
}
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p))  //先序遍历 
{     
     if(bt)//树不为空，则执行如下操作 
     {
         oper(bt); //处理结点的数据 
         BinTree_DLR(bt->left,oper);
         BinTree_DLR(bt->right,oper);
     }
     return; 
} 
void BinTree_LDR(ChainBinTree *bt,void(*oper)(ChainBinTree *p))  //中序遍历 
{
     if(bt)//树不为空，则执行如下操作 
     {
         BinTree_LDR(bt->left,oper); //中序遍历左子树
         oper(bt);//处理结点数据 
         BinTree_LDR(bt->right,oper); //中序遍历右子树/
     }
     return; 
} 
void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p)) //后序遍历
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //后序遍历左子树 
         BinTree_LRD(bt->right,oper); //后序遍历右子树/
         oper(bt); //处理结点数据
     }
     return; 
}

void oper(ChainBinTree *p) //操作二叉树结点数据 
{
     printf("%c ",p->data); //输出数据
     return;
}

void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)) //按层遍历 
{
     ChainBinTree *p;
     ChainBinTree *q[QUEUE_MAXSIZE]; //定义一个顺序栈 
     int head=0,tail=0;//队首、队尾序号 
     if(bt)//若队首指针不为空     
     {
         tail=(tail+1)%QUEUE_MAXSIZE;//计算循环队列队尾序号 
         q[tail] = bt;//将二叉树根指针进队
     }
     while(head!=tail) //队列不为空，进行循环 
     {
         head=(head+1)%QUEUE_MAXSIZE; //计算循环队列的队首序号 
         p=q[head]; //获取队首元素 
         oper(p);//处理队首元素 
         if(p->left!=NULL) //若结点存在左子树，则左子树指针进队 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//计算循环队列的队尾序号 
             q[tail]=p->left;//将左子树指针进队 
         }
                 
         if(p->right!=NULL)//若结点存在右孩子，则右孩子结点指针进队 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//计算循环队列的队尾序号 
             q[tail]=p->right;//将右子树指针进队 
         }
     }
     return; 
}
