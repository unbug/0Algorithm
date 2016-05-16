#include <stdio.h> 
#include <stdlib.h> 

int repeat(int d[])//判断x里面是否出现重复数字
{
    int i,x,digit[10]={0};
    for(i=0;i<5;i++)
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

int main() 
{
    int d[5],num=0; 
    for(d[0]=10;d[0]<100;d[0]++)
    {
        for(d[1]=1;d[1]<10;d[1]++)
        {
            for(d[2]=1;d[2]<10;d[2]++)
            {
                for(d[3]=10;d[3]<100;d[3]++)
                {
                    d[4]=d[0]*d[1];
                    if(d[4]==d[2]*d[3] && d[4]>100)
                    {                        
                        if(!repeat(d))
                        {
                            printf("%d: %d * %d = %d * %d = %d\n",++num,d[0],d[1],d[2],d[3],d[4]);
                        }
                    }
                }
            }
        }
    }  
    getch();
    return 0; 
}