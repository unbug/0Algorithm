#include <stdio.h>
typedef struct coord
{
   int x;
   int y;
}Coordinate;	//棋盘上的坐标 
int chessboard[8][8] = { 0 };	//棋盘初始状态
int main()
{
   Coordinate start;	//起始坐标 
   int i, j;
   printf("输入马的起始位置坐标:");
   scanf("%d %d", &start.x, &start.y);
   if(start.x< 1  || start.y < 1 
       || start.x > 8 || start.y > 8) //超界 
   {
       printf("坐标输入错误，请重新输入！\n");
       exit(0);
   }
   start.x -= 1;
   start.y -= 1;
   if (travel(start))
   {
	  printf("\n马按以下顺序走:\n");
      for (i = 0; i < 8; i++)	//输出遍过的顺序 
       {
    	  for (j = 0; j < 8; j++)
    	  {
    		 printf("%2d ", chessboard[i][j]);
    	  }
    	  printf("\n");
       }
   }
   else
   {
	  printf("遍历失败！\n");
   }
   getch();
   return 0;
}
int travel(Coordinate start)
{   
   Coordinate move[8] ={ {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
                       {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };//马可走的八个方向
   Coordinate next[8] = { 0 };	//下一步的出路
   int ways[8] = { 0 };	//记录每个方向出路的数量
   Coordinate curpos, tmp; //当前坐标 、临时坐标 
   int i, j, n, m;//循环变量 
   int count, count1, min, tmp1; //计数变量 
   curpos = start;	//从起始位置开始 
   chessboard[curpos.x][curpos.y] = 1;	//标记第1步
   for (n= 2; n <= 64; n++) //循环2~64个位置 
   {
	  for (m = 0; m < 8; m++)
	  {
		 ways[m] = 0;	//清空各位置的出路数为0 
	  }
	  count1 = 0;	//下一个可走位置序号        
	  for (j = 0; j < 8; j++)	//试探八个方向 
	  {
		 tmp.x = curpos.x + move[j].x;	//下一方向的坐标
		 tmp.y = curpos.y + move[j].y;
		 if (tmp.x < 0 || tmp.y < 0 || tmp.x > 7 || tmp.y > 7)	//若下一方向越界了
			continue;	//继续试探其他方向             
		 if (chessboard[tmp.x][tmp.y] == 0)	//若该位置还未走过
		 {
			next[count1] = tmp;	//保存下一方向坐标 
			count1++;	//增加可走方向数量 
		 }
	  }
	  count = count1;	//保存可走方向的数量        
	  if (count == 0)	//若可走方向为0，则返回遍历失败 
	  {
		 return 0; //遍历失败,返回0 
	  }
      else if (count == 1)	//若可走方向只有1个，直接为最少出路的方向
	  {
		 min = 0;
	  }
      else	// 找下一个位置的可出路数
	  {
		 for (m = 0; m < count; m++)	//前面找到的各方向的下一方向 
		 {
			for (j = 0; j < 8; j++)	//试探八个方向 
			{
			   tmp.x = next[m].x + move[j].x;	//下一方向的坐标
			   tmp.y = next[m].y + move[j].y;
			   if (tmp.x < 0 || tmp.y < 0 || tmp.x > 7 || tmp.y > 7)	//越界 
			   {
				  continue;	//继续 
			   }
			   if (chessboard[tmp.x][tmp.y] == 0)	//若该方向未走 
				  ways[m]++;	//增加出路数 
			}
		 }
		 tmp1 = ways[0];	//第1个位置的可走出路数 
		 min = 0;
		 for (m = 1; m < count; m++)	//从可走的位置中查找最少出路的方向
		 {
			if (ways[m] < tmp1)
			{
			   tmp1 = ways[m];
			   min = m;	//找出最少出路的方向 
			}
		 }
	  }
	  curpos = next[min];
	  chessboard[curpos.x][curpos.y] = n;	//记录步数
   }
   return 1;	//遍历成功，返回1 
}
