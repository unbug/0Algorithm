#include <stdio.h>
int fact(int n);
int main()
{
    int i;
    printf("������Ҫ��׳˵�һ��������"); 
    scanf("%d",&i);
    printf("%d�Ľ׳˽��Ϊ��%d\n",i,fact(i)); 
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
