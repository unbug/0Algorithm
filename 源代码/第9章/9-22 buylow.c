#include <stdio.h>
#include <limits.h>
#define MAXN 5000
int n, price[MAXN], flag[MAXN], cnt[MAXN];
int max(int x, int y)
{
   if (x > y)
	  return x;
   else
	  return y;
}
int main()
{
   int i, j, k, max1, last, total;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("buylow.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d", &n);
   for (i = 1; i <= n; i++)
	  fscanf(fp1, "%d", &price[i]);
   fclose(fp1);
   price[0] = INT_MAX;	//����0��Ԫ������Ϊһ���������ֵ 
   max1 = 1;	//�������������ʼֵΪ1 
   flag[1] = 1;
   for (i = 2; i <= n; i++)	//����ǰi������������ 
   {
	  flag[i] = 1;
	  for (j = 1; j < i; j++)
	  {
		 if (price[j] > price[i])
			flag[i] = max(flag[i], flag[j] + 1);	//״̬ת�Ʒ��� 
	  }
	  max1 = max(max1, flag[i]);	//ȡ���ֵ 
   }
   cnt[1] = 1;	//��ʼΪ1�� 
   for (i = 2; i <= n; i++)
   {
	  last = -1;
	  if (flag[i] == 1)	//����i��֮ǰ���������Ϊ 1 
	  {
		 cnt[i] = 1;	//����������Ϊ1 
		 continue;
	  }
	  for (j = i - 1; j >= 1; j--) //���flag��־�е�ֵ 
	  {
		 if (flag[j] + 1 == flag[i] && price[j] > price[i]
			&& price[j] != last)
		 {
			cnt[i] += cnt[j]; //���������� 
			last = price[j];
		 }
	  }
   }
   total = 0;	//��������0 
   last = -1;
   for (i = n; i >= 1; i--)	//�Ӻ���ǰ�ۼ������� 
   {
	  if (flag[i] == max1 && price[i] != last)
	  {
		 total += cnt[i]; 
		 last = price[i];
	  }
   }
   if ((fp2 = fopen("buylow.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d,%d\n", max1, total);	//������
   fprintf(fp2, "%d,%d\n", max1, total);
   fclose(fp2);
   getch();
   return 0;
}
