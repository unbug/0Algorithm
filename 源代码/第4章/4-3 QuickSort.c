#include <stdio.h>
#include "4-1 CreateData.c"
#define ARRAYLEN 10
int Division(int a[],int left, int right) //分割 
{
    int base=a[left];    //基准元素
    while(left<right)
    {
        while(left<right && a[right]>base)
            --right;     //从右向左找第一个比基准小的元素
        a[left]=a[right];
        while(left<right && a[left]<base )
            ++left;      //从左向右找第一个比基准大的元素
        a[right]=a[left];
    }
    a[left]=base;
    return left;
}
void QuickSort(int a[],int left,int right)
{
    int i,j;
    if(left<right)
    {
        i=Division(a,left,right);   //分割
        QuickSort(a,left,i-1);     //将两部分分别排序
        QuickSort(a,i+1,right);
    }
}
int main()
{
    int i,a[ARRAYLEN];
    for(i=0;i<ARRAYLEN;i++)
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    QuickSort(a,0,ARRAYLEN-1);
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
