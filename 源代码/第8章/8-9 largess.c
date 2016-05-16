#include <stdio.h>
int main()
{
    double t=1,sum=1; //t为第1格的数量,sum为合计数量 
    int i;
    for(i=2;i<=64;i++)
    {
        t=t*2;
        sum=sum+t;
    }
    printf("总麦粒数为:%.2f粒。\n",sum);
    printf("共:%.2f吨。\n",sum/25380/1000);
    getch();
    return 0;
}
