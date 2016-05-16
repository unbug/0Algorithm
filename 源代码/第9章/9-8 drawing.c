#include <stdio.h>
#define MAXN 51
char canvas[500][500]; //保存立体图的画布 
void draw(int x, int y)	//x,y为坐标，绘制立方体 
{
   canvas[y][x] = '+';	//左下角 
   canvas[y][x + 1] = '-';	//下横线 
   canvas[y][x + 2] = '-';
   canvas[y][x + 3] = '-';
   canvas[y][x + 4] = '+';	//右下角 
   canvas[y + 1][x] = '|';	//向上数的第2行，绘竖线 
   canvas[y + 1][x + 1] = ' ';	//3个空格 
   canvas[y + 1][x + 2] = ' ';
   canvas[y + 1][x + 3] = ' ';
   canvas[y + 1][x + 4] = '|';
   canvas[y + 1][x + 5] = '/';	//绘斜线 
   canvas[y + 2][x] = '|';	//向上数的第3行,绘竖线 
   canvas[y + 2][x + 1] = ' ';	//3个空格 
   canvas[y + 2][x + 2] = ' ';
   canvas[y + 2][x + 3] = ' ';
   canvas[y + 2][x + 4] = '|';
   canvas[y + 2][x + 5] = ' ';	//空格 
   canvas[y + 2][x + 6] = '+';	//向上转的加号 
   canvas[y + 3][x] = '+';	//向上数的第4行,绘加号 
   canvas[y + 3][x + 1] = '-';	//3个横线 
   canvas[y + 3][x + 2] = '-';
   canvas[y + 3][x + 3] = '-';
   canvas[y + 3][x + 4] = '+';	//转角加号 
   canvas[y + 3][x + 5] = ' ';	//空 
   canvas[y + 3][x + 6] = '|';	//竖线 
   canvas[y + 4][x + 1] = '/';	//向上数的第5行，绘斜线 
   canvas[y + 4][x + 2] = ' ';	//3个空格 
   canvas[y + 4][x + 3] = ' ';
   canvas[y + 4][x + 4] = ' ';
   canvas[y + 4][x + 5] = '/';	//斜线 
   canvas[y + 4][x + 6] = '|';	//竖线 
   canvas[y + 5][x + 2] = '+';	//向上数的第6行,绘转角加号 
   canvas[y + 5][x + 3] = '-';	//横线 
   canvas[y + 5][x + 4] = '-';
   canvas[y + 5][x + 5] = '-';
   canvas[y + 5][x + 6] = '+';
}
int main()
{
   FILE *fp1, *fp2;
   int a[MAXN][MAXN];
   int width, height, t, x, y;
   int i, j, k, m, n;
   if ((fp1 = fopen("drawing.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d", &m, &n); //从文件中读入行列 
   width = 4 * n + 2 * m + 1; //计算画布宽度 
   height = 0; //设置画布高度初始值为0 
   for (i = 0; i < m; i++) 
   {
	  for (j = 0; j < n; j++)
	  {
		 fscanf(fp1, "%d", &a[i][j]); //从文件中获取矩阵数据
		 t = 3 * a[i][j] + 2 * (m - i) + 1; //计算高度 
		 if (t > height) //保存画布最高值 
			height = t;
	  }
   }
   fclose(fp1); //关闭文件 
   for (i = 0; i < height; i++) //清空画布，设置背景为点 
	  for (j = 0; j < width; j++)
		 canvas[i][j] = '.';
   for (i = 0; i < m; i++) //宽度方向m个立方体 
   {
	  for (j = 0; j < n; j++) //长度方向，n个立方体 
	  {
		 for (k = 0; k < a[i][j]; k++) //高度方向 
		 {
			x = 2 * (m - i - 1) + 4 * j; //计算立方体横向坐标 
			y = 2 * (m - i - 1) + 3 * k; //计算立方体纵向坐标 
			draw(x, y); //在(x,y)坐标位置绘制一个立方体 
		 }
      }
   }
   if ((fp2 = fopen("drawing.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   for (i = height - 1; i >= 0; i--) //将立体图形输出到文件 
   {
	  for (j = 0; j < width; j++)
		 fprintf(fp2, "%c", canvas[i][j]);
	  fprintf(fp2, "\n");
   }
   for (i = height - 1; i >= 0; i--) //将立体图形输出到屏幕 
   {
	  for (j = 0; j < width; j++)
		 printf("%c", canvas[i][j]);
	  printf("\n");
   }
   getch();
   return 0;
}
