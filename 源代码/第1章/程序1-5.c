#include <stdio.h>
#define FETCH 1000
#define RATE 0.0171
int main()
{
    double corpus[49];
    int i;
    corpus[48]=(double)FETCH;
    for(i=47;i>0;i--)
    {
        corpus[i]=(corpus[i+1]+FETCH)/(1+RATE/12);
    }
    for(i=48;i>0;i--)
    {
        printf("第%d月末本利合计:%.2f\n",i,corpus[i]);
    }
    getch();
    return 0;
}
