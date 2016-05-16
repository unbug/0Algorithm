#include <stdio.h>
#define MAXN 1001
int main()
{
   int num[6], flag[MAXN] = { 0 }; //保存6种砝码的数量 
   int poise[6] = { 1, 2, 3, 4, 10, 20 };	//不同重量的砝码 
   int i, j, k, total;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("poise.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   for (i = 0; i < 6; i++)	//读入各种砝码的数量
	  fscanf(fp1, "%d", &num[i]);
   fclose(fp1);
   total = 0;
   flag[0] = 1;
   for (i = 0; i < 6; i++) //循环检查6种砝码 
   {
	  for (j = 0; j < num[i]; j++) //分别用不同数量砝码 
	  {
		 for (k = MAXN - 1; k >= poise[i]; k--)
			if (flag[k - poise[i]] == 1 && flag[k] == 0)
			{
			   flag[k] = 1;
			   total++;
			}
	  }
   }
   if ((fp2 = fopen("poise.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("Total=%d\n", total);
   fprintf(fp2, "Total=%d\n", total);
   fclose(fp2);
   getch();
   return 0;
}
