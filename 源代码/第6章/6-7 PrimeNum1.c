#include <stdio.h> 
#define MAXNUM 1000 //��1000���ڵ��������� 
int main()
{
    int i,j,c=0;
    int prime[MAXNUM+1]; //�������� 
    for(i=2;i<=MAXNUM;i++) //��ʼ������ 
        prime[i]=1; //��־Ϊ1��ʾ��Ӧ���������� 
    for(i=3;i<=MAXNUM;i++) //ѭ��������� 
    {
        prime[i]=PrimeNum(i); //������i�Ƿ�Ϊ���� 
    }
    for(i=2;i<MAXNUM;i++) //������� 
    {     
        if(prime[i]==1) //�������� 
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
int PrimeNum(int i) //�ж���i�Ƿ�Ϊ���� 
{
    int j,flag=1;
    for(j=2;j<i-1;j++) //ѭ������ÿ���� 
    {
        if(i%j==0) //i�ܱ�j��������ʾ�������� 
        {
            flag=0;
            break; 
        }
    }
    return flag; //���ؽ�� 
}
int PrimeNum1(int i) //�ж���i�Ƿ�Ϊ���� 
{
    int j,flag=1;
    for(j=2;j*j<i;j++) //ѭ������ÿ���� 
    {
        if(i%j==0) //i�ܱ�j��������ʾ�������� 
        {
            flag=0;
            break; 
        }
    }
    return flag; //���ؽ�� 
}
