#include<stdio.h>
int Trial(float, float, float, float);	//��4������������ 
float Calc(int, float, float);	//���� 
void Output(int, int, int, int, float, float, float, float);	//������ 
int iCount = 0;	//������ 
int main()
{
   int i, j, k, t, result, flag;
   float num[4]; //���������4���� 
   char again = 'y';
   while (again == 'y' || again == 'Y')
   {
	  iCount = 0;
	  printf("\n����4����(1~13):");
	  i = 0;
	  flag = 0;
	  while (flag == 0)
	  {
		 i++;
		 for (i = 0; i < 4; i++)	//����4���� 
		 {
			scanf("%f", &num[i]);
			if (num[i] < 1 || num[i] > 13 || num[i] != (int) (num[i]))	//�ж����������Ƿ���Ч 
			   flag++;
		 }
		 if (flag != 0)	//������������� 
		 {
			printf("�����������,�������롣\n", i);
			flag = 0;
		 }
         else
			flag = 1;
	  }
	  for (i = 0; i < 4; i++)	//ѭ����4����������ʽ���м��� 
	  {
		 for (j = 0; j < 4; j++)
		 {
			if (j == i)	//������Ԫ������ 
			   continue;	//������һ�� 
			for (k = 0; k < 4; k++)
			{
			   if (k == i || k == j)	//������Ԫ������
				  continue;	//������һ�� 

			   for (t = 0; t < 4; t++)
			   {
				  if (t == i || t == j || t == k)	//������Ԫ������
					 continue;	//������һ�� 
				  else
					 result = Trial(num[i], num[j], num[k], num[t]);
			   }
			}
		 }
	  }
	  if (result == 0)
		 printf("\n��4�����޽�!\n");
	  printf("\n����(y/n)?");
	  again = getch();
   }
   return 0;
}
int Trial(float data1, float data2, float data3, float data4)	//��4������������ 
{
   int o1, o2, o3;
   float temp1, temp2, temp3;
   for (o1 = 0; o1 < 4; o1++)	//4������� 
   {
	  for (o2 = 0; o2 < 6; o2++)	//6������� 
	  {
		 for (o3 = 0; o3 < 6; o3++)	//6������� 
		 {
			//�����1�ֱ��ʽ 
			if ((!(o1 == 3 && data2 == 0)) && (!(o2 == 3 && data3 == 0))
			   && (!(o3 == 3 && data4 == 0)))	//�������Ϊ�������ҳ���Ϊ0����ִ���������� 
			{
			   temp1 = Calc(o1, data1, data2);	//����a��b������������ 
			   temp2 = Calc(o2, temp1, data3);	//����temp1,c�����ļ����� 
			   temp3 = Calc(o3, temp2, data4);	//����temp2,d�����ļ����� 
			   if (fabs(temp3 - 24) < 0.1)	//�ж���temp3��24��� 
			   {
				  iCount++;	//�ۼӴ��� 
				  Output(1, o1, o2, o3, data1, data2, data3, data4);	//�����1����ʽ�Ľ� 
			   }
			}
			if (o3 == 2)	//���˷���Ϊ�м������� 
			{
			   temp1 = Calc(o1, data1, data2);	//����a��b�������� 
			   temp2 = Calc(o2, data3, data4);	//����c��d�������� 
			   temp3 = temp1 * temp2;	//������˵Ľ�� 
			   if (fabs(temp3 - 24) < 0.1)	//���������24
			   {
				  iCount++;
				  Output(2, o1, o2, o3, data1, data2, data3, data4);	//�����2����ʽ�Ľ� 
			   }
			}
			if (o3 == 3)	//��������Ϊ�м������� 
			{
			   temp1 = Calc(o1, data1, data2);	//����a��b�Ľ�� 
			   temp2 = Calc(o2, data3, data4);	//����c��d�Ľ�� 
			   if (temp2)
			   {
				  temp2 = temp1 / temp2;	//��������Ľ�� 
				  if (fabs(temp3 - 24) < 0.1)	//���������24 
				  {
					 iCount++;
					 Output(2, o1, o2, o3, data1, data1, data3, data4);	//�����2����ʽ�Ľ� 
				  }
			   }
			}
		 }
	  }
   }
   return iCount;
}
float Calc(int oper, float data1, float data2)	//��������������� 
{
   if (oper == 0)	//�ӷ� 
	  return (data1 + data2);
   if (oper == 1)	//���� 
	  return (data1 - data2);
   if (oper == 2)	//�˷� 
	  return (data1 * data2);
   if (oper == 3)	//���� 
	  if (data2 == 0)	//����Ϊ0 
		 return 32767;	//����һ������ֵ 
	  else
		 return (data1 / data2);	//������ 
   if (oper == 4)	//���Ƿ�������� 
	  return (data2 - data1);
   if (oper == 5)	//���Ƿ�������� 
	  if (data1 == 0)	//������Ϊ0 
		 return 32767;	//����һ������ֵ 
	  else
		 return (data2 / data1);
   return 0;
}
void Output(int type, int o1, int o2, int o3, float data1, float data2,
   float data3, float data4)	//����� 
{
   char operator[6];	//����6������� 
   operator[0] = '+';
   operator[1] = '-';
   operator[2] = '*';
   operator[3] = '/';
   operator[4] = '-';
   operator[5] = '/';
   printf("��%d:", iCount);
   if (type == 1)
   {
	  if (o2 == 4 || o2 == 5)	//��2�������Ϊ�����򷴳������ 
	  {
		 if (o3 == 4 || o3 == 5)	//��3�������Ϊ�����򷴳������ 
			printf("%2.0f %c (%2.0f %c (%2.0f %c %2.0f)) =24\n", data4,
			   operator[o3], data3, operator[o2], data1, operator[o1], data2);
		 else
			printf("(%2.0f %c (%2.0f %c %2.0f)) %c %2.0f =24\n", data3,
			   operator[o2], data1, operator[o1], data2, operator[o3], data4);
	  } else if (o3 == 4 || o3 == 5)	//��3�������Ϊ�����򷴳������ 
	  {
		 printf("%2.0f %c ((%2.0f %c %2.0f) %c %2.0f) =24\n", data4,
			operator[o3], data1, operator[o1], data2, operator[o2], data3);
	  } else
		 printf("((%2.0f %c %2.0f) %c %2.0f) %c %2.0f =24\n", data1,
			operator[o1], data2, operator[o2], data3, operator[o3], data4);
   }
   if (type == 2)
   {
	  printf("(%2.0f %c %2.0f) %c (%2.0f %c %2.0f) =24\n", data1,
		 operator[o1], data2, operator[o3], data3, operator[o2], data4);
   }
}
