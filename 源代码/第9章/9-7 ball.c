#include <stdio.h>
int main()
{
   FILE *fp1, *fp2;
   int s[31][31] = { 0 };
   int i, j, k, m, n;
   if ((fp1 = fopen("ball.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   s[0][0] = 1; //最初球在序号为0的人手中 
   fscanf(fp1, "%d%d", &n, &m); //从文件中读取游戏人数和传球次数 
   fclose(fp1);//关闭文件 
   for (i = 1; i <= m; i++) //循环传球m次 
   {
	  s[i][0] = s[i - 1][n - 1] + s[i - 1][1]; //第1个人单独处理
	  for (j = 1; j < n - 1; j++) //循环向左或向右传 
		 s[i][j] = s[i - 1][j - 1] + s[i - 1][j + 1];
	  s[i][n - 1] = s[i - 1][n - 2] + s[i - 1][0]; //末1个人单独处理
   }
   if ((fp2 = fopen("ball.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n",s[m][0]);
   fprintf(fp2, "%d\n", s[m][0]);//输出第0个人第m次传球的方案数 
   fclose(fp2);
   getch();
   return 0;
}
