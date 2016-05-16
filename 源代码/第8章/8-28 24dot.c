#include<stdio.h>
int Trial(float, float, float, float);	//对4个数进行试算 
float Calc(int, float, float);	//计算 
void Output(int, int, int, int, float, float, float, float);	//输出结果 
int iCount = 0;	//求解计数 
int main()
{
   int i, j, k, t, result, flag;
   float num[4]; //保存输入的4个数 
   char again = 'y';
   while (again == 'y' || again == 'Y')
   {
	  iCount = 0;
	  printf("\n输入4个数(1~13):");
	  i = 0;
	  flag = 0;
	  while (flag == 0)
	  {
		 i++;
		 for (i = 0; i < 4; i++)	//输入4个数 
		 {
			scanf("%f", &num[i]);
			if (num[i] < 1 || num[i] > 13 || num[i] != (int) (num[i]))	//判断输入数据是否有效 
			   flag++;
		 }
		 if (flag != 0)	//有数据输入错误 
		 {
			printf("数据输入错误,重新输入。\n", i);
			flag = 0;
		 }
         else
			flag = 1;
	  }
	  for (i = 0; i < 4; i++)	//循环将4个数代入表达式进行计算 
	  {
		 for (j = 0; j < 4; j++)
		 {
			if (j == i)	//该数组元素已用 
			   continue;	//继续下一个 
			for (k = 0; k < 4; k++)
			{
			   if (k == i || k == j)	//该数组元素已用
				  continue;	//继续下一个 

			   for (t = 0; t < 4; t++)
			   {
				  if (t == i || t == j || t == k)	//该数组元素已用
					 continue;	//继续下一个 
				  else
					 result = Trial(num[i], num[j], num[k], num[t]);
			   }
			}
		 }
	  }
	  if (result == 0)
		 printf("\n这4个数无解!\n");
	  printf("\n继续(y/n)?");
	  again = getch();
   }
   return 0;
}
int Trial(float data1, float data2, float data3, float data4)	//对4个数进行试算 
{
   int o1, o2, o3;
   float temp1, temp2, temp3;
   for (o1 = 0; o1 < 4; o1++)	//4个运算符 
   {
	  for (o2 = 0; o2 < 6; o2++)	//6种运算符 
	  {
		 for (o3 = 0; o3 < 6; o3++)	//6种运算符 
		 {
			//处理第1种表达式 
			if ((!(o1 == 3 && data2 == 0)) && (!(o2 == 3 && data3 == 0))
			   && (!(o3 == 3 && data4 == 0)))	//若运算符为除法，且除数为0，不执行下面的语句 
			{
			   temp1 = Calc(o1, data1, data2);	//返回a、b两数的运算结果 
			   temp2 = Calc(o2, temp1, data3);	//返回temp1,c两数的计算结果 
			   temp3 = Calc(o3, temp2, data4);	//返回temp2,d两数的计算结果 
			   if (fabs(temp3 - 24) < 0.1)	//判断若temp3与24相等 
			   {
				  iCount++;	//累加次数 
				  Output(1, o1, o2, o3, data1, data2, data3, data4);	//输出第1种算式的解 
			   }
			}
			if (o3 == 2)	//将乘法作为中间的运算符 
			{
			   temp1 = Calc(o1, data1, data2);	//计算a、b的运算结果 
			   temp2 = Calc(o2, data3, data4);	//计算c、d的运算结果 
			   temp3 = temp1 * temp2;	//计算相乘的结果 
			   if (fabs(temp3 - 24) < 0.1)	//若结果等于24
			   {
				  iCount++;
				  Output(2, o1, o2, o3, data1, data2, data3, data4);	//输出第2种算式的解 
			   }
			}
			if (o3 == 3)	//将除法作为中间的运算符 
			{
			   temp1 = Calc(o1, data1, data2);	//计算a、b的结果 
			   temp2 = Calc(o2, data3, data4);	//计算c、d的结果 
			   if (temp2)
			   {
				  temp2 = temp1 / temp2;	//计算相除的结果 
				  if (fabs(temp3 - 24) < 0.1)	//若结果等于24 
				  {
					 iCount++;
					 Output(2, o1, o2, o3, data1, data1, data3, data4);	//输出第2种算式的解 
				  }
			   }
			}
		 }
	  }
   }
   return iCount;
}
float Calc(int oper, float data1, float data2)	//根据运算符计算结果 
{
   if (oper == 0)	//加法 
	  return (data1 + data2);
   if (oper == 1)	//减法 
	  return (data1 - data2);
   if (oper == 2)	//乘法 
	  return (data1 * data2);
   if (oper == 3)	//除法 
	  if (data2 == 0)	//除数为0 
		 return 32767;	//返回一个极大值 
	  else
		 return (data1 / data2);	//返回商 
   if (oper == 4)	//若是反减运算符 
	  return (data2 - data1);
   if (oper == 5)	//若是反除运算符 
	  if (data1 == 0)	//若除数为0 
		 return 32767;	//返回一个极大值 
	  else
		 return (data2 / data1);
   return 0;
}
void Output(int type, int o1, int o2, int o3, float data1, float data2,
   float data3, float data4)	//输出解 
{
   char operator[6];	//保存6种运算符 
   operator[0] = '+';
   operator[1] = '-';
   operator[2] = '*';
   operator[3] = '/';
   operator[4] = '-';
   operator[5] = '/';
   printf("解%d:", iCount);
   if (type == 1)
   {
	  if (o2 == 4 || o2 == 5)	//第2个运算符为反减或反除运算符 
	  {
		 if (o3 == 4 || o3 == 5)	//第3个运算符为反减或反除运算符 
			printf("%2.0f %c (%2.0f %c (%2.0f %c %2.0f)) =24\n", data4,
			   operator[o3], data3, operator[o2], data1, operator[o1], data2);
		 else
			printf("(%2.0f %c (%2.0f %c %2.0f)) %c %2.0f =24\n", data3,
			   operator[o2], data1, operator[o1], data2, operator[o3], data4);
	  } else if (o3 == 4 || o3 == 5)	//第3个运算符为反减或反除运算符 
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
