#include <stdio.h>
int gcd(int a, int b) //最大公约数 
{
    int m,n,r;
    m=a>=b?a:b; //m保存较大数 
    n=a<b?a:b; //n保存较小数 
    r=m%n; //求余数 
    while(r!=0) //辗转相除 
    {
        m=n;
        n=r;
        r=m%n;
    }
    return n; //返回最大公约数 
}
int lcm(int a,int b) //最小公倍数 
{
    int t = gcd(a,b); //获取最大公约数 
    return (a*b)/t; //返回最小公倍数 
}

int main(void)
{
    int a,b;
    printf("输入两个整数(用空格分隔):");
    scanf("%d%d",&a,&b);
    printf("最大公约数:%d\n",gcd(a,b));
    printf("最小公倍数:%d\n",lcm(a,b)); 
    getch();
    return 0;
}
