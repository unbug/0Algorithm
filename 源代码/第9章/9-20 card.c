#include <stdio.h>
#define MAXN 100
int main()
{
   int i, j, n, total = 0, sum, ave, num[MAXN];
   FILE *fp1, *fp2;
   if ((fp1 = fopen("card.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);	//�����ƶ��� 
   sum = 0;
   for (i = 0; i < n; i++)	//����ÿ���Ƶ����� 
   {
	  fscanf(fp1, "%d", &num[i]);
	  sum += num[i];	//���� 
   }
   fclose(fp1);	//�ر��ļ� 
   ave = sum / n;	//����ƽ��ֵ 
   for (i = 0; i < n; i++)	//����ÿ������ƽ��ֵ�Ĳ� 
	  num[i] -= ave;
   i = 0;
   j = n - 1;
   while (num[i] == 0)	//������ߵ�0 
	  i++;
   while (num[j] == 0)	//�����ұߵ�0 
	  j--;
   while (i < j)
   {
	  num[i + 1] += num[i];	//����ߵ����Ƶ��ұ�
	  num[i] = 0;	//ʹ��ߵ�������ƽ��ֵ��� 
	  total++;	//����һ���ƶ�����
	  i++;	//׼���ƶ���һ����
	  while (num[i] == 0)	//�����Ҳ���Ϊ0���ƶ� 
		 i++;
   }
   if ((fp2 = fopen("card.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", total);	//�����Ҫ�ƶ��Ĳ��� 
   fprintf(fp2, "%d\n", total);
   fclose(fp2);
   getch();
   return 0;
}
