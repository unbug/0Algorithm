#include <stdio.h>
int PrimeNum(int i); //�ж����� 
int main()
{
    int i,j,t,k,s;
    printf("1000���ڵĻ���������:\n");
    for(i=0;i<=9;++i) //��λ
        for(j=0;j<=9;++j) //ʮλ
        {
            if(i==0 && j==0) //��ǰ��λ��Ϊ0 
                continue; //����ѭ�� 
            for(k=0;k<=9;++k)//��λ 
            {
                if(i!=0 && i!=k) //����λ��Ϊ0,�Ұ�λ�͸�λ���� 
                    continue; //����ѭ�� 
                s=i*100+j*10+k; //����Ϊһ������ 
                t=k*100+j*10+i; //���Ϊ��һ����������������
                if(i==0) //�����ĵ�һλΪ0���Ƕ�λ����
                     t/=10; //����������ɵ��� 
                if(s>10 && s==t) //������10��Ϊ������
                    if(PrimeNum(s)==1)//��������
                        printf("%d\t",s); //��������� 
            }
        }
    getch();
    return 0;
}
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
