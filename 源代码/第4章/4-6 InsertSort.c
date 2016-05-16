#include <stdio.h>
#include "4-1 CreateData.c"	//生成随机数的函数
#define ARRAYLEN 10	//需要排序的数据元素数量
void InserSort(int a[],int n)//直接插入排序 
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];     //取出一个未排序的数据 
        for(j=i-1;j>=0 && t<a[j];--j)     //在排序序列中查找位置 
            a[j+1]=a[j]; //向后移动数据 
        a[j+1]=t; //插入数据到序列 
    }
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
    InserSort(a,ARRAYLEN);	//调用插入排序函数
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)	//输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
