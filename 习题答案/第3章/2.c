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
