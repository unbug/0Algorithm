#include <stdio.h>
#define MAXN 101
int main()
{
   int flag1[MAXN]={0}, flag2[MAXN]={0}, a[MAXN]={0};
   int n, max;
   int i, j;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("chorus.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);
   for (i = 1; i <= n; i++)
	  fscanf(fp1, "%d", &a[i]);
   fclose(fp1);
   a[0] = 0;	//����Ϊһ����Сֵ
   for (i = 1; i <= n; i++) //�ö�������������� 
   {
	  for (j = i - 1; j >= 0; j--)
	  {
		 if (a[j] < a[i] && (flag1[j] + 1 > flag1[i]))
			flag1[i] = flag1[j] + 1;
	  }
   }
   a[n + 1] = 0;	//�������һ����Сֵ
   for (i = n; i >= 1; i--)//�ö�������������� 
   {
	  for (j = i + 1; j <= n + 1; j++)
	  {
		 if (a[j] < a[i] && flag2[j] + 1 > flag2[i])
			flag2[i] = flag2[j] + 1;
	  }
   }
   max = 0;
   for (i = 1; i <= n; i++) //��������ͽ������е�������� 
   {
	  if (flag1[i] + flag2[i] > max)
	  {
		 max = flag1[i] + flag2[i];
		 printf("%d,%d\n",flag1[i],flag2[i]);
      }
   }
   if ((fp2 = fopen("chorus.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", n - max + 1); //��ȥҪ�������������͵õ��������� 
   fprintf(fp2, "%d\n", n - max + 1);
   fclose(fp2);
   getch();
   return 0;
}
