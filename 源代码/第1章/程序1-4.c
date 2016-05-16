#include <stdio.h>
#define NUM 13
int main() 
{ 
    int i;
    long fib[NUM] = {1,1}; 
    
    for(i=2;i<NUM;i++) 
    { 
        fib[i] = fib[i-1]+fib[i-2]; 
    } 
    for(i=0;i<NUM;i++) 
    { 
        printf("%d月兔子总数:%d\n", i, fib[i]); 
    } 
    getch();
    return 0; 
}
