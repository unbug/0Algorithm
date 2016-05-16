#include <stdio.h>

int main()
{
    int a,b,c,count=1;
    printf("不同借书方法的组合:\n");
    for(a=1;a<=5;a++)
    {
        for(b=1;b<=5;b++)
        {
            for(c=1;a!=b&&c<=5;c++)
            {
                if(c!=a&&c!=b)
                    printf("%2d:%d,%d,%d\n",count++,a,b,c);
            }
        }
    }
    getch();
    return 0;
}