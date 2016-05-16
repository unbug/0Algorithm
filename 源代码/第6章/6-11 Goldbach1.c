#include <stdio.h>
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
int main()
{
    int n,i,j,flag;
    printf("输入一个最大范围n(n>=6):"); 
    scanf("%d",&n); 
    if(n<6) //判断输入数据是否合法 
    {
        printf("数据输入错误!\n");
        return 0;
    }
    for(i=6;i<=n;i+=2) //从6开始，循环验证各偶数 
    {
        flag=1;
        for(j=2;j<=i/2;j++) //判断组成每个数的两个加数 
        {
          if(j%2==0 || ((i-j)%2==0)) continue; //若一个加数是偶数，不进行素数判断 
          if(PrimeNum(j) && PrimeNum(i-j)) //若两个加数都是素数 
          {
              printf("%d=%d+%d\n",i,j,i-j);//输出素数 
              flag=0; //清除标志 
              break; 
          }
        }
        if(1==flag)//若某个偶数不是由两个奇数组成 
            printf("找到一个不符合要求的偶数:%d\n",j); 
    }
    getch();
    return 0;
}
