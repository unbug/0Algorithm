/*��10000���ڵ�����*/
#include <stdio.h>
int main()
{
    long p[300]; //����ֽ������ 
    long i,num,count,s,c=0;
    for(num=2;num<=2000000;num++)
    {
        count=0;
        s=num;
        for(i=1;i<num/2+1;i++) //ѭ������ÿ1���� 
        {
            if(num % i==0) //�ܱ�i����*/
            {
                p[count++]=i; //�������ӣ�������count����1                
                s-=i; //��ȥһ������*/ 
             }
        }
        if(s==0) //�ѱ��ֽ���ɣ������*/ 
        {
            printf("%4ld��һ������,������",num);
            printf("%ld=%ld",num,p[0]); //������� */
            for(i=1;i<count;i++) //������� */
                printf("+%ld",p[i]);
            printf("\n");
            c++;
        }
    }
    printf("\n���ҵ�%d��������\n",c);
    getch();
    return 0; 
}
