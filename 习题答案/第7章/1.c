#include "stdio.h"

void DecTo14(int dec)
{
    char d14[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D'};
    if(dec/14 == 0)
    {
        printf("%c",d14[dec%14]);            //��ʾ���λ
        return;
    }
    else{
        DecTo14(dec/14);                     //�ݹ���� 
        printf("%c",d14[dec%14]);            //��ʾ��λ
        return;
    }
}

int main()
{
    int dec;
    printf("\n������һ��ʮ����������") ;
    scanf("%d",&dec);
    if(dec>0)
    {
        printf("ʮ������ %d ת����ʮ�Ľ�����Ϊ��",dec);
        DecTo14(dec);
    }       
    else
        printf("�������һ��������\n"); 
    getche();
    return 0;
}