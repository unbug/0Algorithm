#include <stdio.h>
#define MAXN 7 //����ÿһע��Ʊ��λ�� 
#define NUM 29 //������ɲ�Ʊ������ 
int num[NUM];
int lottery[MAXN];
void combine(int n, int m)
{
     int i,j;
     for(i=n;i>=m;i--)
     {
         lottery[m-1]=num[i-1]; //����һλ���� 
         if (m>1)
             combine(i-1,m-1);
         else      //��m=1,���һע���� 
         {
             for(j=MAXN-1;j>=0;j--)
                 printf("%3d",lottery[j]);
             getch();
             printf("\n");
         }
     }
}
int main()
{
    int i,j;
    for(i=0;i<NUM;i++)  //���ò�Ʊ��λ���� 
        num[i]=i+1;
    for(i=0;i<MAXN;i++)
        lottery[i]=0;
    combine(NUM,MAXN);    

    getch();
    return 0;
}
