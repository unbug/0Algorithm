#include <stdio.h> 
#include <math.h> 
int main () 
{
    int i,n,s;
    double k,y2;
    printf("�����и����:");
    scanf("%d",&n); 
    i=0;//�и���� 
    k=3.0; //��ʼֵ 
    y2=1.0; //�ڽ������εı߳� 
    s=6;//��ʼ�ڽӶ���εı��� 
    while(i<=n)
    {
        printf("��%d���и�,Ϊ%d��,PI=%.24f\n",i,s,k*sqrt(y2));
        s*=2; //��������1�� 
        y2=2-sqrt(4-y2); //�ҳ� 
        i++;
        k*=2.0;        
    } 
    getch();
    return 0;
}
