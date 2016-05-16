#include <stdio.h>
int main()
{
   int i, weekday[7], t1, t2, max, day;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("unhappy.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   for (i = 0; i < 7; i++)	//读取7天的数据 
   {
	  fscanf(fp1, "%d%d\n", &t1, &t2);
	  weekday[i] = x + y;	//保存7天的学习时间 
   }
   fclose(fp1);
   day = -1;	//
   max = 0;	//
   for (i = 0; i < 7; i++)
   {
	  if (weekday[i] > 8)	//若第i天学习时间超过8小时 
	  {
		 if (weekday[i] > max)	//超过最大值 
		 {
			max = weekday[i];	//保存最不高兴那天的学习时间 
			day = i;	//保存不高兴的星期数 
		 }
	  }
   }
   if ((fp2 = fopen("unhappy.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n", day + 1);	//输出不高兴的星期几 
   fprintf(fp2, "%d\n", day + 1);
   fclose(fp2);
   getch();
   return 0;
}
