#include <stdio.h>

int main()
{
    char A, B, C;
    for(A = 'X'; A <= 'Z'; ++A)
    {
        for(B = 'X'; B <= 'Z'; ++B)
        {
            for(C = 'X'; C <= 'Z'; ++C)
            {
                if(A!=B && A!=C && B != C)
                {
                    if(A != 'X' && C != 'X' && C != 'Z')
                        printf("A-----%c\nB-----%c\nC-----%c\n", A, B, C);
                }
            }
        }
    }
    getch();
    return 0;
}
