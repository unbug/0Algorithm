#include <stdio.h>
#include "4-1 CreateData.c"
#define ARRAYLEN 10
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
    int i,a[ARRAYLEN];
    for(i=0;i<ARRAYLEN;i++)
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))
    {
        printf("������������ɹ�!\n");
        getch();
        return 1;
    }
    printf("ԭ����:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    QuickSort(a,0,ARRAYLEN-1);
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
