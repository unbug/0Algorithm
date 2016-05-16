#include <stdio.h>
typedef struct goods
{
    double *value; //��ֵ
    double *weight; //���� 
    int num;//��Ʒ���� 
    int limitw; //��������
}GOODS;
void backpack(GOODS *g,char select[])
{
   int i,flag;
   char *select1;
   double maxvalue = 0,tw,tv;
   if(!(select1 = (char *)malloc(sizeof(char) * g->num)))//���������뱳������Ʒ��� 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   for (i = 0; i < g->num; i++)//��������� 
       select1[i] = 0;    
   while(binadd(select1, g->num) == 0) //����һ�ζ����Ƽӷ����� 
   {
       tw = 0;
       tv = 0;
       flag = 1;
       printf("\n");
       for (i = 0; i < g->num; i++) //����ѡ��״̬�������� 
       {
           if (select1[i] == 1) //��ѡ�и���Ʒ
           {
               tw += g->weight[i]; //�ۼ�ѡ����Ʒ������ 
               tv += g->value[i];//�ۼ�ѡ����Ʒ�ļ�ֵ 
               if (tw > g->limitw) //�������������� 
               {
                   flag = 0;
                   break; //�˳����η��������� 
               }
           } 
       }
       if(flag && maxvalue < tv) //������ѡ����Ʒ����δ��������,���ұ������ۼӼ�ֵ�������з���������ֵ
       {
           maxvalue = tv;
           for(i = 0; i < g->num; i++) //���淽�� 
               select[i] = select1[i];
       } 
   }   
}
int binadd(char select1[],int n) //���������� 
{
    int i,carry=0;
    select1[0] += 1;
    for (i = 0; i < n; i++)
    {
        select1[i] += carry; //���Ͻ�λ 
        carry = select1[i] /2;//�����λ         
        select1[i] %= 2; //����0��1; 
        if (carry==0)
            return 0;
    }
    return carry;
}
int main()
{
   double sumweight,maxvalue; //��������׶����ż�ֵ 
   char *select;
   GOODS g;
   int i; //item�����������������뱳����Ʒ����� 
   printf("�����������:");
   scanf("%d",&g.limitw);
   printf("��ѡ��Ʒ����:"); 
   scanf("%d",&g.num);
   if(!(g.value = (double *)malloc(sizeof(double)*g.num)))//�����ڴ汣����Ʒ��ֵ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0); 
   }
   if(!(g.weight = (double *)malloc(sizeof(double)*g.num)))//�����ڴ汣����Ʒ������ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   if(!(select = (char *)malloc(sizeof(char)*g.num)))
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   for (i = 0; i < g.num; i++)
   {
	  printf("�����%d����Ʒ�������ͼ�ֵ:",i + 1);
	  scanf("%lf%lf",&g.weight[i],&g.value[i]);
   }
   printf("\n���������װ������Ϊ:%.2f\n\n",g.limitw);
   for (i = 0; i < g.num; i++)
	  printf("��%d����Ʒ��:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);
   backpack(&g,select);
   sumweight=0;
   maxvalue=0; 
   printf("\n�ɽ�������Ʒװ�뱳��,ʹ����װ����Ʒ��ֵ���:\n");
   for (i = 0; i < g.num; ++i)
	  if (select[i])
	  {
		 printf("��%d����Ʒ,����:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);
		 sumweight+=g.weight[i];
		 maxvalue+=g.value[i];
      }	 
   printf("\n������Ϊ: %.2f,�ܼ�ֵΪ:%.2f\n", sumweight, maxvalue );
   getch();
   return 0;
}
