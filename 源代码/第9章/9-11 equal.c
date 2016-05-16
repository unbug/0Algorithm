#include <stdio.h>
char *expr1;	//指向要处理的字符串 
int a = 1;	//可设置a为一个整数（最好设置为较小值，减小表达式溢出的可能性） 
void trim(char *str)	//去掉空格 
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
   str[j] = '\0'; //字符串结束字符 
}
int calc(int left, int right)	//表达式求值 
{
   int pare, oper, num, base, exp, i;
   if (left > right)
	  return 0;
   pare = 0;	//括号层数
   oper = 0;	//运算符的位置
   for (i = right; i >= left; i--)	//从右向左检查表达式中的运算符和括号 
   {
	  if (expr1[i] == ')')	//若为右括号 
		 pare++;	//增加括号数量 
	  else if (expr1[i] == '(')	//若为左括号 
		 pare--;	//减少括号数量 
	  if (pare == 0)	//若无括号 
	  {
		 if (expr1[i] == '+' || expr1[i] == '-')	//若是加或减号 
		 {
			oper = i;	//保存符号位置 
			break;
		 } else if ((expr1[i] == '*') && ((oper == 0) || (expr1[oper] == '*'
				  || expr1[oper] == '^')))
			oper = i;
		 else if ((expr1[i] == '^') && (oper == 0))
			oper = i;
	  }
   }
   if (oper == 0)	//边界情况的处理 
   {
	  if ((expr1[left] == '(') && (expr1[right] == ')'))	//若是括号内的表达式 
		 return (calc(left + 1, right - 1));	//递归计算括号内表达式的值 
	  if (expr1[right] == ')')	//多余的右括号 
		 return (calc(left, right - 1));	//计算去掉右括号后的表达式 
	  if (expr1[left] == '(')	//多余的左括号 
		 return (calc(left + 1, right));	//计算去掉左括号后的表达式 
	  if (expr1[left] == 'a')	//为变量a 
		 return (a);	//返回x的值 
	  num = 0;
	  for (i = left; i <= right; i++)	//为数字 
		 num = num * 10 + expr1[i] - '0';	//累加值       
   }
   else	//递归计算运算符两边 
   {
	  switch (expr1[oper])
	  {
	  case '+':
		 return (calc(left, oper - 1) + calc(oper + 1, right));	//左右表达式的结果相加 
	  case '-':
		 return (calc(left, oper - 1) - calc(oper + 1, right));
	  case '*':
		 return (calc(left, oper - 1) * calc(oper + 1, right));
	  case '^':
		 num = 1;
		 base = calc(left, oper - 1);	//计算左边表达式的值 
		 exp = calc(oper + 1, right);	//计算指数的值 
		 for (i = 1; i <= exp; i++)	//重复乘，得到幂结果 
			num = num * base;
	  }
   }
   return num;	//返回计算结果 
}
int main()
{
   FILE *fp1, *fp2;
   char flag[26] = { 0 };	//标志数组，若为1，表示与题干表达式相同 
   int result, i, n;
   char expr[51], str[26][51];
   if ((fp1 = fopen("equal.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fgets(expr, 50, fp1);
   trim(expr);	//去掉表达式中的空字符
   fscanf(fp1, "%d\n", &n);
   for (i = 0; i < n; i++)
   {
	  fgets(str[i], 50, fp1);
	  trim(str[i]);
   }
   fclose(fp1);
   expr1 = expr;	//全局指针指向表达式字符串 
   result = calc(0, strlen(expr1) - 2);	//计算表达式的值 
   for (i = 0; i < n; i++)	//计算n个表达式的值 
   {
	  if (flag[i] == 0)
	  {
		 expr1 = str[i];
		 if (calc(0, strlen(expr1) - 2) == result)	//若表达式值与题干表达式的值相等 
			flag[i] = 1;
	  }
   }
   if ((fp2 = fopen("equal.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   for (i = 0; i < n; i++)
   {
	  if (flag[i])
	  {
		 printf("%c", i + 'A');	//输出字母顺序到屏幕 
		 fprintf(fp2, "%c", i + 'A');	//输出字母顺序到文件 
	  }
   }
   fclose(fp2);
   getch();
   return 0;
}
