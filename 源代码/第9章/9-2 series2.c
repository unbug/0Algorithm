#include <stdio.h>
#define MAXN 100	//数组最大下标值
int dec[MAXN] = { 0 }, s[MAXN] =
{
0};	//dec保存n的倒数,s保存结果值
int calc(int k)
{
   int i, div, carry, residue, n = 0;
   s[0] = s[1] = 0;
   do
   {
	  n++;
	  dec[1] = 1 / n;
	  residue = 1 % n;	//余数 
	  for (i = 2; i < MAXN; i++)	//求1/n 
	  {
		 div = residue * 10;	//将余数扩大10倍 
		 residue = div % n;	//得到余数 
		 dec[i] = div / n;	//保存商 
	  }
	  //计算sn
	  div = 0;
	  carry = 0;	//进位 
	  for (i = MAXN - 1; i >= 1; i--)	//从低位开始逐位相加 
	  {
		 div = dec[i] + s[i] + carry;	//累加一位和进位值 
		 carry = div / 10;	//进位 
		 s[i] = div % 10;	//保留一位数        
	  }
	  s[0] = s[0] + carry;	//加进位(K最大为15,b[0]保存10位数         
   }
   while (s[0] * 10 + s[1] < k);
   return n;
}
int main()
{
   int k, n;
   printf("输入数字k(1~15):");
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
