#include <stdio.h>
int gcd(int a, int b) //���Լ�� 
{
    int m,n,r;
    m=a>=b?a:b; //m����ϴ��� 
    n=a<b?a:b; //n�����С�� 
   if(0==n)//����С��Ϊ0 
       return m; //������һ��Ϊ���Լ�� 
   if(m%2==0 && n%2 ==0)//m��n����ż�� 
       return 2*gcd(m/2,n/2); //�ݹ����gcd��������m��n������2 
   if ( m%2 == 0)//mΪż�� 
       return gcd(m/2,n); //�ݹ����gcd��������m����2 
   if ( n%2==0 )//nΪż�� 
       return gcd(m,n/2);//�ݹ����gcd��������n����2
   return gcd((m+n)/2,(m-n)/2);//m��n�����������ݹ����gcd
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
