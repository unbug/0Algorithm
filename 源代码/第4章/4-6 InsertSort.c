#include <stdio.h>
#include "4-1 CreateData.c"	//����������ĺ���
#define ARRAYLEN 10	//��Ҫ���������Ԫ������
void InserSort(int a[],int n)//ֱ�Ӳ������� 
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];     //ȡ��һ��δ��������� 
        for(j=i-1;j>=0 && t<a[j];--j)     //�����������в���λ�� 
            a[j+1]=a[j]; //����ƶ����� 
        a[j+1]=t; //�������ݵ����� 
    }
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
    InserSort(a,ARRAYLEN);	//���ò���������
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)	//��������Ľ��
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
