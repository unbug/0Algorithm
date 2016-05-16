#include <stdio.h>
#include <limits.h>
#define MAXN 1000
int height[MAXN], flag[MAXN] = { 0 };
int n, max, min;

int main()
{
   int i, j;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("missile.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);
   for (i = 1; i <= n; i++)
	  fscanf(fp1, "%d", &height[i]);
   fclose(fp1);
   height[0] = INT_MAX; //在0号元素设置为一个最大值 
   for (i = 1; i <= n; i++)
   {
	  for (j = i - 1; j >= 0; j--)	//第1~i个导弹中可击拦截多少个 
	  {
		 if (height[j] >= height[i] && (flag[j] + 1 > flag[i]))
			flag[i] = flag[j] + 1;
	  }
   }
   max = 0;
   for (i = 1; i <= n; i++) //将最大值保存到max变量中 
   {
	  if (flag[i] > max)
		 max = flag[i];
   }
   for (i = 0; i < MAXN; i++) //重置flag标志数组 
	  flag[i] = 0;
   height[0] = 0; //将0号元素设置为一个最小值 
   for (i = 1; i <= n; i++)
   {
	  for (j = i - 1; j >= 0; j--) //判断1~i个导弹需要的系统数 
	  {
		 if (height[j] < height[i] && (flag[j] + 1 > flag[i]))
			flag[i] = flag[j] + 1;
	  }
   }
   min = 0;
   for (i = 1; i <= n; i++)	//查找最小序列 
   {
	  if (flag[i] > min)
		 min = flag[i];
   }
   if ((fp2 = fopen("missile.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n%d\n", max, min);
   fprintf(fp2, "%d\n%d\n", max, min);
   getch();
   return 0;
}
