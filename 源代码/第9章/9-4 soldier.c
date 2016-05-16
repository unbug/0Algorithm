#include <stdio.h>
#define MAXN 21
int chessboard[MAXN][MAXN] = { 0 };
int n, m, x, y;	//n,m为B点的行列坐标位置,x,y为马的坐标位置 
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void horse() //初始化马和其控制点坐标位置 
{
   int i;
   chessboard[x][y] = -1;	//标记马的位置 
   for (i = 0; i < 8; i++)	//标记马下一步的位置 
   {
	  if ((x + dx[i] >= 0 && x + dx[x] <= n) && (y + dy[i] >= 0)
		 && (y + dy[i]) <= m)
		 chessboard[x + dx[i]][y + dy[i]] = -1;
   }
}
void search() //逐步搜寻出路
{
   int i, j;
   for (i = 0; i <= n; i++)	//扫描第0列的各行
   {
	  if (chessboard[i][0] != -1)	//若没有障碍 
		 chessboard[i][0] = 1;	//设置该位置可走路径数为1 
	  else
		 break;
   }
   for (i = 0; i <= m; i++)	//扫描第0行的每列 
   {
	  if (chessboard[0][i] != -1)	//若不是马的控制点 
		 chessboard[0][i] = 1;	//设置该位置可走路径数为1 
	  else
		 break;
   }
   for (i = 1; i <= n; i++)	//扫描各行各列 
   {
	  for (j = 1; j <= m; j++)
	  {
		 if (chessboard[i][j] != -1)	//若该位置不是马的控制点 
		 {
			if ((chessboard[i - 1][j] != -1) && (chessboard[i][j - 1] != -1))	//上面和左边也不是马的控制点
			   chessboard[i][j] = chessboard[i - 1][j] + chessboard[i][j - 1];	//将上面和左边的路径进行累加 
			if ((chessboard[i - 1][j] == -1) && (chessboard[i][j - 1] != -1))	//若上面有马控制点,而左边无马控制点 
			   chessboard[i][j] = chessboard[i][j - 1];	//保存左边路径到到当前位置 
			if ((chessboard[i - 1][j] != -1) && (chessboard[i][j - 1] == -1))	//若上面无马控制点,而左边有马控制点 
			   chessboard[i][j] = chessboard[i - 1][j];	//保存上面路径到当前位置 
			if ((chessboard[i - 1][j] == -1) && (chessboard[i][j - 1] == -1))	//若上面和左边都有马的控制点 
			   chessboard[i][j] = 0;	//当前位置无通路 
		 }
	  }
   }
}
int main()
{
   int i, j;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("soldier.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1,"%d%d%d%d", &n, &m, &x, &y);
   fclose(fp1);
   horse();	//初始化马及其下一步的位置 
   search();
   if ((fp2 = fopen("soldier.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n", chessboard[n][m]);
   fprintf(fp2,"%d\n",chessboard[n][m]);
   fclose(fp2);
   getch();
   return 0;
}
