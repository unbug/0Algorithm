#include <stdio.h>
int main()
{
    int len,i;//lenС������ 
    int numerator=1,denominator=3,result,carry;
    int flag=1,count=0; //���������ı�־�������Ĵ��� 
    char *pi,*temp; //ָ�򱣴�piֵ����ʱ������������ 
    printf("����С��λ��:");
    scanf("%d",&len);
    len+=2; //����2λ 
    if(!(pi=(char *)malloc(sizeof(char)*len))) //���䱣��piֵ���ڴ�
    {
        printf("�����ڴ�ʧ��!\n");
        exit(0); 
    }
    if(!(temp=(char *)malloc(sizeof(char)*len))) //���䱣����ʱֵ���ڴ�
    {
        printf("�����ڴ�ʧ��!\n");
        exit(0); 
    } 
    for(i=0;i<len;i++)//��ʼ������ 
        pi[i]=temp[i]=0;
    pi[1]=2; //�ó�ֵ 
    temp[1]=2;
    while(flag && (++count<2147483647)) //int�����ֵ��2147483647
    {
        carry=0;
        for(i=len-1;i>0;i--)//�ӵ�λ����λ��� 
        {
            result=temp[i]*numerator+carry; //��ÿһλȥ�� 
            temp[i]=result%10; //������� 
            carry=result/10; //��λ 
        }
        carry=0;
        for(i=0;i<len;i++) //�ɸߵ��ͽ��г������� 
        {
            result=temp[i]+carry*10; //��ǰλ����ǰһλ������ 
            temp[i]=result/denominator; //��ǰλ���������� 
            carry=result%denominator; //��ǰλ���������ۼӵ���һλ������ 
        }
        flag=0; //�����־ 
        for(i=len-1;i>0;i--) //�ɵ�λ����λ�����������ۼ� 
        {
            result=pi[i]+temp[i]; //���������ۼӵ�x�� 
            pi[i]=result%10; //����һλ�� 
            pi[i-1]+=result/10; //���λ��λ 
            flag|=temp[i];//��temp�е���ȫ��Ϊ0���˳�ѭ�� 
        }
        numerator++; //�ۼӷ��� 
        denominator+=2; //�ۼӷ�ĸ 
    }
    printf("\n������%d��\n",count); //����������� 
    printf("\t---��1-1000λС��---\n");
    printf("PI=%d.",pi[1]);//����������� 
    for(i=2;i<len;i++)
    {
        if((i>2) && (i-2)%10==0) //ÿ10λС�����һ���ո� 
            printf(" ");
        if((i>2) && (i-2)%50==0) //ÿ50λС������ 
            printf("\n");
        if(i>2 && (i-2) % 1000 ==0)//��1000λС����ʾһ����ʾ
        {             
            printf("\t---���������ʾ��%d-%dλС��---\n",(i-2)/1000*1000+1,((i-2)/1000+1)*1000);
            getch();
        }
        printf("%d",(int)pi[i]);
    } 
    getch();
    return 0;
}
