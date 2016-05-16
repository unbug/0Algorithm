#include <stdio.h>
#include "4-1 CreateData.c"	//����������ĺ���
#define ARRAYLEN 10	//��Ҫ���������Ԫ������
void ShellSort(int a[],int n)//ϣ������ 
{
    int d,i,j,x;
    d=n/2;
    while(d>=1) //ѭ��������Ϊ1ʱ���� 
    {
        for(i=d;i<n;i++)
        {
            x=a[i]; //��ȡ�����е���һ������ 
            j=i-d; //������ǰһ�����ݵ���� 
            while(j>=0 && a[j]>x) //��һ��������ǰһ���� 
            {
                a[j+d]=a[j]; //����һ������ǰ�ƶ� 
                j=j-d; //�޸���ţ�������ǰ�Ƚ� 
            }
            a[j+d]=x; //�������� 
        }
        d/=2;  //��С���� 
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
    ShellSort(a,ARRAYLEN);	//����ϣ��������
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)	//��������Ľ��
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
