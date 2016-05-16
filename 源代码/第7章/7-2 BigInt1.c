#include <stdio.h>
#include <string.h>
typedef struct bigint
{
   char *num;					//ָ����������(���0�б��������λ)
   char minus;					//����(1��ʾ����,-1��ʾ����) 
   int digit;					//���������λ��(ʵ��λ��) 
}BIGINT, *pBIGINT;
void BigIntTrans(pBIGINT num);	//�ַ���ת���� 
void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT result);	//�˷����� 
void BigIntAdd1(pBIGINT num1, pBIGINT num2, pBIGINT result);	//ͬ������� 
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT result);	//�ӷ����� 
void BigIntSub1(pBIGINT num1, pBIGINT num2, pBIGINT result);	//����������
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT result);	//�������� 
void BigIntDiv(pBIGINT num1, pBIGINT num2, pBIGINT result, pBIGINT residue);	//�������� 
void BigIntPrint(pBIGINT result);	//���������
int BigIntEqual(pBIGINT num1, pBIGINT num2);	//������С�Ƚ�

void BigIntTrim(pBIGINT num1) //�����������ȥ��ǰ������0����ʹ������λ��
{
   int i;
   for (i = num1->digit - 1; i >= 0; i--)
   {
	  if (num1->num[i] != 0)
		 break;
   }
   if (i < 0)	//������ȫ��Ϊ0
   {
	  num1->digit = 1;	//��������λ��Ϊ1
	  num1->num[0] = 0;
   } else
	  num1->digit = i + 1;	//����λ��     
}
void BigIntTrans(pBIGINT num1) //���ַ���תΪ���ֱ�ʾ
{
   char *temp;					//��ʱ���� 
   int i, k, len;
   len = strlen(num1->num);	//�ַ������� 
   if (!(temp = (char *) malloc(sizeof(char) * len)))	//�����ڴ� 
   {
	  printf("�ڴ����ʧ��!\n");
	  exit(0);
   }
   i = 0;
   num1->minus = 1;	//����Ϊ���� 
   if (num1->num[0] == '-')	//�ж��Ƿ�Ϊ���� 
   {
	  num1->minus = -1;	//����Ϊ���� 
	  i++;
   }
   k = 0;	//����λ�������� 
   while (num1->num[i] != '\0')	//�ַ���δ���� 
   {
	  if (num1->num[i] >= '0' && num1->num[i] <= '9')	//Ϊ����0~9 
	  {
		 temp[k] = num1->num[i] - '0';	//��ASCII��ת��Ϊ��Ӧ���� 
		 k++;
	  }
	  i++;
   }

   for (i = 0; i < num1->digit; i++)	//��������Ԫ�� 
	  num1->num[i] = 0;
   num1->digit = k;	//ת���������λ�� 
   for (i = 0, k--; k >= 0; k--, i++)	//����ʱ�����λ���ñ��浽����num�� 
	  num1->num[i] = temp[k];
   BigIntTrim(num1); //��������Ĵ����� 
}
void BigIntPrint(pBIGINT result) //��������� 
{
   int j;
   if (result->minus == -1)	//�Ǹ��� 
	  printf("-");	//������� 
   if (result->digit == 1 && result->num[0] == 0)	//��������Ϊ0
	  printf("0");
   else //��Ϊ0 
   {
	  for (j = result->digit - 1; j >= 0; j--) //�Ӹ�λ����λ��� 
		 printf("%d", result->num[j]);
   }
}
int BigIntEqual(pBIGINT num1, pBIGINT num2) //�ȽϾ���ֵ��С
{
   int i;
   if (num1->digit > num2->digit)	//num1��λ������num2 
	  return 1;
   else if (num1->digit < num2->digit)	//num1��λ��С��num2
	  return -1;
   else	//����λ����� 
   {
	  i = num1->digit - 1;	//num1������λ�� 
	  while (i >= 0)	//�Ӹ�λ���λ��
	  {
		 if (num1->num[i] > num2->num[i])	//num1��Ӧλ����num2
			return 1;
		 else if (num1->num[i] < num2->num[i])	//num1��ӦλС��num2
			return -1;
		 else
			i--; //�Ƚ���һλ 
	  }
   }
   return 0;	//��� 
}
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
   int i;
   i = BigIntEqual(num1, num2);	//�Ƚ���������ֵ��С
   if (i < 0)	//num1����ֵС��num2 
   {
     pBIGINT temp;
     temp = num1;	//�������� 
     num1 = num2;
     num2 = temp;
   }
   if (num1->minus * num2->minus < 0)	//���Ų�ͬ����ִ���� 
   {	  
	  if (i == 0)	//�������
	  {
		 result->digit = 1;	//�������Ϊһλ����������ֵ0
		 result->num[0] = 0;	//���ֵΪ0
		 result->minus = 1;	//�����Ϊ���� 
		 return;	//���� 
	  } 
	  BigIntSub1(num1, num2, result);	//�������������������ӵ����
   } else
	  BigIntAdd1(num1, num2, result);	//������Ӻ������ͬ�����
}
void BigIntAdd1(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
   int i, carry;
   carry = 0;
   result->minus = num1->minus;	//������� 
   for (i = 0; i < num1->digit; i++)	//�����������Ƶ���������� 
	  result->num[i] = num1->num[i];
   for (i = 0; i < num2->digit; i++)	//num2�е���С������λ��ҲСЩ
   {
	  result->num[i] = result->num[i] + num2->num[i] + carry;	//����Ӧλ�����ͽ�λ����� 
	  carry = result->num[i] / 10;	//�����λ����
	  result->num[i] = result->num[i] % 10;	//����һλ     
   }
   if (carry)	//������н�λ 
	  result->num[i] = result->num[i] + carry;
   BigIntTrim(result);	//������ 
}
void BigIntSub1(pBIGINT num1, pBIGINT num2, pBIGINT result) //����������
{
   int i, borrow;
   result->minus = num1->minus;	//��num1����ֵ��num2�󣬽��������num1��ͬ 
   borrow = 0;
   for (i = 0; i < num1->digit; i++)	//�������������ݸ��Ƶ������ 
	  result->num[i] = num1->num[i];
   for (i = 0; i <= num2->digit; i++)
   {
	  result->num[i] = result->num[i] - num2->num[i] - borrow;	//num1��ȥnum2������ȥ��λ�Ľ�λ 
	  if (result->num[i] < 0)	//��Ϊ���� 
	  {
		 result->num[i] = 10 + result->num[i];	//���λ��λ 
		 borrow = 1;	//���ý�λֵ 
	  } else
		 borrow = 0;
   }
   if (borrow == 1)
	  result->num[i] = result->num[i] - borrow;
   BigIntTrim(result);
   /*i = num1->digit;
   while (i > 0)
   {
	  if (result->num[i] == 0)
		 i--;
	  else
		 break;
   }
   result->digit = i;	//������λ��*/
}
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT result) //�������� 
{
   num2->minus = -1 * num2->minus;	//�������ķ���ȡ�� 
   BigIntAdd(num1, num2, result);	//���üӷ����� 
}
void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
   char carry, temp;
   int i, j, pos;
   for (i = 0; i < num1->digit + num2->digit; i++)	//���������м�������0 
	  result->num[i] = 0;
   for (i = 0; i < num2->digit; i++)	//�ó�����ÿ1λ���Ա����� 
   {
	  carry = 0;	//�����λ
	  for (j = 0; j < num1->digit; j++)	//��������ÿ1λ 
	  {
		 temp = num2->num[i] * num1->num[j] + carry;	//��˲����Ͻ�λ
		 carry = temp / 10;	//�����λcarry
		 temp = temp % 10;	//���㵱ǰλ��ֵ
		 pos = i + j;
		 result->num[pos] += temp;	//�������ۼӵ���ʱ������ 
		 carry = carry + result->num[pos] / 10;	//�����λ 
		 result->num[pos] = result->num[pos] % 10;
	  }
	  if (carry > 0)
	  {
		 result->num[i + j] = carry;	//�������λ��λ
		 result->digit = i + j + 1;	//������λ�� 
	  } else
		 result->digit = i + j;	//������λ�� 
   }
   result->minus = num1->minus * num2->minus;	//����ķ��� 
}
void BigIntDiv(pBIGINT num1, pBIGINT num2, pBIGINT result, pBIGINT residue) //������������ ��� �ȥ��λ�Ľ�λ �num1��ͬ ��
{
   BIGINT quo1, residuo1, quo2;
   int i, j, k, m;				//k�������̽��,m�����̵�λ�� 
   char t;
   result->minus = num1->minus * num2->minus;	//�̵ķ���
   residue->num = (char *) malloc(sizeof(char) * num2->digit);	//�����������ڴ�ռ�
   residue->digit = num2->digit+1;	//���������ĳ�ʼλ���������ͬ 
   for (i = 0; i < residue->digit; i++)	//������ȫ����0 
	  residue->num[i] = 0;
   m = 0;
   for (i = num1->digit - 1; i >= 0; i--)
   {
	  residue->digit=num2->digit+1; //��������������λ���ȳ�����һλ 
	  for (j = residue->digit - 1; j > 0; j--)	//������ 
		 residue->num[j] = residue->num[j - 1];	//����ŵ�λ�����������λ(ʵ���ǽ������е����λȥ��) 
	  residue->num[0] = num1->num[i];	//���Ʊ������е�һλ�����������λ�� 
	  BigIntTrim(residue);//�������� 
      k = 0;	//����
	  while (BigIntEqual(residue, num2) >= 0)	//�Ƚ�����������Ĵ�С
	  {
		 BigIntSub1(residue, num2, residue);	//��������ȥ��������ֵ������������
		 k++;	//���̼�1 
	  }
	  result->num[m++] = k;	//������    
   }
   result->digit = m;	//�����̵�λ�� 
   for (i = 0; i < m / 2; i++)	//���̸�λ��ת(�ڼ�����������0��������̵ĸ�λ) 
   {
	  t = result->num[i];
	  result->num[i] = result->num[m - 1 - i];
	  result->num[m - 1 - i] = t;
   }
   BigIntTrim(result);	//������ 
   BigIntTrim(residue);	//�������� 
}
int main()
{
   BIGINT num1, num2, result, residue;	//���������������������� 
   int i = 0, len;
   char op;
   printf("�����������λ��:");
   scanf("%d", &len);
   if (!(num1.num = (char *) malloc(sizeof(char) * (len + 1))))
   {
	  printf("�ڴ����ʧ��!\n");
	  exit(0);
   }
   num1.digit = len + 1;
   if (!(num2.num = (char *) malloc(sizeof(char) * (len + 1))))
   {
	  printf("�ڴ����ʧ��!\n");
	  exit(0);
   }
   num2.digit = len + 1;
   if (!(result.num = (char *) malloc(sizeof(char) * (2 * len + 1))))
   {
	  printf("�ڴ����ʧ��!\n");
	  exit(0);
   }
   result.digit = 2 * len + 1;
   for (i = 0; i < result.digit; i++)	//��ս���� 
	  result.num[i] = 0;
   printf("ѡ�������������(+��-��*��/):");
   fflush(stdin);
   scanf("%c", &op);
   switch (op)
   {
   case '+':
	  printf("\n���뱻����:");
	  scanf("%s", num1.num);
	  printf("\n�������:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  BigIntAdd(&num1, &num2, &result);	//�ӷ� 
	  break;
   case '-':
	  printf("\n���뱻����:");
	  scanf("%s", num1.num);
	  printf("\n�������:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  BigIntSub(&num1, &num2, &result);	//���� 
	  break;
   case '*':
	  printf("\n���뱻����:");
	  scanf("%s", num1.num);
	  printf("\n�������:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  BigIntMul(&num1, &num2, &result);	//�˷� 
	  break;
   case '/':
	  printf("\n���뱻����:");
	  scanf("%s", num1.num);
	  printf("\n�������:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  if (num2.digit == 1 && num2.num[0] == 0)	//������Ϊ0
		 printf("��������Ϊ0!\n");
	  else
		 BigIntDiv(&num1, &num2, &result, &residue);	//������ 
	  break;
   }
   if (op == '/')
   {
	  if (!(num2.digit == 1 && num2.num[0] == 0))	//Ϊ�����ҳ�����Ϊ0
	  {
		 printf("��:");
		 BigIntPrint(&result);
		 printf("\t����:");
		 BigIntPrint(&residue);
	  }
   } else
   {
	  printf("\n���:");
	  BigIntPrint(&result);
   }

   getch();
   return 0;
}
