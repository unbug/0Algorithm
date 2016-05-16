#include <stdio.h>
int fact(int n);
int main()
{
    int i;
    printf("请输入要求阶乘的一个整数："); 
    scanf("%d",&i);
    printf("%d的阶乘结果为：%d\n",i,fact(i)); 
    getch();
    return 0;
}
int fact(int n)
{
    if(n<=1)
        return 1;
    else
       return n*fact(n-1);
}
