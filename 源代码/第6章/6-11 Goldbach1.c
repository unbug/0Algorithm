#include <stdio.h>
int PrimeNum(int i) //�ж���i�Ƿ�Ϊ���� 
{
    int j,flag=1;
    for(j=2;j*j<i;j++) //ѭ������ÿ���� 
    {
        if(i%j==0) //i�ܱ�j��������ʾ�������� 
        {
            flag=0;
            break; 
        }
    }
    return flag; //���ؽ�� 
}
int main()
{
    int n,i,j,flag;
    printf("����һ�����Χn(n>=6):"); 
    scanf("%d",&n); 
    if(n<6) //�ж����������Ƿ�Ϸ� 
    {
        printf("�����������!\n");
        return 0;
    }
    for(i=6;i<=n;i+=2) //��6��ʼ��ѭ����֤��ż�� 
    {
        flag=1;
        for(j=2;j<=i/2;j++) //�ж����ÿ�������������� 
        {
          if(j%2==0 || ((i-j)%2==0)) continue; //��һ��������ż���������������ж� 
          if(PrimeNum(j) && PrimeNum(i-j)) //������������������ 
          {
              printf("%d=%d+%d\n",i,j,i-j);//������� 
              flag=0; //�����־ 
              break; 
          }
        }
        if(1==flag)//��ĳ��ż������������������� 
            printf("�ҵ�һ��������Ҫ���ż��:%d\n",j); 
    }
    getch();
    return 0;
}
