#include <stdio.h>
#define MAX 15

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
    int a[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};
    int i;
    
    QuickSort(a,0,MAX-1);
    printf("排序结果:"); 
    for(i=0;i<MAX;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}