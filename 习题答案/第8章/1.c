#include<stdio.h>

int main()
{
    int i,j,k,count=1;
    printf("100Ԫ�˱Ҷһ�����\n");
    printf("������\t1Ԫ����\t2Ԫ����\t5Ԫ����\n"); 
    for(i=0;i<=100;i++)                            //1Ԫ���ɻ�100�� 
    {
        for(j=0;j<=50;j++)                         //2Ԫ���ɻ�50�� 
        {
            for(k=0;k<=20;k++)                     //5Ԫ���ɻ�20�� 
            {
                if(i+j*2+k*5==100)
                    printf("%d\t%d\t%d\t%d\n",count++,i,j,k);
            }
        }
    }
    getch();
    return 0;
} 
 
