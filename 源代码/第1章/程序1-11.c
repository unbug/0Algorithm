#include <stdio.h>
#define MAXN 7 //设置每一注彩票的位数 
#define NUM 29 //设置组成彩票的数字 
int num[NUM];
int lottery[MAXN];
void combine(int n, int m)
{
     int i,j;
     for(i=n;i>=m;i--)
     {
         lottery[m-1]=num[i-1]; //保存一位数字 
         if (m>1)
             combine(i-1,m-1);
         else      //若m=1,输出一注号码 
         {
             for(j=MAXN-1;j>=0;j--)
                 printf("%3d",lottery[j]);
             getch();
             printf("\n");
         }
     }
}
int main()
{
    int i,j;
    for(i=0;i<NUM;i++)  //设置彩票各位数字 
        num[i]=i+1;
    for(i=0;i<MAXN;i++)
        lottery[i]=0;
    combine(NUM,MAXN);    

    getch();
    return 0;
}
