#include <stdio.h>
#include <stdlib.h>
int CreatePrime(int n,int prime[])
{
    int i,j;
    for(i=2;i<=n;i++) //��ʼ������ 
        prime[i]=1; //��־Ϊ1��ʾ��Ӧ���������� 
    for(i=2;i*i<=n;i++) //ѭ������ǰi�� 
    {
        if(prime[i]==1) //��Ϊ����
        {
            for(j=2*i;j<=n;j++) //ɸȥ���� 
            {
                if(j%i==0) //�ܱ����� 
                    prime[j]=0; //�������� 
            }
        }
    }
}
int main()
{
    int n,i,j,flag;
    int *prime;
    printf("����һ�����Χn(n>=6):"); 
    scanf("%d",&n); 
    if(n<6) //�ж����������Ƿ�Ϸ� 
    {
        printf("�����������!\n");
        return 0;
    }
    if(!(prime=(int *)malloc(sizeof(int)*n)))
    {
        printf("�����ڴ�ʧ��!\n");
        getch();
        return 0; 
    }
    CreatePrime(n,prime); //������������ 
    for(i=6;i<=n;i+=2) //��6��ʼ��ѭ����֤��ż�� 
    {
        flag=1;
        for(j=2;j<=i/2;j++) //�ж����ÿ�������������� 
        {
          if(j%2==0 || ((i-j)%2==0)) continue; //��һ��������ż���������������ж� 
          if(prime[j]==1 && prime[i-j]==1) //������������������ 
          {
              printf("%d=%d+%d\n",i,j,i-j);//������� 
              flag=0; //�����־ 
              break; 
          }
        }
        if(1==flag)//��ĳ��ż������������������� 
            printf("�ҵ�һ��������Ҫ���ż��:%d\n",i); 
    }
    getch();
    return 0;
}
