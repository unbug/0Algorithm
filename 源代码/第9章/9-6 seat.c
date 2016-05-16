#include <stdio.h>
#define MAXN 1001
void swap(int *a, int *b)	//交换数据 
{
   int t;
   t = *a;
   *a = *b;
   *b = t;
}
int main()
{
   FILE *fp1, *fp2;
   int row[MAXN], col[MAXN], temp[MAXN];
   int m, n, k, l, d;	//m行n列，k条横向通道，l条纵向通道,d对同学上课说话 
   int x1, y1, x2, y2;	//两个相互说话同学的位置 
   int i, j;
   if ((fp1 = fopen("seat.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d%d%d%d\n", &m, &n, &k, &l, &d);
   for (i = 1; i <= m; i++)	//设置不插入横向通道 
	  row[i] = 0;
   for (i = 1; i <= n; i++)	//设置不插入纵向通道 
	  col[i] = 0;
   for (i = 0; i < d; i++)	//读入文件中每行的数据,统计在每行、每列添加通道可以分割的学生数
   {
	  fscanf(fp1, "%d%d%d%d", &y1, &x1, &y2, &x2);	//读入要说话的两个坐标位置 
	  if (x1 == x2)	//若在同一列
	  {
		 if (y1 > y2)
			swap(&y1, &y2);	//交换列号，使低列号排在前面 
		 row[y1]++;	//在y1位置增加一条横向通道分隔同一列的同学 
	  } else if (y1 == y2)	//在同一行 
	  {
		 if (x1 > x2)
			swap(&x1, &x2);	//交换行号，使低行号排在前面 
		 col[x1]++;	//在x1位置增加一条纵向通道分隔同一行的同学 
	  }
   }
   fclose(fp1);	//关闭文件 
   for (i = 0; i <= m; i++)	//temp中保存行号,准备排序 
	  temp[i] = i;
   for (i = 1; i < m; i++)	//对横向通道分隔说话学生对数进行排序 
	  for (j = i + 1; j <= m; j++)
		 if (row[i] < row[j])	//第i行设通道分隔说话学生少于第j行 
		 {
			swap(&row[i], &row[j]);	//交换通道位置 
			swap(&temp[i], &temp[j]);	//交换行号 
		 }
   for (i = 1; i < k; i++)	//对前k条横向通道进行排序 
	  for (j = i + 1; j <= k; j++)
		 if (temp[i] > temp[j])	//使低行号排在前面 
			swap(&temp[i], &temp[j]);
   if ((fp2 = fopen("seat.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   for (i = 1; i <= k; i++)	//输出横向通道位置 
   {
	  printf(" %d", temp[i]);
	  fprintf(fp2, " %d", temp[i]);
   }
   printf("\n");
   fprintf(fp2, "\n");
   for (i = 0; i <= n; i++)	//将列号保存到temp数组中，准备排序
	  temp[i] = i;
   for (i = 1; i < n; i++)	//对纵向通道分隔说话学生对数进行排序
	  for (j = i + 1; j <= n; j++)
		 if (col[i] < col[j])
		 {
			swap(&col[i], &col[j]);	//交换通道位置 
			swap(&temp[i], &temp[j]);	//交换列号 
		 }
   for (i = 1; i < l; i++)	//对前L条纵向通道进行排序 
	  for (j = i + 1; j <= l; j++)
		 if (temp[i] > temp[j])	//使低列号排在前面 
			swap(&temp[i], &temp[j]);
   for (i = 1; i <= l; i++)	//输出纵向通道 
   {
	  printf(" %d", temp[i]);
	  fprintf(fp2, " %d", temp[i]);
   }
   fprintf(fp2, "\n");
   fclose(fp2);
   getch();
   return 0;
}
