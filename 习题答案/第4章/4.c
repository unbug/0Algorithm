#include <stdio.h>
#define MAX 15

void InserSort(int a[],int n)//ֱ�Ӳ������� 
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];     //ȡ��һ��δ��������� 
        for(j=i-1;j>=0 && t>a[j];--j)     //�����������в���λ�� 
            a[j+1]=a[j]; //����ƶ����� 
        a[j+1]=t; //�������ݵ����� 
    }
}
int main()
{
    int a[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};
    int i;
    
    InserSort(a,MAX);	//���ò���������
    printf("������:"); 
    for(i=0;i<MAX;i++)	//��������Ľ��
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}