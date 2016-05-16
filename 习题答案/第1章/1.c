#include "stdio.h"

int isPrime(int n)  //判断n是否是素数，是则返回1，不是则返回0
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
    int total = 0;   //变量，记录素数和
    int i;
    for(i=1;i<=100;i++)
    {
        if(isPrime(i))
        {
            total =total + i;   //素数累加
        }
    }    
    printf("1至100所有素数之和为: %d\n",total);
    getche();
    return 0;
}
