#include <stdio.h>
int iCount = 0;	//����Ե��Ĵ��� 
void swap(char *x, char *y)
{
   char t;
   t = *x;
   *x = *y;
   *y = t;
   iCount++;	//�ۼӶԵ����� 
}
int main()
{
   char color[] = "rwbwwbrbwr";	//��ʾ�������е����� 
   int B = 0, W = 0, R = strlen(color) - 1;
   int i;
   printf("��ɫ���������Ч��:");
   for (i = 0; i <= R; i++)	//���������������� 
	  printf("%c", color[i]);
   printf("\n");
   while (color[W] == 'b')	//���ǰ��� 
   {
	  B++;	//����ƶ������ʶ 
	  W++;	//����ƶ������ʶ 
   }
   while (color[R] == 'r')	//������ 
	  R--;	//��ǰ�ƶ������ʶ 
   while (W <= R)	//ѭ��ִ��,ֱ����ɫ��ʶ���ں�ɫ��ʶ 
   {
	  if (color[W] == 'r')	//���Ǻ�ɫ�� 
	  {
		 swap(&color[W], &color[R]);	//�Ե���ɫ��Ͱ�ɫ�� 
		 R--;	//��ǰ�ƶ������ʶ  
		 while (color[R] == 'r')	//���Ǻ�ɫ�� 
			R--;	//��ǰ�ƶ������ʶ
	  }
	  while (color[W] == 'w')	//���ǰ�ɫ�� 
		 W++;	//��ǰ�ƶ������ʶ
	  if (color[W] == 'b')	//������ɫ�� 
	  {
		 swap(&color[W], &color[B]);	//�Ե���ɫ����ɫ�� 
		 B++;	//����ƶ������ʶ
		 W++;	//����ƶ������ʶ
	  }
   }
   printf("ͨ��%d�ζԵ����,����������:\n", iCount);
   for (i = 0; i < strlen(color); i++)	//����ƶ����Ч�� 
	  printf("%c", color[i]);
   printf("\n");
   getch();
   return 0;
}
