#include <stdio.h>
#define MAXN 500	//������̫����ɳ����ڴ治��
int main()
{
   int r, i, j;
   char d[MAXN][MAXN];
   int flag[MAXN][MAXN] = { 0 };
   FILE *fp1, *fp2;
   if ((fp1 = fopen("numtri.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &r); //�������� 
   for (i = 1; i <= r; i++) //���������е����� 
	  for (j = 1; j <= i; j++)
		 fscanf(fp1, "%d", &d[i][j]);
   fclose(fp1);
   for (i = r; i >= 1; i--) //����flag��־�е�ֵ 
   {
	  for (j = 1; j <= r; j++)
	  {
		 if (flag[i + 1][j] > flag[i + 1][j + 1])
			flag[i][j] = flag[i + 1][j] + d[i][j];
		 else
			flag[i][j] = flag[i + 1][j + 1] + d[i][j];
	  }
   }
   if ((fp2 = fopen("numtri.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", flag[1][1]); //������ 
   fprintf(fp2, "%d\n", flag[1][1]);
   getch();
   return 0;
}
