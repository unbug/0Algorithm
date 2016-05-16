#include <stdio.h>
int main()
{
    int i,j,k,num;
    int *arr;
    printf("输入非0元素的数量:"); 
    scanf("%d",&num);
    arr=(int *)malloc(sizeof(int)*(num+1)*3);
    for(i=1;i<=num;i++)
    {
        
        printf("输入第%d个三元组数据",i);
        scanf("%d%d%d",&arr[i*3],&arr[i*3+1],&arr[i*3+2]);
    }
    for(i=1;i<=num;i++) //获取稀疏矩阵的行和列 
    {
        if(arr[0]<arr[i*3]) arr[0]=arr[i*3]; //保存矩阵的行 
        if(arr[1]<arr[i*3+1]) arr[1]=arr[i*3+1]; //保存矩阵的列 
    }
    arr[2]=num;//元素数量 
    printf("稀疏矩阵三元组:\n");
    for(i=0;i<=num;i++) //输出三元组数据 
    {
        for(j=0;j<3;j++)
            printf("%4d", arr[i*3+j]);
        printf("\n");
    }
    printf("稀疏矩阵:\n");
    k=1;
    for(i=0;i<=arr[0];i++) //稀疏矩阵的行数 
    {
        for(j=0;j<=arr[1];j++) //稀疏矩阵的列数 
        {
            if(i==arr[k*3] && j==arr[k*3+1] && k<=arr[2])
            {
                printf("%4d ",arr[k*3+2]); //输出非0数据 
                k++;
            }
            else
                printf("%4d ", 0); //输出0 
        }
        printf("\n");
    }
    getch();
    return 0;
}

