#include <stdio.h>
#define MAX 15

int Division(int a[],int left, int right) //�ָ� 
{
    int base=a[left];    //��׼Ԫ��
    while(left<right)
    {
        while(left<right && a[right]>base)
            --right;     //���������ҵ�һ���Ȼ�׼С��Ԫ��
        a[left]=a[right];
        while(left<right && a[left]<base )
            ++left;      //���������ҵ�һ���Ȼ�׼���Ԫ��
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
        i=Division(a,left,right);   //�ָ�
        QuickSort(a,left,i-1);     //�������ֱַ�����
        QuickSort(a,i+1,right);
    }
}
int main()
{
    int a[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};
    int i;
    
    QuickSort(a,0,MAX-1);
    printf("������:"); 
    for(i=0;i<MAX;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}