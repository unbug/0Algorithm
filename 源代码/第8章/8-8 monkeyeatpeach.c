#include <stdio.h>
int peach(int n) //�ݹ麯�� 
{
    if(n==1)
        return 1;  //��10���ֻʣ1����
    else
       return (peach(n-1)+1)*2;  //ǰһ���ܱȺ�1���һ���1
}
int main()
{
    int days; //���� 
    long sum; //��������� 
    printf("��������:");
    scanf("%d",&days); 
    sum=peach(days);
    printf("�����������:%ld\n",sum);
    getch();
    return 0;
}
