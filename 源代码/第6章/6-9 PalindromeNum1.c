#include <stdio.h>
int PrimeNum(int i); //判断质数 
int main()
{
    int i,j,t,k,s;
    printf("1000以内的回文素数有:\n");
    for(i=0;i<=9;++i) //百位
        for(j=0;j<=9;++j) //十位
        {
            if(i==0 && j==0) //若前两位都为0 
                continue; //重新循环 
            for(k=0;k<=9;++k)//个位 
            {
                if(i!=0 && i!=k) //若百位不为0,且百位和个位不等 
                    continue; //重新循环 
                s=i*100+j*10+k; //给合为一个整数 
                t=k*100+j*10+i; //组合为另一个整数（反序数）
                if(i==0) //整数的第一位为0，是二位整数
                     t/=10; //调整反向组成的数 
                if(s>10 && s==t) //若大于10且为回文数
                    if(PrimeNum(s)==1)//若是素数
                        printf("%d\t",s); //输出回文数 
            }
        }
    getch();
    return 0;
}
int PrimeNum(int i) //判断数i是否为质数 
{
    int j,flag=1;
    for(j=2;j*j<i;j++) //循环除以每个数 
    {
        if(i%j==0) //i能被j整除，表示不是质数 
        {
            flag=0;
            break; 
        }
    }
    return flag; //返回结果 
}
