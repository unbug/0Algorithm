#include "stdio.h"

int StrRev()
{
    char c;
    scanf("%c",&c);
    if('#' == c)
    {
        printf("��ת����ַ�����"); 
        return 0;
    }
    StrRev();
    printf("%c",c);
}

int main()
{
   printf("������Ӣ���ַ���(��#����):"); 
   StrRev();
   getche();
   return 0;
}