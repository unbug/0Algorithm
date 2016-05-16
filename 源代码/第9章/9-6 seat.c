#include <stdio.h>
#define MAXN 1001
void swap(int *a, int *b)	//�������� 
{
   int t;
   t = *a;
   *a = *b;
   *b = t;
}
int main()
{
   FILE *fp1, *fp2;
   int row[MAXN], col[MAXN], temp[MAXN];
   int m, n, k, l, d;	//m��n�У�k������ͨ����l������ͨ��,d��ͬѧ�Ͽ�˵�� 
   int x1, y1, x2, y2;	//�����໥˵��ͬѧ��λ�� 
   int i, j;
   if ((fp1 = fopen("seat.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d%d%d%d\n", &m, &n, &k, &l, &d);
   for (i = 1; i <= m; i++)	//���ò��������ͨ�� 
	  row[i] = 0;
   for (i = 1; i <= n; i++)	//���ò���������ͨ�� 
	  col[i] = 0;
   for (i = 0; i < d; i++)	//�����ļ���ÿ�е�����,ͳ����ÿ�С�ÿ�����ͨ�����Էָ��ѧ����
   {
	  fscanf(fp1, "%d%d%d%d", &y1, &x1, &y2, &x2);	//����Ҫ˵������������λ�� 
	  if (x1 == x2)	//����ͬһ��
	  {
		 if (y1 > y2)
			swap(&y1, &y2);	//�����кţ�ʹ���к�����ǰ�� 
		 row[y1]++;	//��y1λ������һ������ͨ���ָ�ͬһ�е�ͬѧ 
	  } else if (y1 == y2)	//��ͬһ�� 
	  {
		 if (x1 > x2)
			swap(&x1, &x2);	//�����кţ�ʹ���к�����ǰ�� 
		 col[x1]++;	//��x1λ������һ������ͨ���ָ�ͬһ�е�ͬѧ 
	  }
   }
   fclose(fp1);	//�ر��ļ� 
   for (i = 0; i <= m; i++)	//temp�б����к�,׼������ 
	  temp[i] = i;
   for (i = 1; i < m; i++)	//�Ժ���ͨ���ָ�˵��ѧ�������������� 
	  for (j = i + 1; j <= m; j++)
		 if (row[i] < row[j])	//��i����ͨ���ָ�˵��ѧ�����ڵ�j�� 
		 {
			swap(&row[i], &row[j]);	//����ͨ��λ�� 
			swap(&temp[i], &temp[j]);	//�����к� 
		 }
   for (i = 1; i < k; i++)	//��ǰk������ͨ���������� 
	  for (j = i + 1; j <= k; j++)
		 if (temp[i] > temp[j])	//ʹ���к�����ǰ�� 
			swap(&temp[i], &temp[j]);
   if ((fp2 = fopen("seat.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   for (i = 1; i <= k; i++)	//�������ͨ��λ�� 
   {
	  printf(" %d", temp[i]);
	  fprintf(fp2, " %d", temp[i]);
   }
   printf("\n");
   fprintf(fp2, "\n");
   for (i = 0; i <= n; i++)	//���кű��浽temp�����У�׼������
	  temp[i] = i;
   for (i = 1; i < n; i++)	//������ͨ���ָ�˵��ѧ��������������
	  for (j = i + 1; j <= n; j++)
		 if (col[i] < col[j])
		 {
			swap(&col[i], &col[j]);	//����ͨ��λ�� 
			swap(&temp[i], &temp[j]);	//�����к� 
		 }
   for (i = 1; i < l; i++)	//��ǰL������ͨ���������� 
	  for (j = i + 1; j <= l; j++)
		 if (temp[i] > temp[j])	//ʹ���к�����ǰ�� 
			swap(&temp[i], &temp[j]);
   for (i = 1; i <= l; i++)	//�������ͨ�� 
   {
	  printf(" %d", temp[i]);
	  fprintf(fp2, " %d", temp[i]);
   }
   fprintf(fp2, "\n");
   fclose(fp2);
   getch();
   return 0;
}
