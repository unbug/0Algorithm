# include "stdio.h"

int isPrime(int a)  //判断a是否是质数，是质数返回1，不是质数返回0
{
    int i;
    for(i=2;i<=a-1;i++)
    if(a % i == 0)
        return 0;
    return 1;
}

void Factor(int n)     //对n分解质因数
{  
    int i;
    for(i=2;i<=n-1;i++)
    {
        if(n % i == 0) //能被整除 
        {
             printf("%d*",i);
             if(isPrime(n/i))
             {
                 printf("%d",n/i);
                 break; 
             }
            else
                Factor(n/i);		//递归地调用Factor 分解n/i
        break;
        }
    }
}
int main()
{
    int n;
    printf("请输入一个整数进行质因数分解:")  ;
    scanf("%d",&n);
    if(isPrime(n))
        printf("输入的整数 %d 是一个质数!\n",n);
    else
    { 
        Factor(n);
        printf("=%d\n",n);
    }
    getche();
    return 0;
}
