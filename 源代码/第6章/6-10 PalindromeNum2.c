#include <stdio.h>
int main(void)
{
    int n,high,low,count=0;
    int b[10]; //保存平方数的各位 
    long s;
    printf("序号\t数值\t回文数\n");
    for(n=10;n<1000;n++) //循环所有范围
    {
        s=n*n; //计算n的平方
        high=0;
        while(s>0)
        {
            b[high++]=s%10;
            s/=10;   
        }
        low=-1; //低位指示器 
        while(++low<--high) //high是高位指示器
        {
            if(b[low]!=b[high]) //若高位和低位不相等，则不对称 
                break; //退出循环 
        }        
        if(low>=high)//所有高位和低位都比较后退出循环 
            printf("%2d\t%d\t%d\n",++count,n,n*n); //输出n和回文数 
    }
    getch();
    return 0;
}
