#include <stdio.h> 
#include <stdlib.h> 

int main()
{
    int row, column,i,ARow,ACol,loc,tmp;
    
    int **arr1,*arr2; //分别指向2个矩阵的内存
    printf("输入矩阵的行数和列数:");//输入矩阵A的行数、列数
    scanf("%d %d",&ARow,&ACol);
    arr1=(int **)malloc(sizeof(int *)*ARow); //分配保存矩阵的二级指针存储空间 
    for(i=0;i<ARow;i++)  //分配一级指针内存空间 
        arr1[i]=(int *)malloc(sizeof(int)*ACol);
    arr2=(int *)malloc(sizeof(int)*ARow*ACol);//分配保存一维矩阵的存储空间
    if(arr1==NULL) //判断内存是否分配成功 
    {
        printf("分配内存失败!\n");
        exit(0);
    }
    printf("输入二维矩阵的数据(%d行%d列):\n",ARow,ACol);//输入A阵元素
    for(row=0;row<ARow;row++)
        for(column=0;column<ACol;column++)
        {
            scanf("%d",&tmp);
            arr1[row][column]=tmp;
        }
    printf("\n以行为主转换为一维矩阵:\n");
    for(row=0;row<ARow;row++)//按行循环 
    {
        for(column=0;column<ACol;column++) //按列循环 
        {
            loc=column+row*ACol; //转换为一维矩阵的序号 
            arr2[loc]=arr1[row][column]; //保存元素 
        }
    }
    for(i=0;i<ARow*ACol;i++) //输出一维矩阵 
        printf("%d ", arr2[i]);
    printf("\n以列为主转换为一维矩阵:\n");
    for(column=0;column<ACol;column++)
    {
        for(row=0;row<ARow;row++)
        {
            loc=row+column*ARow; //转换为一维矩阵的序号 
            arr2[loc]=arr1[row][column]; //保存元素
        }
    }
    for(i=0;i<ARow*ACol;i++) //输出一维矩阵 
        printf("%d ", arr2[i]);
    printf("\n");
    getch();
    return 0;
}
