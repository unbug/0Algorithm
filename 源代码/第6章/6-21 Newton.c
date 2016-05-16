#include <stdio.h>
double func(double x) //���� 
{
    return x*x*x*x-3*x*x*x+1.5*x*x-4.0;
}
double func1(double x) //������ 
{
    return 4*x*x*x-9*x*x+3*x;
}
int Newton(double *x,double precision,int maxcyc) //�������� 
{
    double x1,x0;
    int k;
    x0=*x;
    for(k=0;k<maxcyc;k++)
    {
        if(func1(x0)==0.0)//��ͨ����ֵ����������ֵΪ0
        {
            printf("���������е���Ϊ0!\n");
            return 0;
        }
        x1=x0-func(x0)/func1(x0);//����ţ�ٵ������� 
        if(fabs(x1-x0)<precision || fabs(func(x1))<precision) //�ﵽ�������� 
        {
            *x=x1; //���ؽ�� 
            return 1;
        }
        else //δ�ﵽ�������� 
            x0=x1; //׼����һ�ε��� 
    }
    printf("������������Ԥ��!\n"); //���������ﵽ����û�дﵽ����
    return 0;
}
int main()
{
    double x,precision;
    int maxcyc;
    printf("�����ʼ����ֵx0:");
    scanf("%lf",&x); 
    printf("��������������:"); 
    scanf("%d",&maxcyc);
    printf("����Ҫ��ľ���:");
    scanf("%lf",&precision);
    if(Newton(&x,precision,maxcyc)==1) //����������ֵΪ1 
        printf("��ֵ�����ĸ�Ϊ:%lf\n",x);
    else //����������ֵΪ0 
        printf("����ʧ��!\n");
    getch();
    return 0;
}
