#include <stdio.h>  
int Magic1(int **magic,int n)
{
    if(n%2==0) //nΪż�������� 
        return 0;
    int i=0,k=1;  //iΪ�к� 
    int j=(n-1)/2; //��������ţ�λ���е��м䣩 
    magic[i][j]=k; //1����λ�����1 
    while(k<n*n)
    {
        if(i-1<0 && j+1>=n) //�����ϱ��������г����ұ����� 
        {
            i++; //������һ�� 
            magic[i][j]=++k; //���� 
            continue;
        }
        if(i-1<0) //�г����ϱ����� 
            i=n-1; //�����һ�� 
        else
            i--; //����һ�� 
        if(j+1>=n) //�г����ұ����� 
            j=0; //�Ƶ���� 
        else
            j++; //����һ�� 
        if(magic[i][j]==-1) //��Ϊ�� 
            magic[i][j]=++k; //������ 
        else//����Ϊ�� 
        {
            i+=2; //�������� 
            j--; //����һ�� 
            magic[i][j]=++k; //���� 
        }
    }
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
    for(i=0;i<n;i++) //��ʼ������ 
       for(j=0;j<n;j++)
           magic[i][j]=-1;
    if(Magic1(magic,n)) //���ú�����䷽�� 
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
