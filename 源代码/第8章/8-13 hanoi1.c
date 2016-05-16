#include <stdio.h>
long count; //全局变量, 记录移动的次数 
void hanoi(int n,char a,char b,char c) //a移到b,用c作临时柱 
{
    if(n==1)
    {        
       printf("第%d次，%c棒-->%c棒\n",++count,a,c);
    }
    else
    {
        hanoi(n-1,a,c,b); //递归调用本函数,移动a到c,用b作临时柱 
        printf("第%d次，%c棒-->%c棒\n",++count,a,c);
        hanoi(n-1,b,a,c); //递归调用本函数,将b移到a,用c作临时柱 
    }
}
int main()
{
    int h; //圆盘数量 
    printf("请输入汉诺塔圆盘的数量:");
    scanf("%d",&h);
    count=0;
    hanoi(h,'A','B','C');    
    getch();
    return 0;
}
