#include <stdio.h>
#define MAXN 100
int main()
{
   int i, j, n, total = 0, sum, ave, num[MAXN];
   FILE *fp1, *fp2;
   if ((fp1 = fopen("card.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);	//读入牌堆数 
   sum = 0;
   for (i = 0; i < n; i++)	//读入每堆牌的牌数 
   {
	  fscanf(fp1, "%d", &num[i]);
	  sum += num[i];	//汇总 
   }
   fclose(fp1);	//关闭文件 
   ave = sum / n;	//计算平均值 
   for (i = 0; i < n; i++)	//计算每堆牌与平均值的差 
	  num[i] -= ave;
   i = 0;
   j = n - 1;
   while (num[i] == 0)	//跳过左边的0 
	  i++;
   while (num[j] == 0)	//跳过右边的0 
	  j--;
   while (i < j)
   {
	  num[i + 1] += num[i];	//将左边的牌移到右边
	  num[i] = 0;	//使左边的牌数与平均值相等 
	  total++;	//增加一次移动操作
	  i++;	//准备移动下一堆牌
	  while (num[i] == 0)	//跳过右侧已为0的牌堆 
		 i++;
   }
   if ((fp2 = fopen("card.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n", total);	//输出需要移动的步数 
   fprintf(fp2, "%d\n", total);
   fclose(fp2);
   getch();
   return 0;
}
