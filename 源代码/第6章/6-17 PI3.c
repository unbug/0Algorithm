#include <stdio.h>
int main()
{
    double pi=2,temp=2;
    int numerator=1,denominator=3;
    while(temp>1e-16) //���д���ָ���ľ��� 
    {
        temp=temp*numerator/denominator; //����һ�����е�ֵ 
        pi+=temp; //��ӵ�pi�� 
        numerator++; //��������1 
        denominator+=2; //��ĸ����2 
    }
    printf("PI=%.18f\n",pi); //������ 
    getch();
    return 0;   
}
/*
��ʽ pi/2=1+1/3*2/5+1/3*2/5*3/7+... 
*/
