#include <stdio.h>

long count; //ȫ�ֱ���, ��¼�ƶ��Ĵ��� 
void hanoi(int n,char a,char b,char c) //a�Ƶ�b,��c����ʱ�� 
{
    if(n==1)
    {        
       printf("��%d�Σ�%c��-->%c��\n",++count,a,c);
    }
    else
    {
        hanoi(n-1,a,c,b); //�ݹ���ñ�����,�ƶ�a��c,��b����ʱ�� 
        printf("��%d�Σ�%c��-->%c��\n",++count,a,c);
        hanoi(n-1,b,a,c); //�ݹ���ñ�����,��b�Ƶ�a,��c����ʱ�� 
    }
}
int main()
{
    int h; //Բ������ 
    printf("�����뺺ŵ��Բ�̵�����:");
    scanf("%d",&h);
    count=0;
    hanoi(h,'A','B','C');    
    getch();
    return 0;
}
