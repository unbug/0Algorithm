#include "stdio.h"
#define NUM 5

void sort(int w[], int t[], int n)
{
    int i,j,tmp;
    int *w_tmp= (int *)malloc(sizeof(int) * n);
    for(i=0;i<n;i++)
        t[i] = i;
    for(i=0;i<n;i++)
        w_tmp[i] = w[i];
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(w_tmp[j]>w_tmp[j+1])
            {
                tmp = w_tmp[j];
                w_tmp[j] = w_tmp[j+1];
                w_tmp[j+1] = tmp;
                tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
            }
        }
    }
}

void Loading(int x[],int w[],int c,int n)
{
    int i , s = 0 ;
    int *t = (int *)malloc(sizeof(int) * n);
    sort(w,t,n);
    for(i = 0;i<n;i++)
    x[i] = 0;
    for(i=0;i<n && w[t[i]]<=c; i++)
    {
        x[t[i]] = 1;
        c = c - w[t[i]];
    }
}

int main()
{
    int x[NUM],w[NUM],c,i;
    printf("��������������������");
    scanf("%d",&c);	
    printf("������ %d ����װ���������\n",NUM);
    for(i=0;i<NUM;i++)
        scanf("%d",&w[i]);
    Loading(x,w,c,NUM);	
    printf("����װ�����¼�װ�䣺\n");
    for(i=0;i<NUM;i++)
    {
        if(x[i] == 1)
            printf("��װ��:%d��������%d\n",i+1,w[i]) ;
    }
    getche();
    return 0;
}