#include <stdio.h>
int main()
{
    long faciend,num,mod,n_mod,p_mod; //mod被乘数的系数，n_mod乘数的系数,p_mod部分乘积的系数 
    long i,t,n;  //临时变量 
    printf("输入最大数:");
    scanf("%ld",&num);    
    printf("1~%ld之间有以下自守数:\n",num);
    for(i=1;i<num;i++)
    {
        faciend=i; //被乘数 
        mod=1;
        do{
            mod*=10; //被乘数的系数 
            faciend/=10;
        }while(faciend>0); //循环求出被乘数的系数 
        p_mod=mod; //p_mod为截取部分积时的系数 
        faciend=0; //积的最后N位 
        n_mod=10; //ll为截取乘数相应位时的系数 
        while(mod>0)
        {
            t=i % (mod*10); //获取被乘数 
            n=i%n_mod-i%(n_mod/10);//分解出每一位乘数作为乘数 
            t=t*n; //相乘的结果 
            faciend=(faciend+t)%p_mod; //截取乘积的后面几位
            mod/=10; //调整被乘数的系数 
            n_mod*=10; //调整乘数的系数 
        }
        if(i==faciend) //若为自守数，则输出 
            printf("%ld ",i);
    }
    getch();
    return 0;
}
