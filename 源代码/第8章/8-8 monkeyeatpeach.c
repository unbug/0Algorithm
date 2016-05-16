#include <stdio.h>
int peach(int n) //递归函数 
{
    if(n==1)
        return 1;  //第10天就只剩1个了
    else
       return (peach(n-1)+1)*2;  //前一天总比后1天多一半加1
}
int main()
{
    int days; //天数 
    long sum; //最初桃子数 
    printf("输入天数:");
    scanf("%d",&days); 
    sum=peach(days);
    printf("最初的桃子数:%ld\n",sum);
    getch();
    return 0;
}
