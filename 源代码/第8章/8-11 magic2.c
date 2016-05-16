#include <stdio.h>  
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int Magic2(int **magic,int n)
{
    int i,j,k=1;
    if(n%4!=0) //阶数不是4个倍数 
        return 0;
    for(i=0;i<n;i++)//初始填入数字 
    {
        if(i<=n/4-1 || i>n/4-1+n/2) //上下部分按顺序填入数字 
        {
            for(j=0;j<n;j++)
                magic[i][j]=k++;
        }
        else//中间半数行按例序填入数字(水平翻转) 
        {
            for(j=n-1;j>=0;j--)
               magic[i][j]=k++;
        }
    }
    for(j=n/4;j<(n/4+n/2);j++)//将中间半数的列进行上下翻转 
        for(i=0;i<n/2;i++)
            swap(&magic[i][j],&magic[n-i-1][j]); //交换数据 
    return 1;
}
int main()   
{
    int i,j,n,sum;
    int **magic;
    printf("方阵的阶数:");
    scanf("%d",&n);
    if(!(magic=(int **)malloc(n*sizeof(int*)))) //分配保存二级指针的内存 
    {
        printf("内存分配失败!\n");
        exit(1);
    }
    for(i=0;i<n;++i) //分配保存指针的数组内存 
    {
        if(!(magic[i]=(int *)malloc(n*sizeof(int))))
        {
            printf("内存分配失败!\n"); 
            exit(1);
        }
    }
    if(Magic2(magic,n)) //调用函数填充方阵 
    {
        for(i=0;i<n;i++) //输出方阵 
        {
           for(j=0;j<n;j++)
               printf("%4d",magic[i][j]);
           printf("\n");
        }
        sum=0;
        for(i=0;i<n;i++) //统计对角线的和 
            sum+=magic[i][i];
        printf("\n各行、列、对角线的和为:%d\n",sum);
    }
    else //生成方阵失败 
        printf("生成魔方阵失败，可能是输入的阶数不正确!\n"); 
    getch();
    return 0;
}
