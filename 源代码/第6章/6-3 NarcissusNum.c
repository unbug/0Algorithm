#include <stdio.h> 
int main()
{
    int i,j,k,c;
    printf("100~999之间的水仙花数:"); 
    for(c=100;c<=999;c++)
    {
        i=c/100; //分解百位数 
        j=(c-i*100)/10; //分解十位数 
        k=c%10;//分解个位数
        if(i*i*i+j*j*j+k*k*k==c)
            printf("%d ",c); 
     }
     getch();
     return 0; 
}
