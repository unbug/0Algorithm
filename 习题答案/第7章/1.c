#include "stdio.h"

void DecTo14(int dec)
{
    char d14[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D'};
    if(dec/14 == 0)
    {
        printf("%c",d14[dec%14]);            //显示最高位
        return;
    }
    else{
        DecTo14(dec/14);                     //递归调用 
        printf("%c",d14[dec%14]);            //显示低位
        return;
    }
}

int main()
{
    int dec;
    printf("\n请输入一个十进制整数：") ;
    scanf("%d",&dec);
    if(dec>0)
    {
        printf("十进制数 %d 转换到十四进制数为：",dec);
        DecTo14(dec);
    }       
    else
        printf("输入的是一个负数！\n"); 
    getche();
    return 0;
}