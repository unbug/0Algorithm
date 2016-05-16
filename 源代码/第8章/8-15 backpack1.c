#include <stdio.h>
typedef struct goods
{
    double *value; //��ֵ
    double *weight; //����
    char *select; //�Ƿ�ѡ�е����� 
    int num;//��Ʒ���� 
    double limitw; //��������
}GOODS;
double maxvalue,totalvalue;//��������ֵ,��Ʒ�ܼ�ֵ 
char *select1; //��ʱ���� 
void backpack(GOODS *g, int i, double tw, double tv)//����Ϊ��Ʒi,��ǰѡ���Ѿ��ﵽ��������tw,���������ܴﵽ���ܼ�ֵ 
{
   int k;
   if (tw + g->weight[i] <= g->limitw)//����Ʒi�����ڵ�ǰ����,������С�ڵ����������� 
   {
	  select1[i] = 1; //ѡ�е�i����Ʒ 
	  if (i < g->num - 1) //����Ʒi�������һ����Ʒ 
		 backpack(g, i + 1, tw + g->weight[i], tv); //�ݹ����,���������һ��Ʒ 
	  else //���ѵ����һ����Ʒ 
	  {
		 for (k = 0; k < g->num; ++k) //��״̬��־���Ƶ�option������ 
			g->select[k] = select1[k];
		 maxvalue = tv; //���浱ǰ����������ֵ 
	  }
   }
   select1[i] = 0; //ȡ����Ʒi��ѡ��״̬ 
   if (tv - g->value[i] > maxvalue)//����Ʒ�ܼ�ֵ��ȥ��Ʒi�ļ�ֵ������maxv���������еļ�ֵ,˵�������Լ����򷽰��������Ʒ 
   {
	  if (i < g->num - 1) //����Ʒi�������һ����Ʒ 
		 backpack(g, i + 1, tw, tv - g->value[i]); //�ݹ����,����������һ��Ʒ 
	  else //���ѵ����һ����Ʒ 
	  {
		 for (k = 0; k < g->num; ++k) //��״̬��־���Ƶ�option������ 
			g->select[k] = select1[k];
		 maxvalue = tv - g->value[i]; //���浱ǰ����������ֵ(����Ʒ�ܼ�ֵ�м�ȥ��Ʒi�ļ�ֵ)
	  }
   }
}
int main()
{
   double sumweight;
   GOODS g;
   int i;
   printf("�����������:");
   scanf("%lf",&g.limitw);
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
   if(!(g.select = (char *)malloc(sizeof(char)*g.num)))//�����ڴ汣����Ʒ������ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   if(!(select1 = (char *)malloc(sizeof(char)*g.num)))//�����ڴ汣����Ʒ������ 
   {
       printf("�ڴ����ʧ��\n");
       exit(0);   
   }
   totalvalue=0;   
   for (i = 0; i < g.num; i++)
   {
	  printf("�����%d����Ʒ�������ͼ�ֵ:",i + 1);
	  scanf("%lf%lf",&g.weight[i],&g.value[i]);
	  totalvalue+=g.value[i];//ͳ��������Ʒ�ļ�ֵ�ܺ� 
   }
   printf("\n���������װ������Ϊ:%.2f\n\n",g.limitw);
   for (i = 0; i < g.num; i++)
	  printf("��%d����Ʒ��:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);
   for (i = 0; i < g.num; i++)//��ʼ�����Ʒ��û����ѡ�� 
       select1[i]=0;
   maxvalue=0;//���뷽����Ʒ���ܼ�ֵ 
   backpack(&g,0,0.0,totalvalue); //��0����Ʒ���뷽��,������Ϊ0,������Ʒ��ֵΪtotalvalue 
   sumweight=0; 
   printf("\n�ɽ�������Ʒװ�뱳��,ʹ����װ����Ʒ��ֵ���:\n");
   for (i = 0; i < g.num; ++i)
	  if (g.select[i])
	  {
		 printf("��%d����Ʒ,����:%.2f,��ֵ:%.2f\n", i + 1, g.weight[i], g.value[i]);
		 sumweight+=g.weight[i];
      }	 
   printf("\n������Ϊ: %.2f,�ܼ�ֵΪ:%.2f\n", sumweight, maxvalue );
   getch();
   return 0;
}
