#include<stdio.h>
#define MAX 100

int main()
 {
     int a,count =0;
     for(a=5;a<=MAX;a+=5)
     {
          count++;
          if(!(a%25))
              count++;
     }
     printf("%d �Ľ׳˺����� %d ��0\n",MAX,count); 
     getch();
     return 0; 
 }

