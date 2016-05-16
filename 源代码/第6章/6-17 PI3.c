#include <stdio.h>
int main()
{
    double pi=2,temp=2;
    int numerator=1,denominator=3;
    while(temp>1e-16) //数列大于指定的精度 
    {
        temp=temp*numerator/denominator; //计算一个数列的值 
        pi+=temp; //添加到pi中 
        numerator++; //分子增加1 
        denominator+=2; //分母增加2 
    }
    printf("PI=%.18f\n",pi); //输出结果 
    getch();
    return 0;   
}
/*
公式 pi/2=1+1/3*2/5+1/3*2/5*3/7+... 
*/
