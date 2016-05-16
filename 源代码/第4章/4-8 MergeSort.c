#include <stdio.h>
#include "4-1 CreateData.c"	//����������ĺ���
#define ARRAYLEN 10	//��Ҫ���������Ԫ������
void MergeStep(int a[],int r[],int s,int m,int n) //��������κϲ� 
{
    int i,j,k;
    k=s;
    i=s;
    j=m+1;
    while(i<=m && j<=n) //�����������δ����ʱ��ѭ���Ƚ� 
    {
        if(a[i]<=a[j]) //����С��Ԫ�ظ��Ƶ�R�� 
            r[k++]=a[i++];
        else
            r[k++]=a[j++];
    }
    while(i<=m) //��δ�ϲ��Ĳ��ָ��Ƶ�R�� 
        r[k++]=a[i++];
    while(j<=n)
        r[k++]=a[j++]; //��δ�ϲ��Ĳ��ָ��Ƶ�R�� 
}
void MergePass(int a[],int r[],int n,int len) //���һ��ϲ��ĺ��� 
{
    int s,e;
    s=0;
    while(s+len<n) //��������������� 
    {
        e=s+2*len-1;
        if(e>=n) //���һ�ο�������len����� 
            e=n-1;
        MergeStep(a,r,s,s+len-1,e); //��������κϲ� 
        s=e+1; //��һ�����������εĿ�ʼ�±� 
    }
    if(s<n) //��ʣһ������Σ������A�и��Ƶ�R�� 
        for(;s<n;s++)
            r[s]=a[s];
}
void MergeSort(int a[],int n)
{
    int *p;
    int len=1;     //�������еĳ��� 
    int f=0;	//����f����־
    if(!(p=(int *)malloc(sizeof(int)*n)))	//�����ڴ�ռ䣬������ʱ����
    {
        printf("������ʱ�ڴ�ʧ��!\n");
        exit(0); 
    }
    while(len<n)
    {
        if(f)   //�������A��P֮�����غϲ� 
            MergePass(p,a,n,len);	//����MergePass����p�ϲ���a
        else
            MergePass(a,p,n,len);	//����MergePass����a�ϲ���p
        len*=2;	//�����������г���
        f=1-f; //ʹfֵ��0��1֮���л� 
    }
    if(f)	//������������
        for(f=0;f<n;f++)	//������p�е����ݸ��Ƶ�����a
            a[f]=p[f];
    free(p); //�ͷŷ�����ڴ� 
}

int main()
{
    int i,a[ARRAYLEN];	//��������
    for(i=0;i<ARRAYLEN;i++)	//�������
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))	//�ж�����������Ƿ�ɹ�
    {
        printf("������������ɹ�!\n");
        getch();
        return 1;
    }
    printf("ԭ����:"); 	//������ɵ������
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    MergeSort(a,ARRAYLEN);	//���úϲ�������
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)	//��������Ľ��
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
