#include<stdio.h>

int main()
{
    int i,j,k,count=1;
    printf("100元人币兑换方案\n");
    printf("方案数\t1元数量\t2元数量\t5元数量\n"); 
    for(i=0;i<=100;i++)                            //1元最多可换100张 
    {
        for(j=0;j<=50;j++)                         //2元最多可换50张 
        {
            for(k=0;k<=20;k++)                     //5元最多可换20张 
            {
                if(i+j*2+k*5==100)
                    printf("%d\t%d\t%d\t%d\n",count++,i,j,k);
            }
        }
    }
    getch();
    return 0;
} 
 
