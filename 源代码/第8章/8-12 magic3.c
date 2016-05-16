#include <stdio.h>
void swap(int *a,int *b)    //交换数据 
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int Magic3(int **magic,int n)
{
    int i,j,sn;
    if((n-2)%4!=0)//不是4K+2阶 
        return 0;
    sn=(n-2)/4;
    for(i=0;i<n;i++)       //第1步,按顺序填入数据 
        for(j=0;j<n;j++)
            magic[i][j]=i*n+j+1;
    for(i=sn+1;i<=3*sn;i++)     //第2步,将井字左右部分进行翻转 
    {
        for(j=0;j<=n/2-1;j++)
        {
            if(j!=sn)
                swap(&magic[i][j],&magic[i][n-1-j]);
        }
    }
    for(i=sn+1;i<=3*sn;i++) //第2步,井字上下部分进行翻转 
        for(j=0;j<=n/2-1;j++)
            if(j!=sn)
                swap(&magic[j][i],&magic[n-1-j][i]);    
    for(i=0;i<=sn-1;i++) //第3步,将井字分隔线之横列及第k+2列两侧数字对调 
    {
        swap(&magic[sn][i],&magic[sn][n-1-i]);
        swap(&magic[n-1-sn][i],&magic[n-1-sn][n-1-i]);
        swap(&magic[sn+1][i],&magic[sn+1][n-1-i]);        
    }
	for(i=sn+1;i<=n-1-sn-1;i++) //两横列中央数字上下对调 
	    swap(&magic[sn][i],&magic[n-1-sn][i]);
    for(i=0;i<=n/2-1;i++) //左边列除交叉点外的数字垂直翻转 
        if(i!=sn)
            swap(&magic[i][sn],&magic[n-1-i][sn]);    
    swap(&magic[sn][0],&magic[n-1-sn][0]); //第4步,将井字横线左侧数字上下对调 
    for(i=sn+1;i<=n/2-1;i++) //井字横线中央数字翻转 
        swap(&magic[sn][i],&magic[sn][n-1-i]);
    for(i=sn+1;i<=n-1-sn-1;i++) //井字分隔线纵向中央数字除第2k+1列外左右对调 
        if(i!=n/2-1)
            swap(&magic[i][sn],&magic[i][n-1-sn]);    
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
    if(Magic3(magic,n)) //调用函数填充方阵 
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




