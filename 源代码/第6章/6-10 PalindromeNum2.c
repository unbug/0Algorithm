#include <stdio.h>
int main(void)
{
    int n,high,low,count=0;
    int b[10]; //����ƽ�����ĸ�λ 
    long s;
    printf("���\t��ֵ\t������\n");
    for(n=10;n<1000;n++) //ѭ�����з�Χ
    {
        s=n*n; //����n��ƽ��
        high=0;
        while(s>0)
        {
            b[high++]=s%10;
            s/=10;   
        }
        low=-1; //��λָʾ�� 
        while(++low<--high) //high�Ǹ�λָʾ��
        {
            if(b[low]!=b[high]) //����λ�͵�λ����ȣ��򲻶Գ� 
                break; //�˳�ѭ�� 
        }        
        if(low>=high)//���и�λ�͵�λ���ȽϺ��˳�ѭ�� 
            printf("%2d\t%d\t%d\n",++count,n,n*n); //���n�ͻ����� 
    }
    getch();
    return 0;
}
