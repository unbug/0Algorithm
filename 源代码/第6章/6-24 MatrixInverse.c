#include <stdio.h>
#include <malloc.h>
double Determinant(double *arr,int n) //求n阶矩阵的行列式 
{
    int row,column,m,lop=0;
    double result=0,mid=1;
    if(n!=1)
    {
        lop=(n==2)?1:n; 
        for(m=0;m<lop;m++)
        {
            mid=1; //顺序求和
            row=0;
            column=m;
            while(row<n)
            {
                mid=mid*arr[row*n+column%n];
                row++;
                column++;
            }
            result+=mid;
        }
        for(m=0;m<lop;m++)
        {
            mid=1; //逆序相减
            row=0;
            column=n-1-m+n;
            while(row<n)
            {
                mid=mid*arr[row*n+column%n];
                row++;
                column--;
            }
            result-=mid;
        }
    }
    else
        result=*arr;
    return(result); //返回行列式的值 
}
double Residue(double *arr, int m,int n,int k)
{
    int len,i,j,sign=1;
    double result=0;
    double *p1,*p2;
    len=(k-1)*(k-1);
    p1=(double *)malloc(len*sizeof(double));     //分配内存单元
    p2=p1;
    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
        {
            if(i!=m && j!=n)
                *p2++=arr[i*k+j];
        }
    sign=((m+n)%2==0)?1:-1;
    result=(double)sign*Determinant(p1,k-1); //计算代数余子式 
    free(p1); //释放内存 
    return(result); //返回代数余子式的值 
}
void PrintMatrix(double *arr1,int row) //输出矩阵 
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++)//输出row作为一行 
            printf("%6G ",*arr1++);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    double *arr1,*arr2; //定义数组首地址指针变量
    int row,num; //定义矩阵行数数row及矩阵元素个数
    int i,j;
    double determinant;//定义矩阵的行列式

    printf("输入矩阵的行数: ");
    scanf("%d",&row);  //输入矩阵行数 
    num=2*row*row;
    arr1=(double *)malloc(num*sizeof(double));//分配保存n*2n阶矩阵的内存单元
    if(arr1==NULL) //分配内存失败 
    {
        printf("分配内存失败!\n");
        exit(0);
    }                 
    arr2=arr1; //使指针arr2指向同一矩阵区域
    for(i=0;i<row;i++) //输入矩阵各元素的值
    {
        printf("输入第%d行的%个元素:",i+1,row);
        for(j=0;j<row;j++) //将矩阵按一维矩阵形式保存 
            scanf("%lf",arr2++);
    }
    printf("\n原矩阵为:\n");
    PrintMatrix(arr1,row);//输出原矩阵
    determinant=Determinant(arr1,row); //求整个矩阵的行列式
    if(determinant==0)
    {
        printf("行列式值为0,没有逆矩阵!\n");
        exit(0);
    }    
    arr2=arr1+row*row; //使指针arr2指向矩阵的后半部分 
    for(i=0;i<row;i++) //求逆矩阵
        for(j=0;j<row;j++)
            arr2[j*row+i]=Residue(arr1,i,j,row)/determinant;
    printf("行列式为:%G\n",determinant);
    arr2=arr1+row*row; //指向矩阵右侧 
    printf("\n逆矩阵为:\n"); 
    PrintMatrix(arr2,row); //打印该矩阵
    free(arr1); 
    getch();
    return 0;
}
