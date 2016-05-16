#include <stdio.h>
#define MAXN 100	//��������±�ֵ
int dec[MAXN] = { 0 }, s[MAXN] =
{
0};	//dec����n�ĵ���,s������ֵ
int calc(int k)
{
   int i, div, carry, residue, n = 0;
   s[0] = s[1] = 0;
   do
   {
	  n++;
	  dec[1] = 1 / n;
	  residue = 1 % n;	//���� 
	  for (i = 2; i < MAXN; i++)	//��1/n 
	  {
		 div = residue * 10;	//����������10�� 
		 residue = div % n;	//�õ����� 
		 dec[i] = div / n;	//������ 
	  }
	  //����sn
	  div = 0;
	  carry = 0;	//��λ 
	  for (i = MAXN - 1; i >= 1; i--)	//�ӵ�λ��ʼ��λ��� 
	  {
		 div = dec[i] + s[i] + carry;	//�ۼ�һλ�ͽ�λֵ 
		 carry = div / 10;	//��λ 
		 s[i] = div % 10;	//����һλ��        
	  }
	  s[0] = s[0] + carry;	//�ӽ�λ(K���Ϊ15,b[0]����10λ��         
   }
   while (s[0] * 10 + s[1] < k);
   return n;
}
int main()
{
   int k, n;
   printf("��������k(1~15):");
   scanf("%d", &k);
   if (k == 1)
   {
	  printf("n=2\n");
	  getch();
	  return 0;
   } else
   {
	  n = 0;
	  n = calc(k);
   }
   printf("n=%d\n", n);
   getch();
   return 0;
}
