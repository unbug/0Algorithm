#include <stdio.h>
#define ARRAYLEN 8
int source[ARRAYLEN+1]={69,65,90,37,92,6,28,54};

int SeqSearch(int s[],int n,int key)
{
    int i;
    for(i=0;s[i]!=key;i++)
        ;
    if(i<n)
        return i;
    else
        return -1;
}

int main()
{
    int key,i,pos;
    printf("请输入关键字:");
    scanf("%d",&key); 
    source[ARRAYLEN]=key; //保存key值到最后一个元素 
    pos=SeqSearch(source,ARRAYLEN,key);
    printf("原数据表:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",source[i]);
    printf("\n");
    if(pos>=0)
        printf("查找成功，该关键字位于数组的第%d个位置。\n",pos);
    else
        printf("查找失败!\n");
    getch();
    return 0;
}
