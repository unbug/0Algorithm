#include <stdio.h>

int repeat(int d[])//�ж�x�����Ƿ�����ظ�����
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
    if(digit[0])  //��������к�0
        return 1;
    for(i=1;i<10;i++)
    {
       if(digit[i]>1)  //���x���溬���ظ�����
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