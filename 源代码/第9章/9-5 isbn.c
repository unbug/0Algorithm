#include <stdio.h>
int main()
{
   char table[12] = { "0123456789X" };
   char str[13];
   int i, j, sum;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("isbn.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fgets(str, 20, fp1); //���ļ��ж�ȡ���� 
   fclose(fp1);	//�ر��ļ� 
   sum = 0;
   j = 1;
   for (i = 0; i < 11; i++) //�����ܺ� 
   {
	  if (i != 1 && i != 5)
		 sum += (str[i] - '0') * j++;
   }
   sum %= 11; //��ģ 
   if ((fp2 = fopen("isbn.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }   
   if (str[12] == table[sum]) //У������ȷ 
   {
	  fputs("Right", fp2); //������ļ� 
	  printf("Right\n");
   }
   else //У������� 
   {
	  str[12] = table[sum]; //������ȷУ���� 
	  fputs(str, fp2); //�����ȷ��ISBN���ļ� 
	  printf("%s\n", str);
   }
   fclose(fp2); //�ر��ļ� 
   getch();
   return 0;
}
