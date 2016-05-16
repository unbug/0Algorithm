#include <stdio.h>
#define MAXROW 10 //最大行数 
#define MAXCOL 10 //最大列数 
#define DEAD 0 //死细胞 
#define ALIVE 1 //活细胞 
int cell[MAXROW][MAXCOL], tempcell[MAXROW][MAXCOL]; //当前生命细胞的状态，一个用于判断当前的细胞的下一个状态
void init(); //初始化细胞数组 
int BorderSum(int, int); //统计当前细胞四周的细胞数 
void Output(); //输出细胞状态 
int main()
{
   int row, col,sum1;
   char again;
   init(); //初始化，输入细胞的位置 
   Output();   //输出细胞初始状态 
   printf("按任意键进行转换。\n");
   getch(); 
   while (1)
   {	  
	  for (row = 0; row < MAXROW; row++)
	  {
		 for (col = 0; col < MAXCOL; col++)
		 {
			switch (BorderSum(row, col)) //(row,col)单元格四周的生细胞数量 
			{
			case 0:
			case 1:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			   tempcell[row][col] = DEAD; //将原细胞改为死细胞 
			   break;
			case 2:
			   tempcell[row][col] = cell[row][col]; //保持细胞原样 
			   break;
			case 3:
			   tempcell[row][col] = ALIVE; //将细胞改为活细胞 
			   break;
			}
		 }
	  }
      for (row = 0; row < MAXROW; row++)//复制临时数组到map数组
    	  for (col = 0; col < MAXCOL; col++)
    		 cell[row][col] = tempcell[row][col];
      sum1=AliveSum();
      if(sum1==0) //若活细胞数量为0 
          break;//跳出循环 
      Output(); //输出转换后的细胞状态 
      printf("共有%d个活细胞。\n",sum1); 
      printf("\n继续生成下一次细胞的状态(n退出)？");
	  again = getch();
	  if (again == 'N' || again == 'n')
		 break;
   }
   getch();
   return 0;
}
void init() //初始化 
{
   int row, col;
   for (row = 0; row < MAXROW; row++) //先全部初始化为死状态 
	  for (col = 0; col < MAXCOL; col++)
		 cell[row][col] = DEAD;
   printf("生命游戏\n");
   printf("输入活细胞的坐标位置，输入(-1 -1)结束:\n");
   while (1)
   {
	  scanf("%d %d", &row, &col); //输入行列坐标 
	  if (0 <= row && row < MAXROW && 0 <= col && col < MAXCOL)
		 cell[row][col] = ALIVE; //保存生细胞 
	  else if (row == -1 || col == -1)
		 break;
	  else
		 printf("输入坐标超过范围。\n"); 
   }
}
int BorderSum(int row, int col) //统计四周细胞数量 
{
   int count = 0, c, r;
   for (r = row - 1; r <= row + 1; r++)
   {
	  for (c = col - 1; c <= col + 1; c++)
	  {
		 if (r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL) //超过数组界限 
			continue; //处理下一个单元格 
		 if (cell[r][c] == ALIVE) //若为活细胞 
			count++; //增加活细胞的数量 
	  }
   }
   if (cell[row][col] == ALIVE) //若当前单元格为活细胞 
	  count--; //活细胞总数减1 
   return count; //返回四周活细胞总数 
}
void Output() //输出细胞状态 
{
   int row, col;
   printf("\n细胞状态\n");
   printf("┌");	//输出项部横线 
   for (col = 0; col < MAXCOL -1; col++)	//输出一行 
	  printf("─┬");
   printf("─┐\n");
   for (row = 0; row < MAXROW; row++)
   {
	  printf("│");	//输出行号
	  for (col = 0; col < MAXCOL; col++)	//输出棋盘各单元格中棋子的状态 
	  {
		 if (cell[row][col] == ALIVE  )	//活细胞 
			printf("●│");
		 else 	//死细胞 
			printf("○│");
	  }
	  printf("\n");

	  if (row < MAXROW - 1)
	  {
		 printf("├");	//输出交叉线 
		 for (col = 0; col < MAXCOL - 1; col++)	//输出一行 
			printf("─┼");
		 printf("─┤\n");
	  }
   }
   printf("└");
   for (col = 0; col < MAXCOL - 1; col++)	//最后一行的横线 
	  printf("─┴");
   printf("─┘\n");   
}
int AliveSum() //统计生细胞的数量 
{
   int row,col,count=0;
   for (row = 0; row < MAXROW; row++)
   {
	  for (col = 0; col < MAXCOL; col++)
	  {
		 if(cell[row][col] == ALIVE) //若是活细胞 
             count++; //累加数量 
      }
   }
   return count;
}
