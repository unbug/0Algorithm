#include <stdio.h>
#include <malloc.h>
double Determinant(double *arr,int n) //��n�׾��������ʽ 
{
    int row,column,m,lop=0;
    double result=0,mid=1;
    if(n!=1)
    {
        lop=(n==2)?1:n; 
        for(m=0;m<lop;m++)
        {
            mid=1; //˳�����
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
            mid=1; //�������
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
    return(result); //��������ʽ��ֵ 
}
double Residue(double *arr, int m,int n,int k)
{
    int len,i,j,sign=1;
    double result=0;
    double *p1,*p2;
    len=(k-1)*(k-1);
    p1=(double *)malloc(len*sizeof(double));     //�����ڴ浥Ԫ
    p2=p1;
    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
        {
            if(i!=m && j!=n)
                *p2++=arr[i*k+j];
        }
    sign=((m+n)%2==0)?1:-1;
    result=(double)sign*Determinant(p1,k-1); //�����������ʽ 
    free(p1); //�ͷ��ڴ� 
    return(result); //���ش�������ʽ��ֵ 
}
void PrintMatrix(double *arr1,int row) //������� 
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++)//���row��Ϊһ�� 
            printf("%6G ",*arr1++);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    double *arr1,*arr2; //���������׵�ַָ�����
    int row,num; //�������������row������Ԫ�ظ���
    int i,j;
    double determinant;//������������ʽ

    printf("������������: ");
    scanf("%d",&row);  //����������� 
    num=2*row*row;
    arr1=(double *)malloc(num*sizeof(double));//���䱣��n*2n�׾�����ڴ浥Ԫ
    if(arr1==NULL) //�����ڴ�ʧ�� 
    {
        printf("�����ڴ�ʧ��!\n");
        exit(0);
    }                 
    arr2=arr1; //ʹָ��arr2ָ��ͬһ��������
    for(i=0;i<row;i++) //��������Ԫ�ص�ֵ
    {
        printf("�����%d�е�%��Ԫ��:",i+1,row);
        for(j=0;j<row;j++) //������һά������ʽ���� 
            scanf("%lf",arr2++);
    }
    printf("\nԭ����Ϊ:\n");
    PrintMatrix(arr1,row);//���ԭ����
    determinant=Determinant(arr1,row); //���������������ʽ
    if(determinant==0)
    {
        printf("����ʽֵΪ0,û�������!\n");
        exit(0);
    }    
    arr2=arr1+row*row; //ʹָ��arr2ָ�����ĺ�벿�� 
    for(i=0;i<row;i++) //�������
        for(j=0;j<row;j++)
            arr2[j*row+i]=Residue(arr1,i,j,row)/determinant;
    printf("����ʽΪ:%G\n",determinant);
    arr2=arr1+row*row; //ָ������Ҳ� 
    printf("\n�����Ϊ:\n"); 
    PrintMatrix(arr2,row); //��ӡ�þ���
    free(arr1); 
    getch();
    return 0;
}
