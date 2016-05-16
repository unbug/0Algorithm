#include <stdio.h>
void MatrixMul(int **a,int **b, int **c, int x, int y, int z)
{
     int i,j,k;
     for (j=0;j<y;j++) //���Ŀ�����C������ 
         for(i=0;i<x;i++)
             c[j][i]=0;
     for(j=0;j<y;j++) //���о���˷����� 
         for(i=0;i<x;i++)
             for(k=0;k<z;k++)
                 c[j][i]+= a[j][k]*b[k][i];
} 
int main()
{
    int i,j,k,tmp;
    int ARow,ACol; //����A���С��� 
    int BRow,BCol; //����B���С��� 
    int CRow,CCol; //����C������ 
    int **a,**b,**c; //�ֱ�ָ��3��������ڴ�
    printf("�������A������������:");//�������A������������
    scanf("%d %d",&ARow,&ACol);
    BRow=ACol; //����B���������ھ���A������
    printf("�������B������:");//�������B������
    scanf("%d",&BCol);
    CRow=ARow; //Ŀ�����C������ 
    CCol=BCol; //Ŀ�����C������ 
    c=(int **)malloc(sizeof(int *)*CRow); //���䱣�����C�Ķ���ָ��洢�ռ� 
    for(j=0;j<CRow;j++)  //����һ��ָ���ڴ�ռ� 
        c[j]=(int *)malloc(sizeof(int)*CCol);
    a=(int **)malloc(sizeof(int *)*ARow);//���䱣�����A�Ķ���ָ�� 
    for(j=0;j<ARow;j++)
        a[j]=(int *)malloc(sizeof(int)*ACol);
    b=(int **)malloc(sizeof(int *)*BRow); //���䱣�����B�Ķ���ָ�� 
    for(j=0;j<BRow;j++)
        b[j]=(int *)malloc(sizeof(int)*BCol);
    if(!b[BRow-1]) //�ж��ڴ��Ƿ����ɹ� 
    {
        printf("�����ڴ�ʧ��!\n");
        exit(0);
    }
    printf("�������A������(%d��%d��):\n",ARow,ACol);//����A��Ԫ��
    for(j=0;j<ARow;j++)
        for (i=0;i<ACol;i++)
        {
            scanf("%d",&tmp);
            a[j][i]=tmp;
        }
    printf("�������A������(%d��%d��):\n",BRow,BCol);//����B��Ԫ��
    for(j=0;j<BRow;j++)
        for (i=0;i<BCol;i++)
        {
            scanf("%d",&tmp);
            b[j][i]=tmp;
        }
    MatrixMul(a,b,c,CCol,CRow,ACol);//���þ���˷����� 
    printf("������˵Ľ��:\n"); 
    for(j=0;j<CRow;j++) //�������˷���� 
    {
        for(i=0;i<CCol;i++)
            printf("%d ",c[j][i]);
        printf("\n"); 
    }
    getch();
    return 0;
}
