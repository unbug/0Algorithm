#include  <stdio.h>
#define MAXLEN 30	// 迷宫包括外墙最大行列数目
#define INIT_SIZE 100	// 存储空间初始分配量
typedef struct
{
   int row; //迷宫的行数 
   int column; //迷宫的列数 
   char grid[MAXLEN][MAXLEN];	//1表示障碍,0表示空,2表示可通，3表示已走过但不通
}MazeType;						// 迷宫类型 
typedef struct					// 迷宫中的坐标 
{
   int row;//行号 
   int column; //列号 
}Coordinate;
typedef struct
{
   int ord;						// 当前位置在路径上的序号
   Coordinate seat;				// 当前坐标 
   int di;						// 往下一坐标的方向 
}MazeNode;						// 栈元素类型 
typedef struct
{
   MazeNode base[INIT_SIZE]; //迷宫节点信息
   int top; //栈顶指针 
}Stack;							// 栈类型 
int InitStack(Stack *S) // 构造空栈s
{
   S->top = -1;
   return 1;
}
int StackEmpty(Stack *s)		// 若s为空返回TRUE,否则返回FALSE 
{
   if (s->top == -1)
	  return 1;   
   return 0;
}
int StackIsFull(Stack *s) //判断栈是否为满
{
   if (s->top == INIT_SIZE - 1)
	  return 1;
   else
	  return 0;
}
int Push(Stack *s, MazeNode mn)	// 插入元素e为新的栈顶元素 
{
   if (!StackIsFull(s)) //若栈未满 
   {
	  s->top++; //修改栈顶指针 
	  s->base[s->top] = mn; //将节点信息入栈 
   }
}
int Pop(Stack *s, MazeNode *mn)	// 若栈不空删除栈//顶元素用e返回并返回OK，否则返回ERROR 
{
   if (s->top != -1) //栈不为空 
   {
	  *mn = s->base[s->top];
	  s->top--;
	  return 1;
   }
   return 0;
}
int DestroyStack(Stack *s)	//销毁栈S 
{
   s->top=-1;
   return 1;
}
int MazeInit(MazeType *maze) // 初始化迷宫
{
   int m, n, i, j;
   printf("输入迷宫的行数和列数:");
   scanf("%d%d", &maze->row, &maze->column);	// 迷宫行和列数 
   for (i = 0; i <= maze->column + 1; i++)// 迷宫行外墙 
   {	
	  maze->grid[0][i] = '1'; //设置为障碍墙 
	  maze->grid[maze->row + 1][i] = '1';
   }
   for (i = 0; i <= maze->row + 1; i++)// 迷宫列外墙 
   {	
	  maze->grid[i][0] = '1';//设置为障碍墙 
      maze->grid[i][maze->column + 1] = '1';
   }
   for (i = 1; i <= maze->row; i++)	// 初始化迷宫 
	  for (j = 1; j <= maze->column; j++)
		 maze->grid[i][j] = '0'; //设置为可通过 
   printf("输入障碍墙的坐标(输入坐标(0,0)结束): ");								// 
   while(1)
   {
       scanf("%d%d", &m, &n);	// 接收障碍的坐标 
       if(m==0) //输入0 
           break; //结束坐标的输入 
       if (m<=0 || n<=0 || m > maze->row || n > maze->column) //越界 
       {
           printf("坐标越界，重新输入!\n");
           continue; 
       }
       maze->grid[m][n] = '1';	// 迷宫障碍用'1'标记
   }
   return 1;
}
int Pass(MazeType *maze, Coordinate pos)	//判断指定坐标是否可通过 
{
   if (maze->grid[pos.row][pos.column] == '0')	// 可通 
	  return 1;
   else
	  return 0;
}
int MarkerPass(MazeType *maze, Coordinate pos)	//标记可通过 
{
   maze->grid[pos.row][pos.column] = '2';	//"2"表示可通 
   return 1;
}
Coordinate NextCoord(Coordinate pos, int i)	//获取下一位置 
{
   switch(i)	// 1.2.3.4分别表示东,南,西,北方向 
   {
   case 1:
	  pos.column += 1; //向右侧查找 
	  break;
   case 2: //向下方查找 
	  pos.row += 1;
	  break;
   case 3: //向左侧查找 
	  pos.column -= 1;
	  break;
   case 4: //向上方查找 
	  pos.row -= 1;
	  break;
   default:
	  exit(0);
   }
   return pos;
}
int MarkerNoPass(MazeType *maze, Coordinate pos)	// 曾走过但不是通路标记并返回OK 
{
   maze->grid[pos.row][pos.column] ='3';	// "3"表示曾走过但不通 
   return 1;
} 
int MazePath(MazeType *maze, Coordinate start, Coordinate end)//从迷宫maze的入口到出口查找路径
{
   Stack S; //定义栈 
   Coordinate pos;
   int curstep;	// 当前序号,1.2.3.4分别表示东,南,西,北方向 
   MazeNode e;
   InitStack(&S); //初始化栈 
   pos = start;	//从入口位置开始查找路径 
   curstep = 1;	// 探索第一步 
   do
   {
	  if (Pass(maze, pos))	//若指定位置可通过
	  {
		 MarkerPass(maze, pos);	//标记能通过 
		 e.ord = curstep; //保存步数 
		 e.seat = pos; //保存当前坐标 
		 e.di = 1; //向右侧控测 
		 Push(&S, e);	//将节点添加到栈中(保存路径)
		 if (pos.row == end.row && pos.column == end.column) //若当前位置是出口坐标 
		 {
			DestroyStack(&S); //释放栈占用的空间 
		    return 1;//返回查找成功 
		 }
         else //与出口坐标不同 
		 {
			pos = NextCoord(pos, 1);//向右侧探测 
			curstep++;	//增加前进步数 
		 }
	  }
	  else	//若指定位置不通(为障碍墙或已走过)
	  {
		 if (!StackEmpty(&S))//若栈不为空(之前有走过的位置) 
		 {
			Pop(&S, &e); //出栈(返回上一步的位置) 
			while (e.di == 4 && !StackEmpty(&S)) //上一步4个方向都探测完,且栈不为空 
			{
			   MarkerNoPass(maze, e.seat); //标记该位置不为通 
			   Pop(&S, &e);//出栈(返回上一步) 
			}
			if (e.di < 4) //若未探测完4个方向 
			{
			   e.di++;	//准备探测下一个方向 
			   Push(&S, e);//将当前节点入栈(保存当前位置，准备下一位置的探测) 
			   pos = NextCoord(e.seat, e.di);	//查找下一个应该探测位置的坐标 
			}
		 }
	  }
   }while (!StackEmpty(&S));
   //程序运行到这里，表示没有能通达的路径 
   DestroyStack(&S); //释放栈占用的空间 
   return 0; //返回失败 
}
void PrintMaze(MazeType *maze)//输出迷宫 
{
   int i, j;
   printf("\n迷宫路径(◇表示通路):\n");
   for (i = 0; i <= maze->row + 1; i++)
   {
	  for (j = 0; j <= maze->column + 1; j++)
	  {
         if ( maze->grid[i][j] == '1') //若是障碍墙 
            printf("█");
         else if ( maze->grid[i][j] == '2') //若是可通路径 
            printf("◇");
         else //其他位置 
            printf("  ");
      }
	  printf("\n");
   }
}
int main()
{ 
    MazeType maze; //迷宫数据 
    Coordinate start, end;
    char cmd;
    printf("创建迷宫\n");
    if (!MazeInit(&maze))// 初始化并创建迷宫 
    {
        printf("\n创建迷宫结构时出错!\n");
        exit(-1);	// 初始化错误 
    }
    do	// 输入迷宫入口坐标 
    {
        printf("\n输入迷宫入口坐标:");
        scanf("%d%d", &start.row, &start.column);
        if (start.row > maze.row || start.column > maze.column)
        {
            printf("\n输入的坐标越界，重新输入!\n");
            continue;
        }
    }while (start.row > maze.row || start.column > maze.column);
    do// 输入迷宫出口坐标 
    {
        printf("\n输入迷宫出口坐标:");
        scanf("%d%d", &end.row, &end.column);
        if (end.row > maze.row || end.column > maze.column)
        {
            printf("\n输入的坐标越界，重新输入!\n");
            continue;
        }
    }while (end.row > maze.row || end.column > maze.column);
    if (!MazePath(&maze, start, end))	//调用函数查找路径 
        printf("\n没有路径可由入口到达出口!\n");
    else
        PrintMaze(&maze);	// 打印找到的路径 
    getch();
    return 0;
}
