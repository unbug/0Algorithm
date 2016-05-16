#include <stdio.h>

int repeat(int d[])//判断x里面是否出现重复数字
{
    int i,x,digit[10]={0};
    for(i=0;i<3;i++)
    {
        x=d[i];
        while(x)
        {
            digit[x%10]++;
            x/=10;
        }
    }
    if(digit[0])  //数字组成中含0
        return 1;
    for(i=1;i<10;i++)
    {
       if(digit[i]>1)  //如果x里面含有重复数字
          return 1;
    }
    return 0;
}

int main( )
{
    int i,j,d[3]={0};
    int count=0;
    for(i=100;i<1000;i++)
    {
        for(j=i+1;j<1000;j++)
        {
            d[0]=i;
            d[1]=j;
            d[2]=d[0]+d[1];
            if(!repeat(d))
               printf("%3d: %d + %d = %d\n",++count,d[0],d[1],d[2]);
        }
    }
    getch();
    return 0;
}