#include "stdio.h"
#include "stdlib.h"
#include "time.h"

double DI(int n)
{
    double x,y;
    time_t t;
    int i,count = 0;
    srand((unsigned)time(&t));
    for(i=0;i<n;i++)
    {
        x = rand()%100/100.0;
        y = rand()%200/100.0;

        if(y<=1 + pow(x,3))
            count++;
    }
    return 2.0*(double)count/(double)n;	
}

int main()
{
    int n;
    printf("请输入随机点的数量：") ;
    scanf("%d",&n);
    printf("定积分结果：%f\n",DI(n));
    getche();
    return 0;
}