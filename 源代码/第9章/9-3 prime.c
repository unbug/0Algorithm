#include <stdio.h>
#define  MAXN  20
char N, K;	//N��������������ѡM������� 
int iCount, Sum;
int Num[MAXN];	//���������MAXN���� 
int Flag[10001];	//����1~10000֮����������±�Ϊ��������Ԫ��ֵΪ1 
int Prime[1229];	//��������
int List[MAXN];	//�����б� 
void GenPrime() //��ɸѡ����2~10000֮�������ѡ����
{
   int i, j, s = 0;
   Flag[0] = Flag[1] = 0;
   for (i = 2; i <= 10000; i++)	//��ʼ������ 
	  Flag[i] = 1;
   for (i = 2; i <= 10000; i++)
   {
	  if (Flag[i] == 1)	//
	  {
		 Prime[s++] = i;	//�����s������Ϊi 
		 j = 2 * i;
		 while (j <= 10000)
		 {
			Flag[j] = 0;
			j = j + i;	//��i�ı���ɸѡ�� 
		 }
	  }
   }
}
void IsPrime(int s)
{
   int i, flag = 0;	//flag��Ϊ0����ʾflag������ 
   if (s < 10000)	//С��10000,ֱ���ж��Ƿ�Ϊ���� 
   {
	  if (Flag[s])	//��s������
		 iCount++;	//���Ӽ�����
   }
   else	//���ۼӺʹ���10000,�赥���ж��Ƿ�Ϊ���� 
   {
	  i = 1;
	  while (Prime[i] * Prime[i] < s)	//s����Prime[i]��ƽ�� 
	  {
		 if (s % Prime[i] == 0)	//��s�ܱ�ĳ���������� 
		 {
			flag = 1;	//��ʾs��������
			break;	//�˳�ѭ�� 
		 }
		 i++;
	  }
	  if (flag == 0)	//�������� 
		 iCount++;	//�ۼ����������� 
   }
}
void Try(int d, int pre)	//��N�������в��� 
{
   int i;
   for (i = pre; i < N - (K - d); i++)
   {
	  Sum += Num[i];	//�ۼ����� 
	  List[d - 1] = i;
	  if (d == K)	//���ۼӵ�������������K�� 
		 IsPrime(Sum);	//���ú����ж�Sum�Ƿ�Ϊ���� 
	  else	//��������K�� 
		 Try(d + 1, i + 1);	//�ݹ���ã��ۼ���һ������ 
	  Sum -= Num[i];	//���ݣ���ȥǰ1������ 
   }
}
int main()
{
   int i;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("prime.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d\n", &N, &K);
   for (i = 0; i < N; i++)	//�������N����
	  fscanf(fp1, "%d", &Num[i]);
   fclose(fp1);
   iCount = 0;	//������ 
   Sum = 0;	//�ۼӺ���0 
   GenPrime();	//���ú�����������������������p�� 
   Try(1, 0);	//�������� 
   if ((fp2 = fopen("prime.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", iCount);  //���������� 
   fprintf(fp2, "%d\n", iCount);
   fclose(fp2);
   getch();
   return 0;
}
