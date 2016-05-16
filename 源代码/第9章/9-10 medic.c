//动态规划 
#include <stdio.h>
#define MAXN 100
typedef struct medi
{
   int time;	//采药时间
   int value;	//药品价值
}Medic;
int main()
{
   Medic medic[MAXN]; //保存药品信息 
   int dp[1001][MAXN+1]={0}; //标志数组 
   int i, j, time, m,  a, b;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("medic.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d", &time, &m);	//从文件中读取采药时间和药品数量
   for (i = 1; i <= m; i++)
	  fscanf(fp1, "%d%d", &medic[i].time, &medic[i].value);	//读取采每种药所需时间和药的价值
   fclose(fp1);	//关闭文件 
   for(i=1;i<=time;i++) //循环处理所有时间段 
   {
       for(j=1;j<=m;j++) //循环处理各种药 
       {
           a=dp[i][j-1];
           if(i>=medic[j].time) //时间i足够采序号为j的药 
           {
               b=dp[i-medic[j].time][j-1]+medic[j].value; //累加第j种药的价值 
               if(b>a)
                   a=b;
           }
           dp[i][j]=a; //保存最大价值 
       }
   }
   if ((fp2 = fopen("medic.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n", dp[time][m]);	//输出采到药的总价值 
   fprintf(fp2, "%d\n", dp[time][m]); //输出到文件 
   fclose(fp2);
   getch();
   return 0;
}
