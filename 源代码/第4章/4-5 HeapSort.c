#include <stdio.h>
#include "4-1 CreateData.c"
#define ARRAYLEN 10
void HeapAdjust(int a[],int s,int n)//���ɶ�
{
    int j,t;
    while(2*s+1<n) //��s������������� 
    {
        j=2*s+1 ;
        if((j+1)<n)
        {            
            if(a[j]<a[j+1])//��������С��������������Ҫ�Ƚ�������
                j++; //�������1��ָ�������� 
        }
        if(a[s]<a[j])//�Ƚ�s��jΪ��ŵ�����
        {            
            t=a[s];  //�������� 
            a[s]=a[j];
            a[j]=t;            
            s=j ;//�ѱ��ƻ�����Ҫ���µ���
        }
        else //�Ƚ����Һ��Ӿ������δ�ƻ���������Ҫ����
            break;
    }
}
void HeapSort(int a[],int n)//������
{
    int t,i;
    int j;
    for(i=n/2-1;i>=0;i--)    //��a[0,n-1]���ɴ����
        HeapAdjust(a, i, n);
    for(i=n-1;i>0;i--)
    {
        t=a[0];//���i����¼����
        a[0] =a[i];
        a[i] =t;
        HeapAdjust(a,0,i);        //��a[0]��a[i]���µ���Ϊ��
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
    HeapSort(a,ARRAYLEN);
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
