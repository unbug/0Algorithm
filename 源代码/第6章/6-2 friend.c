#include <stdio.h>
int main() 
{
    int i,a,b1,b2,m,g1[100],g2[100],count;
    printf("输入最大范围:");
    scanf("%d",&m); 
    for(a=1;a<m;a++)      //循环次数
    {
        for(i=0;i<100;i++) //清空数组 
            g1[i]=g2[i]=0;
        count=0;//数组下标 
        b1=0;//累加和 
        for(i=1;i<a/2+1;i++)//求数a的因子 
        {
            if(a%i==0)//a能被i整除 
            {
                g1[count++]=i; //保存因子到数组，方便输出 
                b1+=i;//累加因子之和 
            }
        }
        count=0;
        b2=0;
        for(i=1;i<b1/2+1;i++) //将数a因子之和再进行因子分解 
        {
            if(b1%i==0) //b1能被i整除 
            {
                g2[count++]=i; //保存因子到数组 
                b2=b2+i;      //累加因子之和 
            }
        }
        if(b2==a && a<b1) //判断A，B的输出条件  
        {
            printf("\n\n%d--%d是亲密数，各因子为：",a,b1); //输出亲密数 
            printf("\n%d=1",a);
            count=1;
            while(g1[count]>0)//输出一个数的因子 
            {
                printf("+%d",g1[count]);
                count++;
            }
            printf("\n%d=1",b1);
            count=1;
            while(g2[count]>0)//输出另一个数的因子 
            {
                printf("+%d",g2[count]);
                count++;
            }
        }
    } 
    getch();
    return 0;
}

