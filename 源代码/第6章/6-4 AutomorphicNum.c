#include <stdio.h>
int main()
{
    long faciend,num,mod,n_mod,p_mod; //mod��������ϵ����n_mod������ϵ��,p_mod���ֳ˻���ϵ�� 
    long i,t,n;  //��ʱ���� 
    printf("���������:");
    scanf("%ld",&num);    
    printf("1~%ld֮��������������:\n",num);
    for(i=1;i<num;i++)
    {
        faciend=i; //������ 
        mod=1;
        do{
            mod*=10; //��������ϵ�� 
            faciend/=10;
        }while(faciend>0); //ѭ�������������ϵ�� 
        p_mod=mod; //p_modΪ��ȡ���ֻ�ʱ��ϵ�� 
        faciend=0; //�������Nλ 
        n_mod=10; //llΪ��ȡ������Ӧλʱ��ϵ�� 
        while(mod>0)
        {
            t=i % (mod*10); //��ȡ������ 
            n=i%n_mod-i%(n_mod/10);//�ֽ��ÿһλ������Ϊ���� 
            t=t*n; //��˵Ľ�� 
            faciend=(faciend+t)%p_mod; //��ȡ�˻��ĺ��漸λ
            mod/=10; //������������ϵ�� 
            n_mod*=10; //����������ϵ�� 
        }
        if(i==faciend) //��Ϊ������������� 
            printf("%ld ",i);
    }
    getch();
    return 0;
}
