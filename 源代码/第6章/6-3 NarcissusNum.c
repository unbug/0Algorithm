#include <stdio.h> 
int main()
{
    int i,j,k,c;
    printf("100~999֮���ˮ�ɻ���:"); 
    for(c=100;c<=999;c++)
    {
        i=c/100; //�ֽ��λ�� 
        j=(c-i*100)/10; //�ֽ�ʮλ�� 
        k=c%10;//�ֽ��λ��
        if(i*i*i+j*j*j+k*k*k==c)
            printf("%d ",c); 
     }
     getch();
     return 0; 
}
