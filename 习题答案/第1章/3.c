# include "stdio.h"

int isPrime(int a)  //�ж�a�Ƿ�������������������1��������������0
{
    int i;
    for(i=2;i<=a-1;i++)
    if(a % i == 0)
        return 0;
    return 1;
}

void Factor(int n)     //��n�ֽ�������
{  
    int i;
    for(i=2;i<=n-1;i++)
    {
        if(n % i == 0) //�ܱ����� 
        {
             printf("%d*",i);
             if(isPrime(n/i))
             {
                 printf("%d",n/i);
                 break; 
             }
            else
                Factor(n/i);		//�ݹ�ص���Factor �ֽ�n/i
        break;
        }
    }
}
int main()
{
    int n;
    printf("������һ�����������������ֽ�:")  ;
    scanf("%d",&n);
    if(isPrime(n))
        printf("��������� %d ��һ������!\n",n);
    else
    { 
        Factor(n);
        printf("=%d\n",n);
    }
    getche();
    return 0;
}
