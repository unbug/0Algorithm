#include <stdio.h>
int main()
{
    int i,j,k,num;
    int *arr;
    printf("�����0Ԫ�ص�����:"); 
    scanf("%d",&num);
    arr=(int *)malloc(sizeof(int)*(num+1)*3);
    for(i=1;i<=num;i++)
    {
        
        printf("�����%d����Ԫ������",i);
        scanf("%d%d%d",&arr[i*3],&arr[i*3+1],&arr[i*3+2]);
    }
    for(i=1;i<=num;i++) //��ȡϡ�������к��� 
    {
        if(arr[0]<arr[i*3]) arr[0]=arr[i*3]; //���������� 
        if(arr[1]<arr[i*3+1]) arr[1]=arr[i*3+1]; //���������� 
    }
    arr[2]=num;//Ԫ������ 
    printf("ϡ�������Ԫ��:\n");
    for(i=0;i<=num;i++) //�����Ԫ������ 
    {
        for(j=0;j<3;j++)
            printf("%4d", arr[i*3+j]);
        printf("\n");
    }
    printf("ϡ�����:\n");
    k=1;
    for(i=0;i<=arr[0];i++) //ϡ���������� 
    {
        for(j=0;j<=arr[1];j++) //ϡ���������� 
        {
            if(i==arr[k*3] && j==arr[k*3+1] && k<=arr[2])
            {
                printf("%4d ",arr[k*3+2]); //�����0���� 
                k++;
            }
            else
                printf("%4d ", 0); //���0 
        }
        printf("\n");
    }
    getch();
    return 0;
}

