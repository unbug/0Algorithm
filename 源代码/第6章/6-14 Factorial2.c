#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void carry(int bit[],int pos)//�����λ
{
    int i,carray=0;
    for(i=0;i<=pos;i++) //��0~pos��λ����Ƿ���Ҫ��λ 
    {
        bit[i]+=carray; //�ۼӽ�λ 
        if(bit[i]<=9)//С��9����λ
            carray=0;
        else if(bit[i]>9 && i<pos)//����9���������λ
        {
            carray=bit[i]/10; //�����λֵ 
            bit[i]=bit[i]%10;//�õ���λ��һλ�� 
        }
        else if(bit[i]>9 && i>=pos)//����9�������λ
        {
            while(bit[i]>9) //ѭ����ǰ��λ 
            {
                carray=bit[i]/10; //�����λֵ 
                bit[i]=bit[i]%10; //��ǰ��һλ�� 
                i++;
                bit[i]=carray; //����һλ�����λ��ֵ 
            }
        }
    }
}
int main()
{
    int num,pos,digit,i,j,m,n;
    double sum=0;
    int *fact;
    printf("���������׳˵�����Num=");
    scanf("%d",&num);
    for(i=1;i<=num;i++)//����׳˵�λ��
        sum+=log10(i);
    digit=(int)sum+1;//���ݳ���
    if(!(fact=(int *)malloc((digit+1)*sizeof(int)))) //���䱣��׳�λ�����ڴ� 
    {
        printf("�����ڴ�ʧ��!\n");
        return 0; 
    }
    for(i=0;i<=digit;i++) //��ʼ������
        fact[i]=0;
    fact[0]=1; //���λΪ1 
    for(i=2;i<=num;i++)//��2~num�����ԭ���Ļ���� 
    {
        for(j=digit;j>=0;j--) //�������λ 
            if(fact[j]!=0)
            {
                pos=j;//��¼���λ
                break;
            }
        for(j=0;j<=pos;j++)
            fact[j]*=i;//ÿһλ��i��
        carry(fact,pos);//��λ���� 
    }
    for(j=digit;j>=0;j--) //�������λ 
        if(fact[j]!=0)
        {
            pos=j;//��¼���λ 
            break;
        }
    m=0;//ͳ�����λ��
    n=0;//ͳ��������� 
    printf("\n���%d�Ľ׳˽��(���������ʾ��һ��):\n",num);
    for(i=pos;i>=0;i--) //��������� 
    {
        printf("%d",fact[i]);
        m++;
        if(m%5==0) //ÿ5���������һ���ո񣬷����Ķ� 
            printf(" ");
        if(40==m) //ÿ�����40������ 
        {
            printf("\n");
            m=0;
            n++;
            if(10==n) //���10������ͣ 
            {
                getch();
                printf("\n");
                n=0;
            }
        }
    }
    printf("\n\n");
    printf("%d�Ľ׳˹���%dλ��\n",num,pos+1);
    getch();
    return 0;
}
