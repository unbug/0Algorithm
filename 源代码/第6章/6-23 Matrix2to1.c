#include <stdio.h> 
#include <stdlib.h> 

int main()
{
    int row, column,i,ARow,ACol,loc,tmp;
    
    int **arr1,*arr2; //�ֱ�ָ��2��������ڴ�
    printf("������������������:");//�������A������������
    scanf("%d %d",&ARow,&ACol);
    arr1=(int **)malloc(sizeof(int *)*ARow); //���䱣�����Ķ���ָ��洢�ռ� 
    for(i=0;i<ARow;i++)  //����һ��ָ���ڴ�ռ� 
        arr1[i]=(int *)malloc(sizeof(int)*ACol);
    arr2=(int *)malloc(sizeof(int)*ARow*ACol);//���䱣��һά����Ĵ洢�ռ�
    if(arr1==NULL) //�ж��ڴ��Ƿ����ɹ� 
    {
        printf("�����ڴ�ʧ��!\n");
        exit(0);
    }
    printf("�����ά���������(%d��%d��):\n",ARow,ACol);//����A��Ԫ��
    for(row=0;row<ARow;row++)
        for(column=0;column<ACol;column++)
        {
            scanf("%d",&tmp);
            arr1[row][column]=tmp;
        }
    printf("\n����Ϊ��ת��Ϊһά����:\n");
    for(row=0;row<ARow;row++)//����ѭ�� 
    {
        for(column=0;column<ACol;column++) //����ѭ�� 
        {
            loc=column+row*ACol; //ת��Ϊһά�������� 
            arr2[loc]=arr1[row][column]; //����Ԫ�� 
        }
    }
    for(i=0;i<ARow*ACol;i++) //���һά���� 
        printf("%d ", arr2[i]);
    printf("\n����Ϊ��ת��Ϊһά����:\n");
    for(column=0;column<ACol;column++)
    {
        for(row=0;row<ARow;row++)
        {
            loc=row+column*ARow; //ת��Ϊһά�������� 
            arr2[loc]=arr1[row][column]; //����Ԫ��
        }
    }
    for(i=0;i<ARow*ACol;i++) //���һά���� 
        printf("%d ", arr2[i]);
    printf("\n");
    getch();
    return 0;
}
