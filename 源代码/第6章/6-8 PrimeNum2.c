#include <stdio.h> 
#define MAXNUM 1000 //��1000���ڵ��������� 
int main()
{
    int i,j,c=0;
    int prime[MAXNUM+1]; //�������� 
    for(i=2;i<=MAXNUM;i++) //��ʼ������ 
        prime[i]=1; //��־Ϊ1��ʾ��Ӧ���������� 
    for(i=2;i*i<=MAXNUM;i++) //ѭ������ǰi�� 
    {
        if(prime[i]==1) //��Ϊ����
        {
            for(j=2*i;j<=MAXNUM;j++) //ɸȥ���� 
            {
                if(j%i==0) //�ܱ����� 
                    prime[j]=0; //�������� 
            }
        }
    }
    for(i=2;i<MAXNUM;i++) //������� 
    {
        if(prime[i]==1) //������������� 
        {
            printf("%4d ",i); //������� 
            c++;
            if(c%10==0) //ÿ�����10������ 
                printf("\n");
        }
    }
    printf("\n");
    getch();
    return 0; 
}
