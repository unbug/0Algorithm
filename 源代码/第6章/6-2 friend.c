#include <stdio.h>
int main() 
{
    int i,a,b1,b2,m,g1[100],g2[100],count;
    printf("�������Χ:");
    scanf("%d",&m); 
    for(a=1;a<m;a++)      //ѭ������
    {
        for(i=0;i<100;i++) //������� 
            g1[i]=g2[i]=0;
        count=0;//�����±� 
        b1=0;//�ۼӺ� 
        for(i=1;i<a/2+1;i++)//����a������ 
        {
            if(a%i==0)//a�ܱ�i���� 
            {
                g1[count++]=i; //�������ӵ����飬������� 
                b1+=i;//�ۼ�����֮�� 
            }
        }
        count=0;
        b2=0;
        for(i=1;i<b1/2+1;i++) //����a����֮���ٽ������ӷֽ� 
        {
            if(b1%i==0) //b1�ܱ�i���� 
            {
                g2[count++]=i; //�������ӵ����� 
                b2=b2+i;      //�ۼ�����֮�� 
            }
        }
        if(b2==a && a<b1) //�ж�A��B���������  
        {
            printf("\n\n%d--%d����������������Ϊ��",a,b1); //��������� 
            printf("\n%d=1",a);
            count=1;
            while(g1[count]>0)//���һ���������� 
            {
                printf("+%d",g1[count]);
                count++;
            }
            printf("\n%d=1",b1);
            count=1;
            while(g2[count]>0)//�����һ���������� 
            {
                printf("+%d",g2[count]);
                count++;
            }
        }
    } 
    getch();
    return 0;
}

