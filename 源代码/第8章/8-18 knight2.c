#include <stdio.h>
typedef struct coord
{
   int x;
   int y;
}Coordinate;	//�����ϵ����� 
int chessboard[8][8] = { 0 };	//��ʼ�����̸���Ԫ��״̬ 
int curstep;	//�����Ĳ������ 
Coordinate move[8] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
          {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};	//����ߵİ˸�����
void display() //��ʾ�߷�
{
   int i, j;
   for (i = 0; i < 8; i++)
   {
	  for (j = 0; j < 8; j++)
		 printf("%4d", chessboard[i][j]);
	  printf("\n");
   }
   getch();
}
void travel(Coordinate curpos) //��ǰ��һ��
{
   Coordinate next;
   int i;
   if (curpos.x < 0 || curpos.x > 7 || curpos.y < 0 || curpos.y > 7)	//Խ�� 
	  return;
   if (chessboard[curpos.x][curpos.y])	//�����߹� 
	  return;	//�Ƿ������
   chessboard[curpos.x][curpos.y] = curstep;	//���沽�� 
   curstep++;
   if (curstep > 64)	//64������λ�ö������� 
   {
      display();
	  printf("\n");
   } 
   else
   {
	  for (i = 0; i < 8; i++)	// 8�����ܵķ���
	  {
		 next.x = curpos.x + move[i].x;
		 next.y = curpos.y + move[i].y;
		 if (next.x < 0 || next.x > 7 || next.y < 0 || next.y > 7);
		 else
		     travel(next);
	  }
   }
   chessboard[curpos.x][curpos.y] = 0; //���������� 
   curstep--; //���ٲ��� 
}
int main()
{
   int i, j;
   Coordinate start;
   printf("���������ʼλ��:");
   scanf("%d%d", &start.x, &start.y);
   if (start.x < 1 || start.y < 1 || start.x > 8 || start.y > 8)	//Խ�� 
   {
	  printf("��������������������룡\n");
	  exit(0);
   }
   start.x--;
   start.y--;
   curstep = 1;	//��1�� 
   travel(start);
   getch();
   return 0;
}
