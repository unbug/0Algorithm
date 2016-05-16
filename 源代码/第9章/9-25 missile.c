#include <stdio.h>
#include <limits.h>
#define MAXN 1000
int height[MAXN], flag[MAXN] = { 0 };
int n, max, min;

int main()
{
   int i, j;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("missile.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);
   for (i = 1; i <= n; i++)
	  fscanf(fp1, "%d", &height[i]);
   fclose(fp1);
   height[0] = INT_MAX; //��0��Ԫ������Ϊһ�����ֵ 
   for (i = 1; i <= n; i++)
   {
	  for (j = i - 1; j >= 0; j--)	//��1~i�������пɻ����ض��ٸ� 
	  {
		 if (height[j] >= height[i] && (flag[j] + 1 > flag[i]))
			flag[i] = flag[j] + 1;
	  }
   }
   max = 0;
   for (i = 1; i <= n; i++) //�����ֵ���浽max������ 
   {
	  if (flag[i] > max)
		 max = flag[i];
   }
   for (i = 0; i < MAXN; i++) //����flag��־���� 
	  flag[i] = 0;
   height[0] = 0; //��0��Ԫ������Ϊһ����Сֵ 
   for (i = 1; i <= n; i++)
   {
	  for (j = i - 1; j >= 0; j--) //�ж�1~i��������Ҫ��ϵͳ�� 
	  {
		 if (height[j] < height[i] && (flag[j] + 1 > flag[i]))
			flag[i] = flag[j] + 1;
	  }
   }
   min = 0;
   for (i = 1; i <= n; i++)	//������С���� 
   {
	  if (flag[i] > min)
		 min = flag[i];
   }
   if ((fp2 = fopen("missile.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n%d\n", max, min);
   fprintf(fp2, "%d\n%d\n", max, min);
   getch();
   return 0;
}
