#include <stdio.h>
#define MONTH 12
int main()
{
   int money[MONTH], save, balance, i;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("save.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   if ((fp2 = fopen("save.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   for (i = 0; i < MONTH; i++)	//����12���µ�Ԥ�� 
	  fscanf(fp1, "%d", &money[i]);
   fclose(fp1);
   save = 0;
   balance = 0;
   for (i = 0; i < MONTH; i++)
   {
	  balance = balance + 300 - money[i];	//ÿ��ʣ���� 
	  while (balance >= 100)	//����100 
	  {
		 save += 100;	//����100 
		 balance -= 100;	//ʣ�ಿ�� 
	  }
	  if (balance < 0)	//��ʣ�ಿ��С��0 
	  {
		 printf("%d\n", -(i + 1));	//������²��� 
		 fprintf(fp2, "%d\n", -(i + 1));
		 break;
	  }
   }
   if (balance > 0)	//������0 
   {
	  printf("%.2f\n", balance + (save * 1.2));	//�������ܵĽ�� 
	  fprintf(fp2, "%.2f\n", balance + (save * 1.2));
   }
   getch();
   return 0;
}
