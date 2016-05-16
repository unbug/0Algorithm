#include <stdio.h>
#include <limits.h>
#define MAXN 5000
int n, price[MAXN], flag[MAXN], cnt[MAXN];
int max(int x, int y)
{
   if (x > y)
	  return x;
   else
	  return y;
}
int main()
{
   int i, j, k, max1, last, total;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("buylow.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d", &n);
   for (i = 1; i <= n; i++)
	  fscanf(fp1, "%d", &price[i]);
   fclose(fp1);
   price[0] = INT_MAX;	//将第0个元素设置为一个最大整数值 
   max1 = 1;	//设置最多天数初始值为1 
   flag[1] = 1;
   for (i = 2; i <= n; i++)	//计算前i天中最大购买次数 
   {
	  flag[i] = 1;
	  for (j = 1; j < i; j++)
	  {
		 if (price[j] > price[i])
			flag[i] = max(flag[i], flag[j] + 1);	//状态转移方程 
	  }
	  max1 = max(max1, flag[i]);	//取最大值 
   }
   cnt[1] = 1;	//初始为1次 
   for (i = 2; i <= n; i++)
   {
	  last = -1;
	  if (flag[i] == 1)	//若第i天之前最大购买天数为 1 
	  {
		 cnt[i] = 1;	//设置序列数为1 
		 continue;
	  }
	  for (j = i - 1; j >= 1; j--) //检查flag标志中的值 
	  {
		 if (flag[j] + 1 == flag[i] && price[j] > price[i]
			&& price[j] != last)
		 {
			cnt[i] += cnt[j]; //增加序列数 
			last = price[j];
		 }
	  }
   }
   total = 0;	//序列数清0 
   last = -1;
   for (i = n; i >= 1; i--)	//从后向前累加序列数 
   {
	  if (flag[i] == max1 && price[i] != last)
	  {
		 total += cnt[i]; 
		 last = price[i];
	  }
   }
   if ((fp2 = fopen("buylow.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d,%d\n", max1, total);	//输出结果
   fprintf(fp2, "%d,%d\n", max1, total);
   fclose(fp2);
   getch();
   return 0;
}
