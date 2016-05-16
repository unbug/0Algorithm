#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    int weight; //权值 
    int parent; //父结点序号 
    int left; //左子树序号
    int right; //右子树序号 
}HuffmanTree;
typedef char *HuffmanCode;  //Huffman编码 
void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2)
//从1~x个结点选择parent结点为0,权重最小的两个结点 
{
     int i;
     HuffmanTree *ht1,*ht2,*t;
     ht1=ht2=NULL; //初始化两个结点为空 
     for(i=1;i<=n;++i) //循环处理1~n个结点（包括叶结点和非叶结点） 
     {
         if(!ht[i].parent) //父结点为空(结点的parent=0) 
         {
             if(ht1==NULL) //结点指针1为空 
             {
                 ht1=ht+i; //指向第i个结点 
                 continue; //继续循环 
             }
             if(ht2==NULL) //结点指针2为空 
             {
                 ht2=ht+i; //指向第i个结点 
                 if(ht1->weight>ht2->weight) //比较两个结点的权重，使ht1指向的结点权重小 
                 {
                     t=ht2;
                     ht2=ht1;
                     ht1=t;
                 }
                 continue; //继续循环 
             }
             if(ht1 && ht2) //若ht1、ht2两个指针都有效 
             {
                 if(ht[i].weight<=ht1->weight) //第i个结点权重小于ht1指向的结点 
                 {
                     ht2=ht1; //ht2保存ht1，因为这时ht1指向的结点成为第2小的 
                     ht1=ht+i; //ht1指向第i个结点 
                 }else if(ht[i].weight<ht2->weight){ //若第i个结点权重小于ht2指向的结点 
                     ht2=ht+i; //ht2指向第i个结点 
                 }
             }
         }
     }
     if(ht1>ht2){ //增加比较，使二叉树左侧为叶结点 
         *bt2=ht1-ht;
         *bt1=ht2-ht;
     }else{
         *bt1=ht1-ht;
         *bt2=ht2-ht;
     }
}

void CreateTree(HuffmanTree *ht,int n,int *w)
{
    int i,m=2*n-1;//总的节点数
    int bt1,bt2; //二叉树结点序与 
    if(n<=1) return ; //只有一个结点，无法创建 
    for(i=1;i<=n;++i) //初始化叶结点 
    {
        ht[i].weight=w[i-1];
        ht[i].parent=0;
        ht[i].left=0;
        ht[i].right=0;
    }
    for(;i<=m;++i)//初始化后续结点 
    {
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].left=0;
        ht[i].right=0;
    }
    for(i=n+1;i<=m;++i) //逐个计算非叶结点，创建Huffman树 
    {
        SelectNode(ht,i-1,&bt1,&bt2); //从1~i-1个结点选择parent结点为0,权重最小的两个结点 
        ht[bt1].parent=i;
        ht[bt2].parent=i;
        ht[i].left=bt1;
        ht[i].right=bt2;
        ht[i].weight=ht[bt1].weight+ht[bt2].weight;
    }
}
void HuffmanCoding(HuffmanTree *ht,int n,HuffmanCode *hc)//,char *letters)
{
     char *cd;
     int start,i;
     int current,parent;    
     cd=(char*)malloc(sizeof(char)*n);//用来临时存放一个字符的编码结果  
     cd[n-1]='\0'; //设置字符串结束标志 
     for(i=1;i<=n;i++)
     {
         start=n-1;
         current=i;
         parent=ht[current].parent;//获取当前结点的父结点 
         while(parent) //父结点不为空 
         {
             if(current==ht[parent].left)//若该结点是父结点的左子树  
               cd[--start]='0'; //编码为0 
             else //若结点是父结点的右子树 
               cd[--start]='1'; //编码为1 
             current=parent; //设置当前结点指向父结点 
             parent=ht[parent].parent; //获取当前结点的父结点序号    
         }
         hc[i-1]=(char*)malloc(sizeof(char)*(n-start));//分配保存编码的内存 
         strcpy(hc[i-1],&cd[start]); //复制生成的编码           
     }
     free(cd); //释放编码占用的内存 
}

void Encode(HuffmanCode *hc,char *alphabet,char *str,char *code)
//将一个字符串转换为Huffman编码
//hc为Huffman编码表 ,alphabet为对应的字母表,str为需要转换的字符串,code返回转换的结果 
{
     
     int len=0,i=0,j;
     code[0]='\0';
     while(str[i])
     {
         j=0;
         while(alphabet[j]!=str[i])
             j++;         
         strcpy(code+len,hc[j]); //将对应字母的Huffman编码复制到code指定位置 
         len=len+strlen(hc[j]); //累加字符串长度 
         i++;
     }
     code[len]='\0';
}

void Decode(HuffmanTree *ht,int m,char *code,char *alphabet,char *decode)
//将一个Huffman编码组成的字符串转换为明文字符串 
//ht为Huffman二叉树,m为字符数量,alphabet为对应的字母表,str为需要转换的字符串,decode返回转换的结果 
{
     int position=0,i,j=0;
     m=2*m-1;
     while(code[position]) //字符串未结束 
     {
          for(i=m;ht[i].left && ht[i].right; position++) //在Huffman树中查找左右子树为空 ，以构造一个Huffman编码 
          {
              if(code[position]=='0') //编码位为0 
                  i=ht[i].left; //处理左子树 
              else //编译位为 1 
                  i=ht[i].right; //处理右子树 
          }
          decode[j]=alphabet[i-1]; //得到一个字母
          j++;//处理下一字符 
     }  
     decode[j]='\0'; //字符串结尾 
}
int main()
{
    int i,n=4,m; 
    char test[]="DBDBDABDCDADBDADBDADACDBDBD";
    char code[100],code1[100];
    char alphabet[]={'A','B','C','D'}; //4个字符
    int w[]={5,7,2,13} ;//4个字符的权重 
    HuffmanTree *ht;
    HuffmanCode *hc;    
    m=2*n-1;    
    ht=(HuffmanTree *)malloc((m+1)*sizeof(HuffmanTree)); //申请内存，保存赫夫曼树 
    if(!ht)
    {
        printf("内存分配失败！\n");
        exit(0);    
    }
    hc=(HuffmanCode *)malloc(n*sizeof(char*));
    if(!hc)
    {
        printf("内存分配失败！\n");
        exit(0);    
    }
    
    CreateTree(ht,n,w); //创建赫夫曼树 
    HuffmanCoding(ht,n,hc); //根据赫夫曼树生成赫夫曼编码 
    for(i=1;i<=n;i++) //循环输出赫夫曼编码 
        printf("字母:%c,权重:%d,编码为 %s\n",alphabet[i-1],ht[i].weight,hc[i-1]);
    
    Encode(hc,alphabet,test,code); //根据赫夫曼编码生成编码字符串 
    printf("\n字符串:\n%s\n转换后为:\n%s\n",test,code); 
    
    Decode(ht,n,code,alphabet,code1); //根据编码字符串生成解码后的字符串 
    printf("\n编码:\n%s\n转换后为:\n%s\n",code,code1); 
    getch();
    return 0;
}

