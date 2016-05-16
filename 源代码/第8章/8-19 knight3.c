#include<stdio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct
{
   int x;
   int y;
}Coordinate; //����λ�� 
int chessboard[8][8] = { 0 };
Coordinate move[8] ={ {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
                    {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };//����ߵİ˸�����

typedef struct
{
   int ord; //������� 
   Coordinate seat; //λ�� 
   int di; //���� 
}SElemType; //ջ�����Ľڵ� 
typedef struct
{
   SElemType *base;
   SElemType *top;
   int stacksize;
}SqStack; //ջ�ṹ 
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

int Pass(Coordinate s) //�Ƿ���ͨ�� 
{
   if ((chessboard[s.x][s.y] == 0) && (s.x <= 7) && (s.x >= 0) && (s.y <= 7)
	  && (s.y >= 0))
	  return (1);
   else
	  return (0);
}
Coordinate NextPos(Coordinate s, int i) //��һλ�� 
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
   Coordinate curpos = start; //����λ�� 
   InitStack(&S); //��ʼ��ջ 
   do
   {
	  if (Pass(curpos)) //����ǰλ�ÿ���
	  {
		 curstep++;  //�������� 
		 chessboard[curpos.x][curpos.y] = curstep; //���沽����� 
		 e.seat = curpos; //���浱ǰλ�� 
		 e.ord = curstep; //���� 
         e.di = 0; //���� 
		 Push(&S, e); //��ջ 
		 if (curstep == 64) //��������64����Ԫ��
		 {       
            break; //�˳�ѭ��
         }
		 else
		 {
             curpos = NextPos(curpos, e.di); //ȡ��һλ�� 
         }
	  }
	  else //����ǰλ�ò����� 
	  {
		 if (!StackEmpty(&S)) //��ջ��Ϊ�� 
		 {
			Pop(&S, e); //����һ����ջ 
			if (e.di == 7) //��8��λ�ö��߹�
            { 
                chessboard[e.seat.x][e.seat.y] = 0; //ȡ���ò��Ĳ������ 
            }
			while (e.di == 7 && !StackEmpty(&S)) //��ǰ8��λ�������꣬��ջ��Ϊ�� 
			{
			   e = Pop(&S, e); //��ջ 
			   if (e.di == 7) //��8��λ�ö���̽���� 
				  chessboard[e.seat.x][e.seat.y] = 0; //ȡ���ò��Ĳ������ 
			   curstep = e.ord; //���沽����� 
			}
			if (e.di < 7) //������λ��δ������̽ 
			{
               e.di++; //��̽��һλ��  
			   Push(&S, e); //��ջ 
			   curpos = NextPos(e.seat, e.di); //ȡ��һλ�� 
			}
		 }
	  }
   } while (!StackEmpty(&S)); //��ջ�л������ݣ�����ѭ�� 
   if (StackEmpty(&S)) //��ջΪ�� 
   {
	  printf("����ʧ��!\n");
	  printf("�밴������Ƴ�������\n");
	  getch();
	  exit(1);
   }
}
int main()
{
   int i,j;
   Coordinate start;
   printf("���������ʼλ������:");
   scanf("%d %d", &start.x, &start.y);
   if(start.x< 1  || start.y < 1 
       || start.x > 8 || start.y > 8) //���� 
   {
       printf("��������������������룡\n");
       exit(0);
   }
   start.x -= 1;
   start.y -= 1;   
   knight(start);
   printf("���·��:\n");
   for (i = 0; i < 8; i++)
   {
	  for (j = 0; j < 8; j++)
		 printf("%4d", chessboard[i][j]);
       printf("\n");
   }
   getch();
   return 0;
}
