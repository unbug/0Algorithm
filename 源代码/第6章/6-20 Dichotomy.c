#include <stdio.h> 
#include <math.h> 
double func(double x) //函数 
{
    return 2*x*x*x-5*x-1;
}
int main() 
{
    double a=1.0,b=2.0;//初始区间 
    double c;
    c=(a+b)/2.0; 
    while(fabs(func(c))>1e-5 && func(a-b)>1e-5)
    {
        if(func(c)*func(b)<0) //确定新的区间 
            a=c; 
        if(func(a)*func(c)<0)
            b=c; 
        c=(a+b)/2; //二分法确定新的区间 
    }
    printf("二分法解方程:2*x*x*x-5*x-1=0\n");
    printf("结果:%0.5f\n",c); //输出解 
    getch();
    return 0;
}
