#include <stdio.h>
char *expr1;	//ָ��Ҫ������ַ��� 
int a = 1;	//������aΪһ���������������Ϊ��Сֵ����С���ʽ����Ŀ����ԣ� 
void trim(char *str)	//ȥ���ո� 
{
   int i = 0, j = 0;
   char *str1;
   str1 = strdup(str);
   while (str1[i] != '\0')
   {
	  if (str1[i] != ' ')
		 str[j++] = str1[i];
	  i++;
   }
   str[j] = '\0'; //�ַ��������ַ� 
}
int calc(int left, int right)	//���ʽ��ֵ 
{
   int pare, oper, num, base, exp, i;
   if (left > right)
	  return 0;
   pare = 0;	//���Ų���
   oper = 0;	//�������λ��
   for (i = right; i >= left; i--)	//������������ʽ�е������������ 
   {
	  if (expr1[i] == ')')	//��Ϊ������ 
		 pare++;	//������������ 
	  else if (expr1[i] == '(')	//��Ϊ������ 
		 pare--;	//������������ 
	  if (pare == 0)	//�������� 
	  {
		 if (expr1[i] == '+' || expr1[i] == '-')	//���Ǽӻ���� 
		 {
			oper = i;	//�������λ�� 
			break;
		 } else if ((expr1[i] == '*') && ((oper == 0) || (expr1[oper] == '*'
				  || expr1[oper] == '^')))
			oper = i;
		 else if ((expr1[i] == '^') && (oper == 0))
			oper = i;
	  }
   }
   if (oper == 0)	//�߽�����Ĵ��� 
   {
	  if ((expr1[left] == '(') && (expr1[right] == ')'))	//���������ڵı��ʽ 
		 return (calc(left + 1, right - 1));	//�ݹ���������ڱ��ʽ��ֵ 
	  if (expr1[right] == ')')	//����������� 
		 return (calc(left, right - 1));	//����ȥ�������ź�ı��ʽ 
	  if (expr1[left] == '(')	//����������� 
		 return (calc(left + 1, right));	//����ȥ�������ź�ı��ʽ 
	  if (expr1[left] == 'a')	//Ϊ����a 
		 return (a);	//����x��ֵ 
	  num = 0;
	  for (i = left; i <= right; i++)	//Ϊ���� 
		 num = num * 10 + expr1[i] - '0';	//�ۼ�ֵ       
   }
   else	//�ݹ������������� 
   {
	  switch (expr1[oper])
	  {
	  case '+':
		 return (calc(left, oper - 1) + calc(oper + 1, right));	//���ұ��ʽ�Ľ����� 
	  case '-':
		 return (calc(left, oper - 1) - calc(oper + 1, right));
	  case '*':
		 return (calc(left, oper - 1) * calc(oper + 1, right));
	  case '^':
		 num = 1;
		 base = calc(left, oper - 1);	//������߱��ʽ��ֵ 
		 exp = calc(oper + 1, right);	//����ָ����ֵ 
		 for (i = 1; i <= exp; i++)	//�ظ��ˣ��õ��ݽ�� 
			num = num * base;
	  }
   }
   return num;	//���ؼ����� 
}
int main()
{
   FILE *fp1, *fp2;
   char flag[26] = { 0 };	//��־���飬��Ϊ1����ʾ����ɱ��ʽ��ͬ 
   int result, i, n;
   char expr[51], str[26][51];
   if ((fp1 = fopen("equal.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fgets(expr, 50, fp1);
   trim(expr);	//ȥ�����ʽ�еĿ��ַ�
   fscanf(fp1, "%d\n", &n);
   for (i = 0; i < n; i++)
   {
	  fgets(str[i], 50, fp1);
	  trim(str[i]);
   }
   fclose(fp1);
   expr1 = expr;	//ȫ��ָ��ָ����ʽ�ַ��� 
   result = calc(0, strlen(expr1) - 2);	//������ʽ��ֵ 
   for (i = 0; i < n; i++)	//����n�����ʽ��ֵ 
   {
	  if (flag[i] == 0)
	  {
		 expr1 = str[i];
		 if (calc(0, strlen(expr1) - 2) == result)	//�����ʽֵ����ɱ��ʽ��ֵ��� 
			flag[i] = 1;
	  }
   }
   if ((fp2 = fopen("equal.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   for (i = 0; i < n; i++)
   {
	  if (flag[i])
	  {
		 printf("%c", i + 'A');	//�����ĸ˳����Ļ 
		 fprintf(fp2, "%c", i + 'A');	//�����ĸ˳���ļ� 
	  }
   }
   fclose(fp2);
   getch();
   return 0;
}
