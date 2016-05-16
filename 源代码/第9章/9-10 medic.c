//��̬�滮 
#include <stdio.h>
#define MAXN 100
typedef struct medi
{
   int time;	//��ҩʱ��
   int value;	//ҩƷ��ֵ
}Medic;
int main()
{
   Medic medic[MAXN]; //����ҩƷ��Ϣ 
   int dp[1001][MAXN+1]={0}; //��־���� 
   int i, j, time, m,  a, b;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("medic.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d", &time, &m);	//���ļ��ж�ȡ��ҩʱ���ҩƷ����
   for (i = 1; i <= m; i++)
	  fscanf(fp1, "%d%d", &medic[i].time, &medic[i].value);	//��ȡ��ÿ��ҩ����ʱ���ҩ�ļ�ֵ
   fclose(fp1);	//�ر��ļ� 
   for(i=1;i<=time;i++) //ѭ����������ʱ��� 
   {
       for(j=1;j<=m;j++) //ѭ���������ҩ 
       {
           a=dp[i][j-1];
           if(i>=medic[j].time) //ʱ��i�㹻�����Ϊj��ҩ 
           {
               b=dp[i-medic[j].time][j-1]+medic[j].value; //�ۼӵ�j��ҩ�ļ�ֵ 
               if(b>a)
                   a=b;
           }
           dp[i][j]=a; //��������ֵ 
       }
   }
   if ((fp2 = fopen("medic.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", dp[time][m]);	//����ɵ�ҩ���ܼ�ֵ 
   fprintf(fp2, "%d\n", dp[time][m]); //������ļ� 
   fclose(fp2);
   getch();
   return 0;
}
