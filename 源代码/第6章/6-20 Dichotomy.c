#include <stdio.h> 
#include <math.h> 
double func(double x) //���� 
{
    return 2*x*x*x-5*x-1;
}
int main() 
{
    double a=1.0,b=2.0;//��ʼ���� 
    double c;
    c=(a+b)/2.0; 
    while(fabs(func(c))>1e-5 && func(a-b)>1e-5)
    {
        if(func(c)*func(b)<0) //ȷ���µ����� 
            a=c; 
        if(func(a)*func(c)<0)
            b=c; 
        c=(a+b)/2; //���ַ�ȷ���µ����� 
    }
    printf("���ַ��ⷽ��:2*x*x*x-5*x-1=0\n");
    printf("���:%0.5f\n",c); //����� 
    getch();
    return 0;
}
