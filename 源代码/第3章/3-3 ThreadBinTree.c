#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef char DATA;       //定义元素类型 
typedef enum 
{
    SubTree,
    Thread
}NodeFlag;  //枚举值SubTree(子树)和Thread(线索)分别为0，1
typedef struct ThreadTree  //定义线索二叉树结点类型 
{
    DATA data;	//元素数据
    NodeFlag lflag; //左标志 
    NodeFlag rflag; //右标志 
    struct ThreadTree *left;	//左子树结点指针
    struct ThreadTree *right;	//右子树结点指针
}ThreadBinTree;

ThreadBinTree *Previous=NULL;     //前驱结点指针 

ThreadBinTree *BinTreeInit(ThreadBinTree *node) //初始化二叉树根结点 
{
     if(node!=NULL) //若二叉树根结点不为空 
         return node;
     else
         return NULL;
}
int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) //添加数据到二叉树 
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
ThreadBinTree *BinTreeLeft(ThreadBinTree *bt) //返回左子结点 
{
    if(bt)
        return bt->left;
    else
        return NULL;
}
ThreadBinTree *BinTreeRight(ThreadBinTree *bt) //返回右子结点 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}
int BinTreeIsEmpty(ThreadBinTree *bt) //检查二叉树是否为空，为空则返回1,否则返回0 
{
    if(bt)
        return 0;
    else
        return 1;
} 
int BinTreeDepth(ThreadBinTree *bt) //求二叉树深度
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
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data) //在二叉树中查找值为data的结点 
{
    ThreadBinTree *p;
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
void BinTreeClear(ThreadBinTree *bt) // 清空二叉树，使之变为一棵空树
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
void BinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p))  //先序遍历 
{     
     if(bt)//树不为空，则执行如下操作 
     {
         oper(bt); //处理结点的数据 
         BinTree_DLR(bt->left,oper);
         BinTree_DLR(bt->right,oper);
     }
     return; 
} 
void BinTree_LDR(ThreadBinTree *bt,void(*oper)(ThreadBinTree *p))  //中序遍历 
{
     if(bt)//树不为空，则执行如下操作 
     {
         BinTree_LDR(bt->left,oper); //中序遍历左子树
         oper(bt);//处理结点数据 
         BinTree_LDR(bt->right,oper); //中序遍历右子树/
     }
     return; 
} 
void BinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //后序遍历
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //后序遍历左子树 
         BinTree_LRD(bt->right,oper); //后序遍历右子树/
         oper(bt); //处理结点数据
     }
     return; 
} 
void BinTree_Level(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //按层遍历 
{
     ThreadBinTree *p;
     ThreadBinTree *q[QUEUE_MAXSIZE]; //定义一个顺序栈 
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
void BinTreeThreading_LDR(ThreadBinTree *bt)     //二叉树按中序线索化
{
    if(bt) //结点非空时，当前访问结点
    {
        BinTreeThreading_LDR(bt->left); //递归调用，将左子树线索化
        bt->lflag=(bt->left)?SubTree:Thread; //设置左指针域的标志
        bt->rflag=(bt->right)?SubTree:Thread;//设置右指针域的标志
        if(Previous) //若当前结点的前驱Previous存在
        {
            if(Previous->rflag==Thread) //若当前结点的前驱右标志为线索
                Previous->right=bt;//设Previous的右线索指向后继
            if(bt->lflag==Thread) //若当前结点的左标志为线索
                bt->left=Previous;//设当前结点的左线索指向中序前驱 
        }
        Previous=bt;//让Previous保存刚访问的结点
        BinTreeThreading_LDR(bt->right);//递归调用，将右子树线索化
    }
}
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt) //求指定结点的后继 
{
    ThreadBinTree *nextnode;
    if(!bt) return NULL; //若当前结点为空，则返回空 
    if(bt->rflag==Thread) //若当前结点的右子树为空
        return bt->right; //返回右线索所指的中序后继
    else{
        nextnode=bt->right; //从当前结点的右子树开始查找
        while(nextnode->lflag==SubTree) //循环处理所有左子树不为空的结点
            nextnode=nextnode->left;
        return nextnode; //返回左下方的结点
    }
}
ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt) //求指定结点的前驱 
{
    ThreadBinTree *prenode;
    if(!bt) return NULL; //若当前结点为空，则返回空 
    if(bt->lflag==Thread) //若当前结点的左子树为空
        return bt->left; //返回左线索所指的中序后继
    else{
        prenode=bt->left; //从当前结点的左子树开始查找
        while(prenode->rflag==SubTree) //循环处理所有右子树不为空的结点
            prenode=prenode->left;
        return prenode; //返回左下方的结点
    }
}

void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //遍历中序线索二叉树
{
    if(bt) //二叉树不为空
    {
        while(bt->lflag==SubTree)//有左子树 
            bt=bt->left; //从根往下找最左下结点，即中序序列的开始结点
        do{
           oper(bt); //处理结点 
           bt=BinTreeNext_LDR(bt);//找中序后继结点
        }while(bt);
    }
}
