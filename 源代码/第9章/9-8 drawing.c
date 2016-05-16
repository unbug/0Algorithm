#include <stdio.h>
#define MAXN 51
char canvas[500][500]; //��������ͼ�Ļ��� 
void draw(int x, int y)	//x,yΪ���꣬���������� 
{
   canvas[y][x] = '+';	//���½� 
   canvas[y][x + 1] = '-';	//�º��� 
   canvas[y][x + 2] = '-';
   canvas[y][x + 3] = '-';
   canvas[y][x + 4] = '+';	//���½� 
   canvas[y + 1][x] = '|';	//�������ĵ�2�У������� 
   canvas[y + 1][x + 1] = ' ';	//3���ո� 
   canvas[y + 1][x + 2] = ' ';
   canvas[y + 1][x + 3] = ' ';
   canvas[y + 1][x + 4] = '|';
   canvas[y + 1][x + 5] = '/';	//��б�� 
   canvas[y + 2][x] = '|';	//�������ĵ�3��,������ 
   canvas[y + 2][x + 1] = ' ';	//3���ո� 
   canvas[y + 2][x + 2] = ' ';
   canvas[y + 2][x + 3] = ' ';
   canvas[y + 2][x + 4] = '|';
   canvas[y + 2][x + 5] = ' ';	//�ո� 
   canvas[y + 2][x + 6] = '+';	//����ת�ļӺ� 
   canvas[y + 3][x] = '+';	//�������ĵ�4��,��Ӻ� 
   canvas[y + 3][x + 1] = '-';	//3������ 
   canvas[y + 3][x + 2] = '-';
   canvas[y + 3][x + 3] = '-';
   canvas[y + 3][x + 4] = '+';	//ת�ǼӺ� 
   canvas[y + 3][x + 5] = ' ';	//�� 
   canvas[y + 3][x + 6] = '|';	//���� 
   canvas[y + 4][x + 1] = '/';	//�������ĵ�5�У���б�� 
   canvas[y + 4][x + 2] = ' ';	//3���ո� 
   canvas[y + 4][x + 3] = ' ';
   canvas[y + 4][x + 4] = ' ';
   canvas[y + 4][x + 5] = '/';	//б�� 
   canvas[y + 4][x + 6] = '|';	//���� 
   canvas[y + 5][x + 2] = '+';	//�������ĵ�6��,��ת�ǼӺ� 
   canvas[y + 5][x + 3] = '-';	//���� 
   canvas[y + 5][x + 4] = '-';
   canvas[y + 5][x + 5] = '-';
   canvas[y + 5][x + 6] = '+';
}
int main()
{
   FILE *fp1, *fp2;
   int a[MAXN][MAXN];
   int width, height, t, x, y;
   int i, j, k, m, n;
   if ((fp1 = fopen("drawing.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d", &m, &n); //���ļ��ж������� 
   width = 4 * n + 2 * m + 1; //���㻭����� 
   height = 0; //���û����߶ȳ�ʼֵΪ0 
   for (i = 0; i < m; i++) 
   {
	  for (j = 0; j < n; j++)
	  {
		 fscanf(fp1, "%d", &a[i][j]); //���ļ��л�ȡ��������
		 t = 3 * a[i][j] + 2 * (m - i) + 1; //����߶� 
		 if (t > height) //���滭�����ֵ 
			height = t;
	  }
   }
   fclose(fp1); //�ر��ļ� 
   for (i = 0; i < height; i++) //��ջ��������ñ���Ϊ�� 
	  for (j = 0; j < width; j++)
		 canvas[i][j] = '.';
   for (i = 0; i < m; i++) //��ȷ���m�������� 
   {
	  for (j = 0; j < n; j++) //���ȷ���n�������� 
	  {
		 for (k = 0; k < a[i][j]; k++) //�߶ȷ��� 
		 {
			x = 2 * (m - i - 1) + 4 * j; //����������������� 
			y = 2 * (m - i - 1) + 3 * k; //������������������ 
			draw(x, y); //��(x,y)����λ�û���һ�������� 
		 }
      }
   }
   if ((fp2 = fopen("drawing.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   for (i = height - 1; i >= 0; i--) //������ͼ��������ļ� 
   {
	  for (j = 0; j < width; j++)
		 fprintf(fp2, "%c", canvas[i][j]);
	  fprintf(fp2, "\n");
   }
   for (i = height - 1; i >= 0; i--) //������ͼ���������Ļ 
   {
	  for (j = 0; j < width; j++)
		 printf("%c", canvas[i][j]);
	  printf("\n");
   }
   getch();
   return 0;
}
