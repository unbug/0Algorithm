#include <stdio.h>
int main()
{
   FILE *fp1, *fp2;
   int s[31][31] = { 0 };
   int i, j, k, m, n;
   if ((fp1 = fopen("ball.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   s[0][0] = 1; //����������Ϊ0�������� 
   fscanf(fp1, "%d%d", &n, &m); //���ļ��ж�ȡ��Ϸ�����ʹ������ 
   fclose(fp1);//�ر��ļ� 
   for (i = 1; i <= m; i++) //ѭ������m�� 
   {
	  s[i][0] = s[i - 1][n - 1] + s[i - 1][1]; //��1���˵�������
	  for (j = 1; j < n - 1; j++) //ѭ����������Ҵ� 
		 s[i][j] = s[i - 1][j - 1] + s[i - 1][j + 1];
	  s[i][n - 1] = s[i - 1][n - 2] + s[i - 1][0]; //ĩ1���˵�������
   }
   if ((fp2 = fopen("ball.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n",s[m][0]);
   fprintf(fp2, "%d\n", s[m][0]);//�����0���˵�m�δ���ķ����� 
   fclose(fp2);
   getch();
   return 0;
}
