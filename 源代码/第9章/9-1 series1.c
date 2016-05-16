#include <stdio.h>
int main()
{
    float s=0.0,k;
    int n;    
    printf("ÊäÈëÊý×Ök(1~15):");
    scanf("%f",&k);
    n=0;
    do{
        n++;
        s+=1.0/(float)n;
    }while(k>=s);
    printf("n=%d\n",n);
    getch();
    return 0;
}
