#include <stdio.h>
void MatrixMul(int **a,int **b, int **c, int x, int y, int z)
{
     int i,j,k;
     for (j=0;j<y;j++) //清空目标矩阵C的内容 
         for(i=0;i<x;i++)
             c[j][i]=0;
     for(j=0;j<y;j++) //进行矩阵乘法运算 
         for(i=0;i<x;i++)
             for(k=0;k<z;k++)
                 c[j][i]+= a[j][k]*b[k][i];
} 
int main()
{
    int i,j,k,tmp;
    int ARow,ACol; //矩阵A的行、列 
    int BRow,BCol; //矩阵B的行、列 
    int CRow,CCol; //矩阵C的行列 
    int **a,**b,**c; //分别指向3个矩阵的内存
    printf("输入矩阵A的行数和列数:");//输入矩阵A的行数、列数
    scanf("%d %d",&ARow,&ACol);
    BRow=ACol; //矩阵B的行数等于矩阵A的列数
    printf("输入矩阵B的列数:");//输入矩阵B的列数
    scanf("%d",&BCol);
    CRow=ARow; //目标矩阵C的行数 
    CCol=BCol; //目标矩阵C的列数 
    c=(int **)malloc(sizeof(int *)*CRow); //分配保存矩阵C的二级指针存储空间 
    for(j=0;j<CRow;j++)  //分配一级指针内存空间 
        c[j]=(int *)malloc(sizeof(int)*CCol);
    a=(int **)malloc(sizeof(int *)*ARow);//分配保存矩阵A的二级指针 
    for(j=0;j<ARow;j++)
        a[j]=(int *)malloc(sizeof(int)*ACol);
    b=(int **)malloc(sizeof(int *)*BRow); //分配保存矩阵B的二级指针 
    for(j=0;j<BRow;j++)
        b[j]=(int *)malloc(sizeof(int)*BCol);
    if(!b[BRow-1]) //判断内存是否分配成功 
    {
        printf("分配内存失败!\n");
        exit(0);
    }
    printf("输入矩阵A的数据(%d行%d列):\n",ARow,ACol);//输入A阵元素
    for(j=0;j<ARow;j++)
        for (i=0;i<ACol;i++)
        {
            scanf("%d",&tmp);
            a[j][i]=tmp;
        }
    printf("输入矩阵A的数据(%d行%d列):\n",BRow,BCol);//输入B阵元素
    for(j=0;j<BRow;j++)
        for (i=0;i<BCol;i++)
        {
            scanf("%d",&tmp);
            b[j][i]=tmp;
        }
    MatrixMul(a,b,c,CCol,CRow,ACol);//调用矩阵乘法函数 
    printf("矩阵相乘的结果:\n"); 
    for(j=0;j<CRow;j++) //输出矩阵乘法结果 
    {
        for(i=0;i<CCol;i++)
            printf("%d ",c[j][i]);
        printf("\n"); 
    }
    getch();
    return 0;
}
