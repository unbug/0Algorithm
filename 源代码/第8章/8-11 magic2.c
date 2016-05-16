#include <stdio.h>  
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int Magic2(int **magic,int n)
{
    int i,j,k=1;
    if(n%4!=0) //��������4������ 
        return 0;
    for(i=0;i<n;i++)//��ʼ�������� 
    {
        if(i<=n/4-1 || i>n/4-1+n/2) //���²��ְ�˳���������� 
        {
            for(j=0;j<n;j++)
                magic[i][j]=k++;
        }
        else//�м�����а�������������(ˮƽ��ת) 
        {
            for(j=n-1;j>=0;j--)
               magic[i][j]=k++;
        }
    }
    for(j=n/4;j<(n/4+n/2);j++)//���м�������н������·�ת 
        for(i=0;i<n/2;i++)
            swap(&magic[i][j],&magic[n-i-1][j]); //�������� 
    return 1;
}
int main()   
{
    int i,j,n,sum;
    int **magic;
    printf("����Ľ���:");
    scanf("%d",&n);
    if(!(magic=(int **)malloc(n*sizeof(int*)))) //���䱣�����ָ����ڴ� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(1);
    }
    for(i=0;i<n;++i) //���䱣��ָ��������ڴ� 
    {
        if(!(magic[i]=(int *)malloc(n*sizeof(int))))
        {
            printf("�ڴ����ʧ��!\n"); 
            exit(1);
        }
    }
    if(Magic2(magic,n)) //���ú�����䷽�� 
    {
        for(i=0;i<n;i++) //������� 
        {
           for(j=0;j<n;j++)
               printf("%4d",magic[i][j]);
           printf("\n");
        }
        sum=0;
        for(i=0;i<n;i++) //ͳ�ƶԽ��ߵĺ� 
            sum+=magic[i][i];
        printf("\n���С��С��Խ��ߵĺ�Ϊ:%d\n",sum);
    }
    else //���ɷ���ʧ�� 
        printf("����ħ����ʧ�ܣ�����������Ľ�������ȷ!\n"); 
    getch();
    return 0;
}
