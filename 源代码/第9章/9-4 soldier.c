#include <stdio.h>
#define MAXN 21
int chessboard[MAXN][MAXN] = { 0 };
int n, m, x, y;	//n,mΪB�����������λ��,x,yΪ�������λ�� 
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void horse() //��ʼ���������Ƶ�����λ�� 
{
   int i;
   chessboard[x][y] = -1;	//������λ�� 
   for (i = 0; i < 8; i++)	//�������һ����λ�� 
   {
	  if ((x + dx[i] >= 0 && x + dx[x] <= n) && (y + dy[i] >= 0)
		 && (y + dy[i]) <= m)
		 chessboard[x + dx[i]][y + dy[i]] = -1;
   }
}
void search() //����Ѱ��·
{
   int i, j;
   for (i = 0; i <= n; i++)	//ɨ���0�еĸ���
   {
	  if (chessboard[i][0] != -1)	//��û���ϰ� 
		 chessboard[i][0] = 1;	//���ø�λ�ÿ���·����Ϊ1 
	  else
		 break;
   }
   for (i = 0; i <= m; i++)	//ɨ���0�е�ÿ�� 
   {
	  if (chessboard[0][i] != -1)	//��������Ŀ��Ƶ� 
		 chessboard[0][i] = 1;	//���ø�λ�ÿ���·����Ϊ1 
	  else
		 break;
   }
   for (i = 1; i <= n; i++)	//ɨ����и��� 
   {
	  for (j = 1; j <= m; j++)
	  {
		 if (chessboard[i][j] != -1)	//����λ�ò�����Ŀ��Ƶ� 
		 {
			if ((chessboard[i - 1][j] != -1) && (chessboard[i][j - 1] != -1))	//��������Ҳ������Ŀ��Ƶ�
			   chessboard[i][j] = chessboard[i - 1][j] + chessboard[i][j - 1];	//���������ߵ�·�������ۼ� 
			if ((chessboard[i - 1][j] == -1) && (chessboard[i][j - 1] != -1))	//������������Ƶ�,�����������Ƶ� 
			   chessboard[i][j] = chessboard[i][j - 1];	//�������·��������ǰλ�� 
			if ((chessboard[i - 1][j] != -1) && (chessboard[i][j - 1] == -1))	//������������Ƶ�,�����������Ƶ� 
			   chessboard[i][j] = chessboard[i - 1][j];	//��������·������ǰλ�� 
			if ((chessboard[i - 1][j] == -1) && (chessboard[i][j - 1] == -1))	//���������߶�����Ŀ��Ƶ� 
			   chessboard[i][j] = 0;	//��ǰλ����ͨ· 
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
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1,"%d%d%d%d", &n, &m, &x, &y);
   fclose(fp1);
   horse();	//��ʼ��������һ����λ�� 
   search();
   if ((fp2 = fopen("soldier.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", chessboard[n][m]);
   fprintf(fp2,"%d\n",chessboard[n][m]);
   fclose(fp2);
   getch();
   return 0;
}
