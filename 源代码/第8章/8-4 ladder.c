#include <stdio.h>
int main()
{
    int ladder=7;    
    while(1)
    {
        if((ladder%2==1) && (ladder%3==2) && (ladder%5==4) && (ladder%6==5))
            break;
        ladder+=7;    
    }
    printf("�ý���������%d�ס�\n",ladder); 
    getch();
    return 0;
}
