#include <stdio.h>
unsigned long factorial(unsigned long n)
{
    if(n<0)
        return 1;
    if(1==n)
        return 1;
    else
        return (unsigned long)n*factorial(n-1);
}
int main()
{
    unsigned long n;
    printf("输入一个整数n(n>0):"); 
    scanf("%d",&n); 
    printf("%lu!=%lu\n",n,factorial(n));
    getch();
    return 0;
}
