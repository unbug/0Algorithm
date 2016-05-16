#include <stdio.h> 
#include <math.h> 
int main () 
{
    int i,n,s;
    double k,y2;
    printf("输入切割次数:");
    scanf("%d",&n); 
    i=0;//切割次数 
    k=3.0; //初始值 
    y2=1.0; //内接六边形的边长 
    s=6;//初始内接多边形的边数 
    while(i<=n)
    {
        printf("第%d次切割,为%d边,PI=%.24f\n",i,s,k*sqrt(y2));
        s*=2; //边数增加1倍 
        y2=2-sqrt(4-y2); //弦长 
        i++;
        k*=2.0;        
    } 
    getch();
    return 0;
}
