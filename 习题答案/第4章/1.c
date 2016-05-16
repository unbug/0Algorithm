#include <stdio.h>
#include <stdlib.h>
#define MAX 80

void bubble(char *str,int count)
{
     int i,d;
     char t;
     
     d=0;
     while(!d)
     {
         d=1;
         for(i=0;i<count-1;i++)
         {
             if(str[i+1]<str[i])
             {
                 t=str[i+1];
                 str[i+1]=str[i];
                 str[i]=t;
                 d=0;
             }
         }
     }
}

int main()
{
    char str[MAX];
    int count;
    
    printf("ÇëÊäÈëÒ»´®Ó¢ÎÄ×Ö·û:");
    gets(str);
    count=strlen(str);
    
    bubble(str,count);
    printf("\nÅÅÐòºóµÄ×Ö·û´®:%s\n",str);
    getch(); 
    return 0;
}
