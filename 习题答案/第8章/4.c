#include<stdio.h>

int main()
{
    int n,a,b;
    printf("����(ab+cd)^2=abcd����������\n");
    for(n=1000;n<10000;n++)
    {
        a=n/100;
        b=n%100;
        if((a+b)*(a+b)==n)
            printf("%d ",n);
    }
    getch();
    return 0;
}
