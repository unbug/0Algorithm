#include "stdio.h"

int isPrime(int n)  //�ж�n�Ƿ������������򷵻�1�������򷵻�0
{
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

int main()
{
    int total = 0;   //��������¼������
    int i;
    for(i=1;i<=100;i++)
    {
        if(isPrime(i))
        {
            total =total + i;   //�����ۼ�
        }
    }    
    printf("1��100��������֮��Ϊ: %d\n",total);
    getche();
    return 0;
}
