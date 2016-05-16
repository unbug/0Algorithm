#include <stdio.h>
#define MAX 15

void InserSort(int a[],int n)//直接插入排序 
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];     //取出一个未排序的数据 
        for(j=i-1;j>=0 && t>a[j];--j)     //在排序序列中查找位置 
            a[j+1]=a[j]; //向后移动数据 
        a[j+1]=t; //插入数据到序列 
    }
}
int main()
{
    int a[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};
    int i;
    
    InserSort(a,MAX);	//调用插入排序函数
    printf("排序结果:"); 
    for(i=0;i<MAX;i++)	//输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}