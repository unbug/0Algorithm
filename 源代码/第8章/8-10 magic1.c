#include <stdio.h>  
int Magic1(int **magic,int n)
{
    if(n%2==0) //n为偶数，返回 
        return 0;
    int i=0,k=1;  //i为行号 
    int j=(n-1)/2; //计算列序号（位于行的中间） 
    magic[i][j]=k; //1行中位置添加1 
    while(k<n*n)
    {
        if(i-1<0 && j+1>=n) //超过上边区域，且列超过右边区域 
        {
            i++; //向下移一行 
            magic[i][j]=++k; //填数 
            continue;
        }
        if(i-1<0) //行超过上边区域 
            i=n-1; //到最后一行 
        else
            i--; //上移一行 
        if(j+1>=n) //列超过右边区域 
            j=0; //移到左边 
        else
            j++; //右移一列 
        if(magic[i][j]==-1) //若为空 
            magic[i][j]=++k; //填入数 
        else//若不为空 
        {
            i+=2; //下移两行 
            j--; //左移一列 
            magic[i][j]=++k; //填数 
        }
    }
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
    for(i=0;i<n;i++) //初始化方阵 
       for(j=0;j<n;j++)
           magic[i][j]=-1;
    if(Magic1(magic,n)) //调用函数填充方阵 
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
