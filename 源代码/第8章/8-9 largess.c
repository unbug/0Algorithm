#include <stdio.h>
int main()
{
    double t=1,sum=1; //tΪ��1�������,sumΪ�ϼ����� 
    int i;
    for(i=2;i<=64;i++)
    {
        t=t*2;
        sum=sum+t;
    }
    printf("��������Ϊ:%.2f����\n",sum);
    printf("��:%.2f�֡�\n",sum/25380/1000);
    getch();
    return 0;
}
