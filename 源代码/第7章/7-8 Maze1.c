#include  <stdio.h>
#define MAXLEN 30	// �Թ�������ǽ���������Ŀ
#define INIT_SIZE 100	// �洢�ռ��ʼ������
typedef struct
{
   int row; //�Թ������� 
   int column; //�Թ������� 
   char grid[MAXLEN][MAXLEN];	//1��ʾ�ϰ�,0��ʾ��,2��ʾ��ͨ��3��ʾ���߹�����ͨ
}MazeType;						// �Թ����� 
typedef struct					// �Թ��е����� 
{
   int row;//�к� 
   int column; //�к� 
}Coordinate;
typedef struct
{
   int ord;						// ��ǰλ����·���ϵ����
   Coordinate seat;				// ��ǰ���� 
   int di;						// ����һ����ķ��� 
}MazeNode;						// ջԪ������ 
typedef struct
{
   MazeNode base[INIT_SIZE]; //�Թ��ڵ���Ϣ
   int top; //ջ��ָ�� 
}Stack;							// ջ���� 
int InitStack(Stack *S) // �����ջs
{
   S->top = -1;
   return 1;
}
int StackEmpty(Stack *s)		// ��sΪ�շ���TRUE,���򷵻�FALSE 
{
   if (s->top == -1)
	  return 1;   
   return 0;
}
int StackIsFull(Stack *s) //�ж�ջ�Ƿ�Ϊ��
{
   if (s->top == INIT_SIZE - 1)
	  return 1;
   else
	  return 0;
}
int Push(Stack *s, MazeNode mn)	// ����Ԫ��eΪ�µ�ջ��Ԫ�� 
{
   if (!StackIsFull(s)) //��ջδ�� 
   {
	  s->top++; //�޸�ջ��ָ�� 
	  s->base[s->top] = mn; //���ڵ���Ϣ��ջ 
   }
}
int Pop(Stack *s, MazeNode *mn)	// ��ջ����ɾ��ջ//��Ԫ����e���ز�����OK�����򷵻�ERROR 
{
   if (s->top != -1) //ջ��Ϊ�� 
   {
	  *mn = s->base[s->top];
	  s->top--;
	  return 1;
   }
   return 0;
}
int DestroyStack(Stack *s)	//����ջS 
{
   s->top=-1;
   return 1;
}
int MazeInit(MazeType *maze) // ��ʼ���Թ�
{
   int m, n, i, j;
   printf("�����Թ�������������:");
   scanf("%d%d", &maze->row, &maze->column);	// �Թ��к����� 
   for (i = 0; i <= maze->column + 1; i++)// �Թ�����ǽ 
   {	
	  maze->grid[0][i] = '1'; //����Ϊ�ϰ�ǽ 
	  maze->grid[maze->row + 1][i] = '1';
   }
   for (i = 0; i <= maze->row + 1; i++)// �Թ�����ǽ 
   {	
	  maze->grid[i][0] = '1';//����Ϊ�ϰ�ǽ 
      maze->grid[i][maze->column + 1] = '1';
   }
   for (i = 1; i <= maze->row; i++)	// ��ʼ���Թ� 
	  for (j = 1; j <= maze->column; j++)
		 maze->grid[i][j] = '0'; //����Ϊ��ͨ�� 
   printf("�����ϰ�ǽ������(��������(0,0)����): ");								// 
   while(1)
   {
       scanf("%d%d", &m, &n);	// �����ϰ������� 
       if(m==0) //����0 
           break; //������������� 
       if (m<=0 || n<=0 || m > maze->row || n > maze->column) //Խ�� 
       {
           printf("����Խ�磬��������!\n");
           continue; 
       }
       maze->grid[m][n] = '1';	// �Թ��ϰ���'1'���
   }
   return 1;
}
int Pass(MazeType *maze, Coordinate pos)	//�ж�ָ�������Ƿ��ͨ�� 
{
   if (maze->grid[pos.row][pos.column] == '0')	// ��ͨ 
	  return 1;
   else
	  return 0;
}
int MarkerPass(MazeType *maze, Coordinate pos)	//��ǿ�ͨ�� 
{
   maze->grid[pos.row][pos.column] = '2';	//"2"��ʾ��ͨ 
   return 1;
}
Coordinate NextCoord(Coordinate pos, int i)	//��ȡ��һλ�� 
{
   switch(i)	// 1.2.3.4�ֱ��ʾ��,��,��,������ 
   {
   case 1:
	  pos.column += 1; //���Ҳ���� 
	  break;
   case 2: //���·����� 
	  pos.row += 1;
	  break;
   case 3: //�������� 
	  pos.column -= 1;
	  break;
   case 4: //���Ϸ����� 
	  pos.row -= 1;
	  break;
   default:
	  exit(0);
   }
   return pos;
}
int MarkerNoPass(MazeType *maze, Coordinate pos)	// ���߹�������ͨ·��ǲ�����OK 
{
   maze->grid[pos.row][pos.column] ='3';	// "3"��ʾ���߹�����ͨ 
   return 1;
} 
int MazePath(MazeType *maze, Coordinate start, Coordinate end)//���Թ�maze����ڵ����ڲ���·��
{
   Stack S; //����ջ 
   Coordinate pos;
   int curstep;	// ��ǰ���,1.2.3.4�ֱ��ʾ��,��,��,������ 
   MazeNode e;
   InitStack(&S); //��ʼ��ջ 
   pos = start;	//�����λ�ÿ�ʼ����·�� 
   curstep = 1;	// ̽����һ�� 
   do
   {
	  if (Pass(maze, pos))	//��ָ��λ�ÿ�ͨ��
	  {
		 MarkerPass(maze, pos);	//�����ͨ�� 
		 e.ord = curstep; //���沽�� 
		 e.seat = pos; //���浱ǰ���� 
		 e.di = 1; //���Ҳ�ز� 
		 Push(&S, e);	//���ڵ���ӵ�ջ��(����·��)
		 if (pos.row == end.row && pos.column == end.column) //����ǰλ���ǳ������� 
		 {
			DestroyStack(&S); //�ͷ�ջռ�õĿռ� 
		    return 1;//���ز��ҳɹ� 
		 }
         else //��������겻ͬ 
		 {
			pos = NextCoord(pos, 1);//���Ҳ�̽�� 
			curstep++;	//����ǰ������ 
		 }
	  }
	  else	//��ָ��λ�ò�ͨ(Ϊ�ϰ�ǽ�����߹�)
	  {
		 if (!StackEmpty(&S))//��ջ��Ϊ��(֮ǰ���߹���λ��) 
		 {
			Pop(&S, &e); //��ջ(������һ����λ��) 
			while (e.di == 4 && !StackEmpty(&S)) //��һ��4������̽����,��ջ��Ϊ�� 
			{
			   MarkerNoPass(maze, e.seat); //��Ǹ�λ�ò�Ϊͨ 
			   Pop(&S, &e);//��ջ(������һ��) 
			}
			if (e.di < 4) //��δ̽����4������ 
			{
			   e.di++;	//׼��̽����һ������ 
			   Push(&S, e);//����ǰ�ڵ���ջ(���浱ǰλ�ã�׼����һλ�õ�̽��) 
			   pos = NextCoord(e.seat, e.di);	//������һ��Ӧ��̽��λ�õ����� 
			}
		 }
	  }
   }while (!StackEmpty(&S));
   //�������е������ʾû����ͨ���·�� 
   DestroyStack(&S); //�ͷ�ջռ�õĿռ� 
   return 0; //����ʧ�� 
}
void PrintMaze(MazeType *maze)//����Թ� 
{
   int i, j;
   printf("\n�Թ�·��(���ʾͨ·):\n");
   for (i = 0; i <= maze->row + 1; i++)
   {
	  for (j = 0; j <= maze->column + 1; j++)
	  {
         if ( maze->grid[i][j] == '1') //�����ϰ�ǽ 
            printf("��");
         else if ( maze->grid[i][j] == '2') //���ǿ�ͨ·�� 
            printf("��");
         else //����λ�� 
            printf("  ");
      }
	  printf("\n");
   }
}
int main()
{ 
    MazeType maze; //�Թ����� 
    Coordinate start, end;
    char cmd;
    printf("�����Թ�\n");
    if (!MazeInit(&maze))// ��ʼ���������Թ� 
    {
        printf("\n�����Թ��ṹʱ����!\n");
        exit(-1);	// ��ʼ������ 
    }
    do	// �����Թ�������� 
    {
        printf("\n�����Թ��������:");
        scanf("%d%d", &start.row, &start.column);
        if (start.row > maze.row || start.column > maze.column)
        {
            printf("\n���������Խ�磬��������!\n");
            continue;
        }
    }while (start.row > maze.row || start.column > maze.column);
    do// �����Թ��������� 
    {
        printf("\n�����Թ���������:");
        scanf("%d%d", &end.row, &end.column);
        if (end.row > maze.row || end.column > maze.column)
        {
            printf("\n���������Խ�磬��������!\n");
            continue;
        }
    }while (end.row > maze.row || end.column > maze.column);
    if (!MazePath(&maze, start, end))	//���ú�������·�� 
        printf("\nû��·��������ڵ������!\n");
    else
        PrintMaze(&maze);	// ��ӡ�ҵ���·�� 
    getch();
    return 0;
}
