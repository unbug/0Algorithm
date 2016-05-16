#include <stdio.h>
#define MAXN 100  //���������� 
int arr[MAXN][MAXN]; //����������� 
int result[MAXN]; //���淽�̵Ľ�
int unuse_result[MAXN];//�ж��Ƿ��ǲ�ȷ���ı�Ԫ
int unuse_num;
void swap(int *a,int *b) //�������� 
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int gcd(int a,int b) //�������Լ�� 
{
    int t;
    while(b!= 0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int lcm(int a,int b) //������С������ 
{
    return a*b/gcd(a,b);
}
void debug(int equ,int var)
{
     int i,j;
     for(i=0;i<equ;i++)
     {
         for(j=0;j<var+1;j++)
            printf("%d ",arr[i][j]);
         printf("\n");
     }
     printf("\n");
}
int Gauss(int equ,int var)
{
    int i,j,k,col;
    int max_r,ta,tb,lcm1;
    int temp,unuse_x_num,unuse_index;
    col=0; //�赱ǰ�����е�ֵΪ0����ʾ�ӵ�1�п�ʼ���� 
    for(k=0;k<equ && col<var;k++,col++) //ѭ����������е���
    {    
        max_r=k; //����ֵ����� 
        for(i=k+1;i<equ;i++)
            if(abs(arr[i][col])>abs(arr[max_r][col]))
                max_r=i; //�������ֵ�����к� 
        if(max_r!=k) //����в��ǵ�ǰ�У������k�н���
            for(j=k;j<var+1;j++)
                swap(&arr[k][j], &arr[max_r][j]); //�����������Ͻ����� 
        if(arr[k][col]==0) //˵��col�е�k������ȫ��0�ˣ�����ǰ�е���һ��
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++) //����Ҫɾ������
        {
            if(arr[i][col]!=0) //���в�Ϊ0��������Ԫ���� 
            {
                lcm1=lcm(abs(arr[i][col]),abs(arr[k][col])); //����С������ 
                ta=lcm1/abs(arr[i][col]);
                tb=lcm1/abs(arr[k][col]);
                if(arr[i][col]*arr[k][col]<0) //���Ϊ������ʾ�������Ų�ͬ 
                    tb=-tb; //��ŵ���������������
                for(j=col;j<var+1;j++)                
                    arr[i][j]=arr[i][j]*ta-arr[k][j]*tb;
            }
        }
    }
    for(i=k;i<equ;i++)//�ж����һ�����һ�У�����Ϊ0����ʾ�޽�
        if(arr[i][col]!=0) 
            return -1; //�����޽�
     if(k<var)//���ɱ�Ԫ��var-k��������ȷ���ı�Ԫ������var-k��.
    {
        for(i=k-1;i>=0;i--)
        {
            unuse_x_num=0; //�жϸ����в�ȷ������������������1�������޷����
            for(j=0;j<var;j++)
            {
                if(arr[i][j]!=0 && unuse_result[j])
                {
                    unuse_x_num++;
                    unuse_index=j;
                }
            }
            if(unuse_x_num>1)
                continue; // �޷�����ȷ���Ľ� 
            temp=arr[i][var];
            for(j=0;j<var;j++)
            {
                if(arr[i][j]!=0 && j!=unuse_index)
                    temp-=arr[i][j]*result[j];
            }
            result[unuse_index]=temp/arr[i][unuse_index]; // ����ñ�Ԫ.
            unuse_result[unuse_index]=0; //�ñ�Ԫ��ȷ����
        }
        return var-k; //���ɱ�Ԫ��var-k��
    }
    for(i=var-1;i>=0;i--) //�ش���� 
    {
        temp=arr[i][var];
        for(j=i+1;j<var;j++)
        {
            if(arr[i][j]!=0)
                temp-=arr[i][j]*result[j];
        }
        if(temp % arr[i][i]!=0) //���������� 
            return -2; //�����и������⣬����������
        result[i]=temp/arr[i][i];
    }
    return 0;
}
int main()
{
    int i,j;
    int equ, var;
    printf("������:");
    scanf("%d",&equ); //���뷽������
    printf("������:");
    scanf("%d",&var);  //����������� 
    for(i=0;i<equ;i++) //ѭ����������̵�ϵ�� 
    {
        printf("��%d�����̵�ϵ��:",i+1); 
        for(j=0;j<var+1;j++) //ѭ������һ�����̵�ϵ�� 
        {
            scanf("%d", &arr[i][j]);
        }
    }
    unuse_num=Gauss(equ,var); //���ø�˹���� 
    if(unuse_num==-1) //�޽� 
        printf("�޽�!\n");
    else if(unuse_num==-2) //ֻ�и������� 
        printf("�и������⣬��������!\n");
    else if(unuse_num>0) //������ 
    {
         printf("������! ���ɱ�������Ϊ%d\n",unuse_num);
         for(i=0;i<var;i++)
         {
             if(unuse_result[i])
                 printf("x%d �ǲ�ȷ����\n",i+1);
             else
                 printf("x%d: %d\n",i+1,result[i]);
         }
    }
    else
    {
        for(i=0;i<var;i++) //����� 
        {
            printf("x%d=%d\n",i+1,result[i]);
        }
    }
    printf("\n");
    getch();
    return 0;
}
