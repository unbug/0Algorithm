#include <stdio.h>
int main()
{
   int i, weekday[7], t1, t2, max, day;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("unhappy.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   for (i = 0; i < 7; i++)	//��ȡ7������� 
   {
	  fscanf(fp1, "%d%d\n", &t1, &t2);
	  weekday[i] = x + y;	//����7���ѧϰʱ�� 
   }
   fclose(fp1);
   day = -1;	//
   max = 0;	//
   for (i = 0; i < 7; i++)
   {
	  if (weekday[i] > 8)	//����i��ѧϰʱ�䳬��8Сʱ 
	  {
		 if (weekday[i] > max)	//�������ֵ 
		 {
			max = weekday[i];	//��������������ѧϰʱ�� 
			day = i;	//���治���˵������� 
		 }
	  }
   }
   if ((fp2 = fopen("unhappy.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", day + 1);	//��������˵����ڼ� 
   fprintf(fp2, "%d\n", day + 1);
   fclose(fp2);
   getch();
   return 0;
}
