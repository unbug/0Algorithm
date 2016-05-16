#include <stdio.h>
int main()
{
    int x,y,z;
    for(x=0;x<=20;x++)
    {
        for(y=0;y<=33;y++)
        {
            z=100-x-y;
            if (z%3==0 &&x*5+y*3+z/3==100)
                printf("¹«¼¦£º%d,Ä¸¼¦£º%d,Ð¡¼¦£º%d\n",x,y,z);
        }
    }  
    getch();
    return 0;
}
