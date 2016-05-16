#include <stdio.h>
void Output(char chessboard[][8]);	//��ʾ���������ӵ���� 
int Check(char chessboard[][8], int moves[][8], char player);	//���һ���Ƿ��еط������� 
void PlayStep(char chessboard[][8], int row, int col, char player);	//��ָ��λ������ 
void AutoPlayStep(char chessboard[][8], int moves[][8], char player);	//�������˼������ 
int GetMaxScore(char chessboard[][8], char player);	//��ȡ���� 
int BestPlay(char chessboard[][8], int moves[][8], char player);	//�������� 
int main()
{
   char chessboard[8][8];	//���������и���Ԫ�����ӵ�״̬ 
   int isDown[8][8] = { 0 };	//���������и�λ���Ƿ�������ӣ������ӵ�λ��Ϊ1������λ��Ϊ0 
   int row, col, x, y;
   int iCount = 0;	//������������ 
   int player = 0;	//���巽
   int SkipPlay = 0;	//�������ӵĴ�������Ϊ2����ʾ˫������������ 
   int Score[2];	//������������Ϸ�ߵĵ÷� 
   char select;
   printf("�ڰ���\n\n");
   printf("��Ϸ��ִ�����£������ִ�ף���Enter��ʼ:\n");
   scanf("%c", &select);
   do
   {
	  if (player == 0)	//�������巽(0��ʾ��Ϸ��,1��ʾ�����) 
		 player = 1;
	  else
		 player = 0;
	  iCount = 4;	//�ۼ������� 
	  for (row = 0; row < 8; row++)	//���̸�λ����� 
		 for (col = 0; col < 8; col++)
			chessboard[row][col] = 0;
	  chessboard[3][3] = chessboard[4][4] = 1;	//�������м�λ�÷��ð��� 
	  chessboard[3][4] = chessboard[4][3] = -1;	//�������м�λ�÷��ú��� 
	  printf("\n���̳�ʼ״̬:\n");
	  Output(chessboard);	//��ʾ��ʼ�������ӵ�״�� 
	  do
	  {
		 if (player == 1)	//������Ϸ������(�°���) 
		 {
			player = 0;
			if (Check(chessboard, isDown, 2))	//�ж��Ƿ���º��� 
			{
			   while(1)	//��ѭ����ֱ���û�������ȷ������Ϊֹ 
			   {
				  fflush(stdin);
				  printf("�������ӵ�λ��(�� ��):");
				  scanf("%d%c", &x, &y);
				  x--;	//����������λ�� 
				  if(y >= 'a')
                      y = y - 'a' + 1;
                  else
                      y = y - 'A' + 1;
				  y--;	//������λ�� 
				  if (x >= 0 && y >= 0 && x < 8 && y < 8 && isDown[x][y])	//����������������Ч 
				  {
					 PlayStep(chessboard, x, y, 2);	//��ָ������λ���º��� 
					 iCount++;	//�ۼ������� 
					 break;
				  }
                  else
					 printf("��������������������롣\n");
			   }
			   printf("\n�����Ӻ��״̬:\n");
			   Output(chessboard);	//��ʾ����״̬
			   printf("���������������ӡ�\n");
			   getch();
			}
            else if (++SkipPlay < 2)	//����Ч���ӵĴ���С��2 
			{
			   fflush(stdin);	//������뻺���� 
			   printf("��ûλ�ÿ��£���Enter���öԷ����ӡ�");
			   scanf("%c", &select);
			} else
			   printf("˫����û�ط����ӣ���Ϸ����!\n");
		 }
         else	//���Ǽ��������(�º���) 
		 {
			player = 1;
			if (Check(chessboard, isDown, 1))	//����Ƿ���°��� 
			{
			   SkipPlay = 0;	//�����Ч���Ӵ��� 
			   AutoPlayStep(chessboard, isDown, 1);	//�������һ������ 
			   iCount++;	//�ۼ�������
			   printf("\n��������Ӻ��״̬:\n");
			   Output(chessboard);	//��ʾ����״̬
			}
            else
			{
			   if (++SkipPlay < 2)	//����Ч���Ӵ���С��2 
				  printf("��ûλ�ÿ��ߣ������ߡ�\n");
			   else
				  printf("˫����û�ط����ӣ���Ϸ����!");
			}
		 }
	  }while (iCount < 64 && SkipPlay < 2);	//��������С��64 ����Ч���ӵĴ���С��2 
	  Output(chessboard);	//��ʾ��˫�����ӵ�״�� 
	  Score[0] = Score[1] = 0;	//��ռƷֱ��� 
	  for (row = 0; row < 8; row++)	//ѭ��ͳ�Ƹ���Ԫ��ڰ����ӵ�����
	  {
		 for (col = 0; col < 8; col++)
		 {
			Score[0] += chessboard[row][col] == -1;	//ͳ�ƺ����� 
			Score[1] += chessboard[row][col] == 1;	//ͳ�ư�����             
		 }
	  }
	  printf("���ճɼ�:\n");
	  printf("�����:%d\n��Ϸ��:%d\n", Score[0], Score[1]);
	  fflush(stdin);	//������뻺���� 
	  printf("������һ��(y/n)��:");
	  scanf("%c", &select);
   }while (select == 'y' || select == 'Y');
   printf("Game Over!\n");
   getch();
   return 0;
}
void Output(char chessboard[][8])	//��ʾ���������ӵ�״̬ 
{
   int row, col;
   printf("\n   ");
   for (col = 0; col < 8; col++)	//����б�� 
	  printf("  %c ", 'A' + col);
   printf("\n");
   printf("  ��");	//�������� 
   for (col = 0; col < 7; col++)	//���һ�� 
	  printf("����");
   printf("����\n");
   for (row = 0; row < 8; row++)
   {
	  printf("%2d��", row + 1);	//����к�
	  for (col = 0; col < 8; col++)	//������̸���Ԫ�������ӵ�״̬ 
	  {
		 if (chessboard[row][col] == 1)	//���� 
			printf("��");
		 else if (chessboard[row][col] == -1)	//���� 
			printf("��");
		 else	//δ���Ӵ� 
			printf("  ��");
	  }
	  printf("\n");
	  if (row < 8 - 1)
	  {
		 printf("  ��");	//��������� 
		 for (col = 0; col < 8 - 1; col++)	//���һ�� 
			printf("����");
		 printf("����\n");
	  }
   }
   printf("  ��");
   for (col = 0; col < 8 - 1; col++)	//���һ�еĺ��� 
	  printf("����");
   printf("����\n");
}
int Check(char chessboard[][8], int isDown[][8], char player)	//���ĳһ���Ƿ������ӵĵط�
{
   int rowdelta, coldelta, row, col, x, y = 0;
   int iStep = 0;
   char opponent = (player == 1) ? -1 : 1;	//�Է����� 
   char myplayer = -1 * opponent;	//�ҷ����� 
   for (row = 0; row < 8; row++)	//��isDown����ȫ����0 
	  for (col = 0; col < 8; col++)
		 isDown[row][col] = 0;
   for (row = 0; row < 8; row++)	//ѭ���ж���������Щ��Ԫ��������� 
   {
	  for (col = 0; col < 8; col++)
	  {
		 if (chessboard[row][col] != 0)	//�������϶�Ӧλ�ò�Ϊ��(��ʾ�Ѿ�����) 
			continue;	//����������һ����Ԫ�� 
		 for (rowdelta = -1; rowdelta <= 1; rowdelta++)	//ѭ����������� 
		 {
			for (coldelta = -1; coldelta <= 1; coldelta++)	//ѭ����������� 
			{
			   if (row + rowdelta < 0 || row + rowdelta >= 8
				  || col + coldelta < 0 || col + coldelta >= 8
				  || (rowdelta == 0 && coldelta == 0))	//��������곬������ ��Ϊ��ǰ��Ԫ�� 
				  continue;	//����ѭ�� 
			   if (chessboard[row + rowdelta][col + coldelta] == opponent)	//��(row,col)�����ж����µ��� 
			   {
				  x = row + rowdelta;	//�Զ�������λ��Ϊ���� 
				  y = col + coldelta;

				  while(1)	//�Զ�������Ϊ��ʼ�㣬�����ܲ����Լ��������ӣ��Թ����Է����� 
				  {
					 x += rowdelta;	//�������ӵ��������� 
					 y += coldelta;

					 if (x < 0 || x >= 8 || y < 0 || y >= 8)	//�������� 
						break;	//�˳�ѭ�� 

					 if (chessboard[x][y] == 0)	//����Ӧλ��Ϊ�� 
						break;
					 if (chessboard[x][y] == myplayer)	//����Ӧλ���µ����ǵ�ǰ���ֵ� 
					 {
						isDown[row][col] = 1;	//�����ƶ������ж�Ӧλ��Ϊ1 (��λ�ÿ����ӣ��γ�����ֽ���������)
						iStep++;	//�ۼӿ����ӵ�λ������ 
						break;
					 }
				  }
			   }
			}
		 }
	  }
   }
   return iStep;	//���ؿ��µ�λ��������������ֵΪ0����ʾû�ط����£� 
}
void PlayStep(char chessboard[][8], int row, int col, char player)	//��ָ��λ������ 
{
   int rowdelta = 0;
   int coldelta = 0;
   int x = 0;
   int y = 0;
   char opponent = (player == 1) ? -1 : 1;	//�Է�����
   char myplayer = -1 * opponent;	//�ҷ����� 
   chessboard[row][col] = myplayer;	//�������µ�����
   for (rowdelta = -1; rowdelta <= 1; rowdelta++)	//������������ܵ�����
   {
	  for (coldelta = -1; coldelta <= 1; coldelta++)
	  {
		 if (row + rowdelta < 0 || row + rowdelta >= 8 || col + coldelta < 0
			|| col + coldelta >= 8 || (rowdelta == 0 && coldelta == 0))	//�����곬�����̽��� 
			continue;	//������һλ�� 
		 if (chessboard[row + rowdelta][col + coldelta] == opponent)	//����λ���Ƕ��ֵ����� 
		 {
			x = row + rowdelta;	//�Զ�����Ϊ���� 
			y = col + coldelta;
			while(1)	//�ڶ�����������Ѱ���ҷ����� 
			{
			   x += rowdelta;
			   y += coldelta;
			   if (x < 0 || x >= 8 || y < 0 || y >= 8)	//�����곬������ 
				  break;	//�˳�ѭ�� 
			   if (chessboard[x][y] == 0)	//����Ӧλ��Ϊ�� 
				  break;	//�˳�ѭ�� 
			   if (chessboard[x][y] == myplayer)	//����Ӧλ�����ҷ�ģ�� 
			   {
				  while (chessboard[x -= rowdelta][y -= coldelta] == opponent)	//ѭ������ 
					 chessboard[x][y] = myplayer;	//���м�����Ӷ�����ҷ����� 
				  break;	//�˳�ѭ�� 
			   }
			}
		 }
	  }
   }
}
int GetMaxScore(char chessboard[][8], char player)	//��ȡ���� 
{
   int Score, row, col;
   char opponent = (player == 1) ? -1 : 1;	//�Է����� 
   char myplayer=-1*opponent;
   for (row = 0; row < 8; row++)	//ѭ�� 
   {
	  for (col = 0; col < 8; col++)
	  {
		 Score -= chessboard[row][col] == opponent;	//�����̶�Ӧλ���Ƕ����µ����ӣ����ܷ��м�1 
		 Score += chessboard[row][col] == myplayer;	//�����̶�Ӧλ�����ҷ������ӣ��ܷ��м�1�� 
	  }
   }
   return Score;	//���ط��� 
}
int BestPlay(char chessboard[][8], int isDown[][8], char player)	//��ȡ�������λ�� 
{
   int row, col, i, j;
   char chessboard1[8][8] = { 0 };	//����һ����ʱ���� 
   int MaxScore = 0;	//������߷� 
   int Score = 0;
   char opponent = (player == 1) ? -1 : 1;	//�����µ����� 
   for (row = 0; row < 8; row++)	//ѭ�����ÿ����Ԫ�� 
   {
	  for (col = 0; col < 8; col++)
	  {
		 if (!isDown[row][col])	//����λ�ò������� 
			continue;	//���� 
		 for (i = 0; i < 8; i++)	//�������̸���Ԫ�����ӵ�״̬����ʱ���� 
			for (j = 0; j < 8; j++)
			   chessboard1[i][j] = chessboard[i][j];
		 PlayStep(chessboard1, row, col, player);	//����ʱ�����е�ָ���������� 
		 Score = GetMaxScore(chessboard1, player);	//��ȡ���Ӻ�ɵõ��ķ���
		 if (MaxScore < Score)	//��ԭ�����õ��ķ���С�ڱ������ӵķ��� 
			MaxScore = Score;	//������߷� 
	  }
   }
   return MaxScore;	//���صõ�����߷� 
}
void AutoPlayStep(char chessboard[][8], int isDown[][8], char player)	//������Զ����� 
{
   int row, col, row1, col1, i, j;
   int Score = 0, MinScore = 100;	//�Է��������ᵽ�ķ�������С���� 
   char chessboard1[8][8];	//��ʱ���飬������������λ�� 
   int isDown1[8][8];	//��ʱ���飬���������λ�� 
   char opponent = (player == 1) ? -1 : 1;	//�����µ�����    
   for (row = 0; row < 8; row++)	//ѭ���������ÿ����Ԫ�� 
   {
	  for (col = 0; col < 8; col++)
	  {
		 if (isDown[row][col] == 0)	//���������� 
			continue;	//������һ��λ�� 
		 for (i = 0; i < 8; i++)	//������ԭ�������Ӹ��Ƶ���ʱ������ 
			for (j = 0; j < 8; j++)
			   chessboard1[i][j] = chessboard[i][j];
		 PlayStep(chessboard1, row, col, player);	//��������ʱ�����е�һ��λ������ 
		 Check(chessboard1, isDown1, opponent);	//�������Ƿ��еط������� 
		 Score = BestPlay(chessboard1, isDown1, opponent);	//�����ʱ�����жԷ����ӵĵ÷���� 
		 if (Score < MinScore)	//����Է��÷���͵��·� 
		 {
			MinScore = Score;
			row1 = row;
			col1 = col;
		 }
	  }
   }
   PlayStep(chessboard, row1, col1, player);	//������������·����� 
}
