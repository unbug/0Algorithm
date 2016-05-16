#include <stdio.h>
int main()
{
    int x,y,z,k;
    for(k = 0; k <= 3; k++)
    {
        x=4*k;
        y=25-7*k;
        z=100-x-y; 
        printf("¹«¼¦:%d£¬Ä¸¼¦:%d£¬Ð¡¼¦:%d\n", x, y, z);
    }
    getch();
    return 0;
}
