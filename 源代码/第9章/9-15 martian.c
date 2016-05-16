#include <stdio.h>
int max;
int a[10000], collect[10000];
int fact(int p)	//����׳� 
{
   int i, f;
   f = 1;
   for (i = 1; i <= p; i++)	//����׳� 
	  f *= i;
   return f;	//���ؽ׳˽�� 
}
int position(int num)	//����num�ڼ�����λ����� 
{
   int i, pos;
   pos = 0;
   for (i = 1; i <= num; i++)
	  if (collect[i] == 1)	//���ڼ����� 
		 pos++;	//�ۼ���� 
   return pos;	//������� 
}
int makebit(int pos)	//�󼯺���λ��p����
{
   int i = 0, num = 0;
   while (i < pos)
   {
	  num++;	//�ۼ��� 
	  if (collect[num] == 1)	//�������ڼ����� 
		 i++;	//��������1 
   }
   return num;	//���ض�Ӧλ���� 
}
int result(int pos)	//�����������ǰposλ����ʾ����
{
   int i, num, x;
   x = max;	//ֻ�䶯���ǰ��p-1��λ�ܱ�ʾ���������
   num = 0;
   for (i = pos; i >= 1; i--)
   {
	  x /= i;	//����ϵ�� 
	  num += (position(a[i]) - 1) * x;	//�ۼ�a[i]λ����ʾ��ֵ 
	  collect[a[i]] = 0;	//��a[i]�ų������֮�� 
   }
   return num + 1;	//����ǰpλ����ʾ���� 
}
void fill(int p, int num)	//����num���������뼯����
{
   int i, s;
   s = max;
   for (i = p; i >= 2; i--)
   {
	  s /= i;
	  if (num % s == 0)	//��num�ܱ�ϵ������ 
	  {
		 a[i] = makebit(num / s);	//���λ 
		 num = s;	//��һ������ϵ�� 
	  } else	//���ܱ����� 
	  {
		 a[i] = makebit(num / s + 1);	//���λ��ֵ 
		 num = num % s;	//��һ����������
	  }
	  collect[a[i]] = 0;	//����a[i]�ų��ڼ����� 
   }
   a[1] = makebit(1);	//�ڵ�1λ������1
}
int main()
{
   int n, m, i, s;
   int p1, p, yes;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("martian.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);	//������ָͷ�� 
   fscanf(fp1, "%d\n", &m);	//�ۼӵ�һ���� 
   for (i = n; i >= 1; i--)	//�������ݵ������� 
	  fscanf(fp1, "%d", &a[i]);
   fclose(fp1);	//�ر��ļ� 
   p = 0;
   for (i = 1; i <= n; i++)	//��ʼ������ 
	  collect[i] = 0;
   p++;
   while (fact(p) <= m)	//����mӦ�����λ��p
	  p++;
   max = fact(p);	//maxΪ���������p!
   for (i = 1; i <= p; i++)	//���ü���
	  collect[a[i]] = 1;
   m += result(p);	//����ǰpλ����ʾ������m��Ӻ�����ֵ
   for (i = 1; i <= p; i++)	//���ü���
	  collect[a[i]] = 1;
   if (m <= max)	//���ý�λ���ɱ�ʾ��Ӻ���� 
	  fill(p, m);	//����m���Ϊԭ�������� 
   else
   {
	  m -= max;	//��λ��m�����
	  p1 = p;
	  yes = 0;
	  do
	  {
		 p1++;
		 collect[a[p1]] = 1;
		 if (position(a[p1]) != p1)
			yes = 1;
	  }
	  while (yes == 0);	//���Ҫ��λ��������λ��p1
	  s = makebit(position(a[p1]) + 1);
	  collect[s] = 0;	//�ų����� 
	  a[p1] = s;	//��λλ�����λ��ֵ 
	  for (i = p1 - 1; i <= p + 1; i++)	//������е�p1-1λ����p+1λ����С��������
	  {
		 s = makebit(1);	//��1λ���� 
		 a[i] = s;	//���浽a[i]�� 
		 collect[s] = 0;	//����������֮�� 
	  }
	  fill(p, m);	//����m���Ϊԭ�������� 
   }
   if ((fp2 = fopen("martian.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   for (i = n; i >= 2; i--)
   {
	  printf("%d ", a[i]);
	  fprintf(fp2, "%d ", a[i]);
   }
   printf("%d\n", a[1]);
   fprintf(fp2, "%d\n", a[1]);
   fclose(fp2);
   getch();
   return 0;
}
