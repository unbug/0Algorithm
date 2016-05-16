#include<stdio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct
{
   int x;
   int y;
}Coordinate; //坐标位置 
int chessboard[8][8] = { 0 };
Coordinate move[8] ={ {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
                    {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };//马可走的八个方向

typedef struct
{
   int ord; //步数序号 
   Coordinate seat; //位置 
   int di; //方向 
}SElemType; //栈操作的节点 
typedef struct
{
   SElemType *base;
   SElemType *top;
   int stacksize;
}SqStack; //栈结构 
int InitStack(SqStack * s1)
{
   s1->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
   if (!s1->base)
	  exit(1);
   s1->top = s1->base;
   s1->stacksize = STACK_INIT_SIZE;
   return (1);
}
SElemType Pop(SqStack * s, SElemType e)
{
   e = *(--s->top);
   return e;
}
int Push(SqStack * s1, SElemType e)
{
   if (s1->top - s1->base >= s1->stacksize)
   {
	  s1->base =
		 (SElemType *) realloc(s1->base,
		 (s1->stacksize + STACKINCREMENT) * sizeof(SElemType));
	  if (!s1->base)
		 exit(1);
	  s1->top = s1->base + s1->stacksize;
	  s1->stacksize += STACKINCREMENT;
   }
   *(s1->top++) = e;
   return 1;
}
int StackEmpty(SqStack * s)
{
   if (s->base == s->top)
	  return (1);

   else
	  return (0);
}

int Pass(Coordinate s) //是否能通过 
{
   if ((chessboard[s.x][s.y] == 0) && (s.x <= 7) && (s.x >= 0) && (s.y <= 7)
	  && (s.y >= 0))
	  return (1);
   else
	  return (0);
}
Coordinate NextPos(Coordinate s, int i) //下一位置 
{
   s.x = s.x + move[i].x;
   s.y = s.y + move[i].y;
   return (s);
}
void knight(Coordinate start)
{
   int curstep = 0;
   SqStack S;
   SElemType e;
   Coordinate curpos = start; //当有位置 
   InitStack(&S); //初始化栈 
   do
   {
	  if (Pass(curpos)) //若当前位置可走
	  {
		 curstep++;  //步数增加 
		 chessboard[curpos.x][curpos.y] = curstep; //保存步数序号 
		 e.seat = curpos; //保存当前位置 
		 e.ord = curstep; //步数 
         e.di = 0; //方向 
		 Push(&S, e); //入栈 
		 if (curstep == 64) //若已走完64个单元格
		 {       
            break; //退出循环
         }
		 else
		 {
             curpos = NextPos(curpos, e.di); //取下一位置 
         }
	  }
	  else //若当前位置不可走 
	  {
		 if (!StackEmpty(&S)) //若栈不为空 
		 {
			Pop(&S, e); //将上一步出栈 
			if (e.di == 7) //若8个位置都走过
            { 
                chessboard[e.seat.x][e.seat.y] = 0; //取消该步的步数序号 
            }
			while (e.di == 7 && !StackEmpty(&S)) //当前8个位置已走完，且栈不为空 
			{
			   e = Pop(&S, e); //出栈 
			   if (e.di == 7) //若8个位置都试探过了 
				  chessboard[e.seat.x][e.seat.y] = 0; //取消该步的步数序号 
			   curstep = e.ord; //保存步数序号 
			}
			if (e.di < 7) //若还有位置未进行试探 
			{
               e.di++; //试探下一位置  
			   Push(&S, e); //入栈 
			   curpos = NextPos(e.seat, e.di); //取下一位置 
			}
		 }
	  }
   } while (!StackEmpty(&S)); //若栈中还有数据，继续循环 
   if (StackEmpty(&S)) //若栈为空 
   {
	  printf("遍历失败!\n");
	  printf("请按任意键推出本程序\n");
	  getch();
	  exit(1);
   }
}
int main()
{
   int i,j;
   Coordinate start;
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
   knight(start);
   printf("马的路线:\n");
   for (i = 0; i < 8; i++)
   {
	  for (j = 0; j < 8; j++)
		 printf("%4d", chessboard[i][j]);
       printf("\n");
   }
   getch();
   return 0;
}
