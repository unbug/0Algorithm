#include <stdio.h>
#define  MAXN  20
char N, K;	//N保存整数个数，选M个数相加 
int iCount, Sum;
int Num[MAXN];	//保存输入的MAXN个数 
int Flag[10001];	//保存1~10000之间的数，若下标为素数，则元素值为1 
int Prime[1229];	//保存素数
int List[MAXN];	//保存列表 
void GenPrime() //用筛选法将2~10000之间的素数选出来
{
   int i, j, s = 0;
   Flag[0] = Flag[1] = 0;
   for (i = 2; i <= 10000; i++)	//初始化数组 
	  Flag[i] = 1;
   for (i = 2; i <= 10000; i++)
   {
	  if (Flag[i] == 1)	//
	  {
		 Prime[s++] = i;	//保存第s个素数为i 
		 j = 2 * i;
		 while (j <= 10000)
		 {
			Flag[j] = 0;
			j = j + i;	//将i的倍数筛选掉 
		 }
	  }
   }
}
void IsPrime(int s)
{
   int i, flag = 0;	//flag若为0，表示flag是素数 
   if (s < 10000)	//小于10000,直接判断是否为素数 
   {
	  if (Flag[s])	//若s是素数
		 iCount++;	//增加计数器
   }
   else	//若累加和大于10000,需单独判断是否为素数 
   {
	  i = 1;
	  while (Prime[i] * Prime[i] < s)	//s大于Prime[i]的平方 
	  {
		 if (s % Prime[i] == 0)	//若s能被某个素数整除 
		 {
			flag = 1;	//表示s不是素素
			break;	//退出循环 
		 }
		 i++;
	  }
	  if (flag == 0)	//若是素数 
		 iCount++;	//累加素数计数器 
   }
}
void Try(int d, int pre)	//在N个数据中查找 
{
   int i;
   for (i = pre; i < N - (K - d); i++)
   {
	  Sum += Num[i];	//累加整数 
	  List[d - 1] = i;
	  if (d == K)	//若累加的整数个数等于K个 
		 IsPrime(Sum);	//调用函数判断Sum是否为素数 
	  else	//若不等于K个 
		 Try(d + 1, i + 1);	//递归调用，累加下一个整数 
	  Sum -= Num[i];	//回溯，减去前1个整数 
   }
}
int main()
{
   int i;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("prime.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d\n", &N, &K);
   for (i = 0; i < N; i++)	//逐个输入N个数
	  fscanf(fp1, "%d", &Num[i]);
   fclose(fp1);
   iCount = 0;	//计数器 
   Sum = 0;	//累加和清0 
   GenPrime();	//调用函数生成素数，保存在数组p中 
   Try(1, 0);	//反复查找 
   if ((fp2 = fopen("prime.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n", iCount);  //输出结果数量 
   fprintf(fp2, "%d\n", iCount);
   fclose(fp2);
   getch();
   return 0;
}
