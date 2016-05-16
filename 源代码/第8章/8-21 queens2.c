#include<stdio.h>
int Queens[8];
int iCount = 0;	//ͳ���ҵ�������� 
void Output() //���һ���⣬��һ��û�г�ͻ�ķ��÷���
{
   int i, j, flag = 1;
   printf("��%2d�ַ���(���ʾ�ʺ�):\n", ++iCount);	//�����š� 
   printf("  ");
   for (i = 1; i <= 8; i++)
	  printf("�x");
   printf("\n");
   for (i = 0; i < 8; i++)
   {
	  printf("��");
	  for (j = 0; j < 8; j++)
	  {
		 if (Queens[i] - 1 == j)
			printf("��");
		 else
		 {
			if (flag < 0)
			   printf("  ");
			else
			   printf("��");
		 }
		 flag = -1 * flag;
	  }
	  printf("��\n");
	  flag = -1 * flag;
   }
   printf("  ");
   for (i = 1; i <= 8; i++)
	  printf("��");
   printf("\n");
   getch();
}
void Queen()
{
   int i, j, flag, iscontinue = 1;
   i = 0;	//���ڴ����Ԫ���±꣬��ʾǰi-1��Ԫ���ѷ���Ҫ�����ڴ����i��Ԫ�� 
   Queens[0] = 1;	//Ϊ����ĵ�һ��Ԫ�ظ���ֵ 
   while (iscontinue)	//�������� 
   {
	  while (iscontinue && i <= 7)	//��δ������8���ʺ� 
	  {
		 flag = 1;
		 for (j = 0; flag && j < i; j++)	//����ɨ��
			if (Queens[j] == Queens[i])	//�������ʺ���ͬһ�� 
			   flag = 0;
		 for (j = 0; flag && j < i; j++)	//�ж��Ƿ��������ʺ�ͬһ�Խ��� 
			if (abs(Queens[i] - Queens[j]) == (i - j))
			   flag = 0;
		 if (!flag)	//���ʺ�λ���г�ͻ 
		 {
			if (Queens[i] == Queens[i - 1])	//Queens[i]��ֵ�Ѿ�����һȦ׷��Queens[i-1]��ֵ 
			{
			   i--;	//�˻�һ����������̽����ǰһ��Ԫ��
			   if (i > 0 && Queens[i] == 8)	//��Queens[i]Ϊ8ʱ,��ʾ���һ�� 
				  Queens[i] = 1;	//��Queens[i]��ֵ��1,�ӵ�1�п�ʼ 
			   else if (i == 0 && Queens[i] == 8)	//����һλ��ֵ�ﵽ8ʱ
				  iscontinue = 0;	//���ý���ѭ�� 
			   else
				  Queens[i]++;	//��Queens[i]��ֵȡ��һ��ֵ
			} else if (Queens[i] == 8)	//���ѵ���8�� 
			   Queens[i] = 1;	//�ӵ�1�п�ʼ 
			else
			   Queens[i]++;	//��Queens[i]��ֵȡ��һ��ֵ 
		 } else if (++i < 8)
			if (Queens[i - 1] == 8)
			   Queens[i] = 1;	//��ǰһ��Ԫ�ص�ֵΪ8��Queens[i]=1
			else
			   Queens[i] = Queens[i - 1] + 1;	//����Ԫ�ص�ֵΪǰһ��Ԫ�ص���һ��ֵ
	  }
	  if (iscontinue)	//�������з��� 
	  {
		 Output();	//���һ�ַ��� 
		 if (Queens[6] < 8)	//��������2�е�ֵδ����8 
			Queens[6]++;	//�޸ĵ����ڶ�λ��ֵ 
		 else
			Queens[6] = 1;	//�ӵ�1�п�ʼ 
		 i = 6;	//��ʼѰ����һ�����������Ľ� 
	  }
   }
}
int main()
{
   printf("�˻ʺ����з���:\n");
   Queen();	//���ú����������з��� 
   getch();
   return 0;
}
