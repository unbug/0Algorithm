#include "stdio.h"

int fisherman(int start,int n)
{
   int s = start;
   while(n)
   {
        s = 5*s+1 ;
        n--;
   }
   return s;
}

int main()
{
    printf("5个渔夫共计捕得 %d 条渔",fisherman(6,4));
    getch();
    return 0;
}