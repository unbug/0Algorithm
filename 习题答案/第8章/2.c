#include<stdio.h>
#define MAX 10000

int main()
{
    int a,i,b,n;
    printf("%d���ڵ�������:\n",MAX);
    for(a=1;a<MAX;a++) //���10000���ڵ�ȫ������
    { 
        for(b=0,i=1;i<=a/2;i++) //������a�ĸ����ӣ�������֮�ʹ����b
        {
            if(!(a%i))
                b+=i; //����b�ĸ����ӣ�������֮�ʹ���n
        }
        for(n=0,i=1;i<=b/2;i++)
        {
            if(!(b%i))
                n+=i;
        }
        if(n==a && a<b)        //��n=a����a��b��һ��������
            printf("%4d ����������%4d\n",a,b); 
    }
    getch();
    return 0;
}
