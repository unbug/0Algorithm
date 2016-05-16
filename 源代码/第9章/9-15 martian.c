#include <stdio.h>
int max;
int a[10000], collect[10000];
int fact(int p)	//计算阶乘 
{
   int i, f;
   f = 1;
   for (i = 1; i <= p; i++)	//计算阶乘 
	  f *= i;
   return f;	//返回阶乘结果 
}
int position(int num)	//求数num在集合中位置序号 
{
   int i, pos;
   pos = 0;
   for (i = 1; i <= num; i++)
	  if (collect[i] == 1)	//若在集合中 
		 pos++;	//累加序号 
   return pos;	//返回序号 
}
int makebit(int pos)	//求集合中位置p的数
{
   int i = 0, num = 0;
   while (i < pos)
   {
	  num++;	//累加数 
	  if (collect[num] == 1)	//若该数在集合中 
		 i++;	//计数器加1 
   }
   return num;	//返回对应位的数 
}
int result(int pos)	//计算组合数中前pos位所表示的数
{
   int i, num, x;
   x = max;	//只变动组合前（p-1）位能表示的最大数；
   num = 0;
   for (i = pos; i >= 1; i--)
   {
	  x /= i;	//计算系数 
	  num += (position(a[i]) - 1) * x;	//累加a[i]位所表示的值 
	  collect[a[i]] = 0;	//将a[i]排除在组合之外 
   }
   return num + 1;	//返回前p位所表示的数 
}
void fill(int p, int num)	//把数num按规则填入集合中
{
   int i, s;
   s = max;
   for (i = p; i >= 2; i--)
   {
	  s /= i;
	  if (num % s == 0)	//数num能被系数整除 
	  {
		 a[i] = makebit(num / s);	//填充位 
		 num = s;	//下一步处理系数 
	  } else	//不能被整除 
	  {
		 a[i] = makebit(num / s + 1);	//填充位的值 
		 num = num % s;	//下一步处理余数
	  }
	  collect[a[i]] = 0;	//将数a[i]排除在集合中 
   }
   a[1] = makebit(1);	//在第1位放置数1
}
int main()
{
   int n, m, i, s;
   int p1, p, yes;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("martian.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);	//火星人指头数 
   fscanf(fp1, "%d\n", &m);	//累加的一个数 
   for (i = n; i >= 1; i--)	//读入数据到数组中 
	  fscanf(fp1, "%d", &a[i]);
   fclose(fp1);	//关闭文件 
   p = 0;
   for (i = 1; i <= n; i++)	//初始化数组 
	  collect[i] = 0;
   p++;
   while (fact(p) <= m)	//计算m应处理的位数p
	  p++;
   max = fact(p);	//max为常量，存放p!
   for (i = 1; i <= p; i++)	//设置集合
	  collect[a[i]] = 1;
   m += result(p);	//计算前p位所表示的数与m相加后所得值
   for (i = 1; i <= p; i++)	//重置集合
	  collect[a[i]] = 1;
   if (m <= max)	//不用进位即可表示相加后的数 
	  fill(p, m);	//将数m填充为原来的序列 
   else
   {
	  m -= max;	//进位后m余的数
	  p1 = p;
	  yes = 0;
	  do
	  {
		 p1++;
		 collect[a[p1]] = 1;
		 if (position(a[p1]) != p1)
			yes = 1;
	  }
	  while (yes == 0);	//求出要进位的数所在位置p1
	  s = makebit(position(a[p1]) + 1);
	  collect[s] = 0;	//排除集合 
	  a[p1] = s;	//进位位保存进位的值 
	  for (i = p1 - 1; i <= p + 1; i++)	//组合数中第p1-1位到第p+1位按从小到大排列
	  {
		 s = makebit(1);	//第1位的数 
		 a[i] = s;	//保存到a[i]中 
		 collect[s] = 0;	//除数到集合之外 
	  }
	  fill(p, m);	//将数m填充为原来的序列 
   }
   if ((fp2 = fopen("martian.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   for (i = n; i >= 2; i--)
   {
	  printf("%d ", a[i]);
	  fprintf(fp2, "%d ", a[i]);
   }
   printf("%d\n", a[1]);
   fprintf(fp2, "%d\n", a[1]);
   fclose(fp2);
   getch();
   return 0;
}
