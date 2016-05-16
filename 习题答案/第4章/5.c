#include <stdio.h>
#define MAX 15

void ShellSort(int a[],int n)//ϣ������ 
{
    int d,i,j,x;
    d=n/2;
    while(d>=1) //ѭ��������Ϊ1ʱ���� 
    {
        for(i=d;i<n;i++)
        {
            x=a[i]; //��ȡ�����е���һ������ 
            j=i-d; //������ǰһ�����ݵ���� 
            while(j>=0 && a[j]>x) //��һ��������ǰһ���� 
            {
                a[j+d]=a[j]; //����һ������ǰ�ƶ� 
                j=j-d; //�޸���ţ�������ǰ�Ƚ� 
            }
            a[j+d]=x; //�������� 
        }
        d/=2;  //��С���� 
    }
}
int main()
{
    int a[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};
    int i;
    
    ShellSort(a,MAX);	//����ϣ��������
    printf("������:"); 
    for(i=0;i<MAX;i++)	//��������Ľ��
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}