#include<stdio.h>
#define MAX 20000

int main()
{
    long i,j,k,ll,kk;
    printf("%d以内的自守数有以下几个:\n",MAX);
    for(i=1;i<MAX;i++)
    {
        for(j=i,k=1;(j/=10)>0;k*=10);
            kk=k*10;
        j=0;
        ll=10;
        while(k>0)
        {
            j=(j+(i%(k*10))*(i%ll-i%(ll/10)))%kk;
            k/=10;
            ll*=10;
        }
        if(i==j)
        printf("%ld ",i);
    }
    getch();
    return 0;
}

