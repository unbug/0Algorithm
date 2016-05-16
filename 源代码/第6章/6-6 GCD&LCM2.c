#include <stdio.h>
int gcd(int a, int b) //最大公约数 
{
    int m,n,r;
    m=a>=b?a:b; //m保存较大数 
    n=a<b?a:b; //n保存较小数 
   if(0==n)//若较小数为0 
       return m; //返回另一数为最大公约数 
   if(m%2==0 && n%2 ==0)//m和n都是偶数 
       return 2*gcd(m/2,n/2); //递归调用gcd函数，将m、n都除以2 
   if ( m%2 == 0)//m为偶数 
       return gcd(m/2,n); //递归调用gcd函数，将m除以2 
   if ( n%2==0 )//n为偶数 
       return gcd(m,n/2);//递归调用gcd函数，将n除以2
   return gcd((m+n)/2,(m-n)/2);//m、n都是奇数，递归调用gcd
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
