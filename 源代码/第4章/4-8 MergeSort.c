#include <stdio.h>
#include "4-1 CreateData.c"	//生成随机数的函数
#define ARRAYLEN 10	//需要排序的数据元素数量
void MergeStep(int a[],int r[],int s,int m,int n) //相邻有序段合并 
{
    int i,j,k;
    k=s;
    i=s;
    j=m+1;
    while(i<=m && j<=n) //当两个有序表都未结束时，循环比较 
    {
        if(a[i]<=a[j]) //当较小的元素复制到R中 
            r[k++]=a[i++];
        else
            r[k++]=a[j++];
    }
    while(i<=m) //将未合并的部分复制到R中 
        r[k++]=a[i++];
    while(j<=n)
        r[k++]=a[j++]; //将未合并的部分复制到R中 
}
void MergePass(int a[],int r[],int n,int len) //完成一遍合并的函数 
{
    int s,e;
    s=0;
    while(s+len<n) //至少有两个有序段 
    {
        e=s+2*len-1;
        if(e>=n) //最后一段可能少于len个结点 
            e=n-1;
        MergeStep(a,r,s,s+len-1,e); //相邻有序段合并 
        s=e+1; //下一对有序段中左段的开始下标 
    }
    if(s<n) //还剩一个有序段，将其从A中复制到R中 
        for(;s<n;s++)
            r[s]=a[s];
}
void MergeSort(int a[],int n)
{
    int *p;
    int len=1;     //有序序列的长度 
    int f=0;	//变量f作标志
    if(!(p=(int *)malloc(sizeof(int)*n)))	//分配内存空间，保存临时数据
    {
        printf("分配临时内存失败!\n");
        exit(0); 
    }
    while(len<n)
    {
        if(f)   //交替地在A和P之间来回合并 
            MergePass(p,a,n,len);	//调用MergePass，对p合并到a
        else
            MergePass(a,p,n,len);	//调用MergePass，对a合并到p
        len*=2;	//增加有序序列长度
        f=1-f; //使f值在0和1之间切换 
    }
    if(f)	//若进行了排序
        for(f=0;f<n;f++)	//将数组p中的数据复制到数组a
            a[f]=p[f];
    free(p); //释放分配的内存 
}

int main()
{
    int i,a[ARRAYLEN];	//定义数组
    for(i=0;i<ARRAYLEN;i++)	//清空数组
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))	//判断生成随机数是否成功
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 	//输出生成的随机数
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    MergeSort(a,ARRAYLEN);	//调用合并排序函数
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)	//输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
