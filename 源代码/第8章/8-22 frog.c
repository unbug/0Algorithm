#include <stdio.h>
int number; //��¼�ƶ��Ĳ��� 
void output(int frog[]) //�������һ���ƶ������ܵĶ��� 
{
   int i;
   printf("��%2d��:", number++); //������� 
   for (i = 0; i <= 6; i++)
   {
	  if(frog[i]==0) //��Ϊ�ո� 
	      printf(" ��");
      else if(frog[i]==1) //�����ƶ������� 
          printf(" ��");
      else //�����ƶ������� 
          printf(" ��");
   }
   printf("\n");
}
void swap(int *a, int *b) //������ֻ���ܵ�λ�� 
{
   int t;
   t = *a;
   *a = *b;
   *b = t;
}
int main()
{
   int frog[7] = { 1, 1, 1, 0, -1, -1, -1 };	//��ʼ������,1��ʾ���ҵ�����, -1��ʾ���������, 0Ϊ��λ
   int i, flag;
   output(frog);
   while (frog[0] + frog[1] + frog[2] != -3 || frog[4] + frog[5] + frog[6] != 3)	//�ж���Ϸ�Ƿ����������û��������ܵĽ������������ѭ��
   {
	  flag = 1;	//flagΪ�����ƶ�һ���ı��1����δ�ƶ����� 0���Ѿ��ƶ�����
	  for (i = 0; flag && i < 5; i++)//ѭ�������������	
      {
		 if (frog[i] == 1 && frog[i + 1] == -1 && frog[i + 2] == 0)//�����ҵ����ܿ�����������
		 {
			swap(&frog[i], &frog[i + 2]); //�������� 
			output(frog); //����ƶ�һ�θ����ܵ�λ�� 
			flag = 0;
		 }
	  }
	  for (i = 0; flag && i < 5; i++)//ѭ������������� 
	  {
		 if (frog[i] == 0 && frog[i + 1] == 1 && frog[i + 2] == -1)//����������ܿ���������
		 {
			swap(&frog[i], &frog[i + 2]); //�������� 
			output(frog);//����ƶ�һ�θ����ܵ�λ��
			flag = 0;
		 }
	  }
	  for (i = 0; flag && i < 6; i++)//ѭ������������� 
	  {
		 if (frog[i] == 1 && frog[i + 1] == 0 && (i == 0 || frog[i - 1] != frog[i + 2]))	//�������ƶ����ܲ����������
		 {
			swap(&frog[i], &frog[i + 1]);//�������� 
			output(frog);//����ƶ�һ�θ����ܵ�λ��
			flag = 0;
		 }
	  }
	  for (i = 0; flag && i < 6; i++)//ѭ������������� 
	  {
		 if (frog[i] == 0 && frog[i + 1] == -1 && (i == 5 || frog[i - 1] != frog[i + 2]))	//�������ƶ����ܲ����������
		 {
			swap(&frog[i], &frog[i + 1]);//�������� 
			output(frog);//����ƶ�һ�θ����ܵ�λ��
			flag = 0;
		 }
	  }
   }
   getch();
   return 0;
}
