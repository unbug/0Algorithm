#include <stdio.h>
int gcd(int a, int b) //���Լ�� 
{
    int m,n,r;
    m=a>=b?a:b; //m����ϴ��� 
    n=a<b?a:b; //n�����С�� 
    r=m%n; //������ 
    while(r!=0) //շת��� 
    {
        m=n;
        n=r;
        r=m%n;
    }
    return n; //�������Լ�� 
}
int lcm(int a,int b) //��С������ 
{
    int t = gcd(a,b); //��ȡ���Լ�� 
    return (a*b)/t; //������С������ 
}

int main(void)
{
    int a,b;
    printf("������������(�ÿո�ָ�):");
    scanf("%d%d",&a,&b);
    printf("���Լ��:%d\n",gcd(a,b));
    printf("��С������:%d\n",lcm(a,b)); 
    getch();
    return 0;
}
