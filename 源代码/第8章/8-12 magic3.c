#include <stdio.h>
void swap(int *a,int *b)    //�������� 
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int Magic3(int **magic,int n)
{
    int i,j,sn;
    if((n-2)%4!=0)//����4K+2�� 
        return 0;
    sn=(n-2)/4;
    for(i=0;i<n;i++)       //��1��,��˳���������� 
        for(j=0;j<n;j++)
            magic[i][j]=i*n+j+1;
    for(i=sn+1;i<=3*sn;i++)     //��2��,���������Ҳ��ֽ��з�ת 
    {
        for(j=0;j<=n/2-1;j++)
        {
            if(j!=sn)
                swap(&magic[i][j],&magic[i][n-1-j]);
        }
    }
    for(i=sn+1;i<=3*sn;i++) //��2��,�������²��ֽ��з�ת 
        for(j=0;j<=n/2-1;j++)
            if(j!=sn)
                swap(&magic[j][i],&magic[n-1-j][i]);    
    for(i=0;i<=sn-1;i++) //��3��,�����ַָ���֮���м���k+2���������ֶԵ� 
    {
        swap(&magic[sn][i],&magic[sn][n-1-i]);
        swap(&magic[n-1-sn][i],&magic[n-1-sn][n-1-i]);
        swap(&magic[sn+1][i],&magic[sn+1][n-1-i]);        
    }
	for(i=sn+1;i<=n-1-sn-1;i++) //�����������������¶Ե� 
	    swap(&magic[sn][i],&magic[n-1-sn][i]);
    for(i=0;i<=n/2-1;i++) //����г������������ִ�ֱ��ת 
        if(i!=sn)
            swap(&magic[i][sn],&magic[n-1-i][sn]);    
    swap(&magic[sn][0],&magic[n-1-sn][0]); //��4��,�����ֺ�������������¶Ե� 
    for(i=sn+1;i<=n/2-1;i++) //���ֺ����������ַ�ת 
        swap(&magic[sn][i],&magic[sn][n-1-i]);
    for(i=sn+1;i<=n-1-sn-1;i++) //���ַָ��������������ֳ���2k+1�������ҶԵ� 
        if(i!=n/2-1)
            swap(&magic[i][sn],&magic[i][n-1-sn]);    
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
    if(Magic3(magic,n)) //���ú�����䷽�� 
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




