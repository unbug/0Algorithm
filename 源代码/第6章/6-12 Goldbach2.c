#include <stdio.h>
#include <stdlib.h>
int CreatePrime(int n,int prime[])
{
    int i,j;
    for(i=2;i<=n;i++) //初始化数组 
        prime[i]=1; //标志为1表示对应的数是质数 
    for(i=2;i*i<=n;i++) //循环处理前i个 
    {
        if(prime[i]==1) //若为质数
        {
            for(j=2*i;j<=n;j++) //筛去合数 
            {
                if(j%i==0) //能被整除 
                    prime[j]=0; //不是质数 
            }
        }
    }
}
int main()
{
    int n,i,j,flag;
    int *prime;
    printf("输入一个最大范围n(n>=6):"); 
    scanf("%d",&n); 
    if(n<6) //判断输入数据是否合法 
    {
        printf("数据输入错误!\n");
        return 0;
    }
    if(!(prime=(int *)malloc(sizeof(int)*n)))
    {
        printf("分配内存失败!\n");
        getch();
        return 0; 
    }
    CreatePrime(n,prime); //生成素数数组 
    for(i=6;i<=n;i+=2) //从6开始，循环验证各偶数 
    {
        flag=1;
        for(j=2;j<=i/2;j++) //判断组成每个数的两个加数 
        {
          if(j%2==0 || ((i-j)%2==0)) continue; //若一个加数是偶数，不进行素数判断 
          if(prime[j]==1 && prime[i-j]==1) //若两个加数都是素数 
          {
              printf("%d=%d+%d\n",i,j,i-j);//输出素数 
              flag=0; //清除标志 
              break; 
          }
        }
        if(1==flag)//若某个偶数不是由两个奇数组成 
            printf("找到一个不符合要求的偶数:%d\n",i); 
    }
    getch();
    return 0;
}
