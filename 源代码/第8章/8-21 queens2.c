#include<stdio.h>
int Queens[8];
int iCount = 0;	//统计找到解的数量 
void Output() //输出一个解，即一种没有冲突的放置方案
{
   int i, j, flag = 1;
   printf("第%2d种方案(★表示皇后):\n", ++iCount);	//输出序号。 
   printf("  ");
   for (i = 1; i <= 8; i++)
	  printf("▁");
   printf("\n");
   for (i = 0; i < 8; i++)
   {
	  printf("▕");
	  for (j = 0; j < 8; j++)
	  {
		 if (Queens[i] - 1 == j)
			printf("★");
		 else
		 {
			if (flag < 0)
			   printf("  ");
			else
			   printf("█");
		 }
		 flag = -1 * flag;
	  }
	  printf("▏\n");
	  flag = -1 * flag;
   }
   printf("  ");
   for (i = 1; i <= 8; i++)
	  printf("▔");
   printf("\n");
   getch();
}
void Queen()
{
   int i, j, flag, iscontinue = 1;
   i = 0;	//正在处理的元素下标，表示前i-1个元素已符合要求，正在处理第i个元素 
   Queens[0] = 1;	//为数组的第一个元素赋初值 
   while (iscontinue)	//继续处理 
   {
	  while (iscontinue && i <= 7)	//还未处理到第8个皇后 
	  {
		 flag = 1;
		 for (j = 0; flag && j < i; j++)	//逐列扫描
			if (Queens[j] == Queens[i])	//若两个皇后在同一列 
			   flag = 0;
		 for (j = 0; flag && j < i; j++)	//判断是否有两个皇后同一对角线 
			if (abs(Queens[i] - Queens[j]) == (i - j))
			   flag = 0;
		 if (!flag)	//若皇后位置有冲突 
		 {
			if (Queens[i] == Queens[i - 1])	//Queens[i]的值已经经过一圈追上Queens[i-1]的值 
			{
			   i--;	//退回一步，重新试探处理前一个元素
			   if (i > 0 && Queens[i] == 8)	//当Queens[i]为8时,表示最后一列 
				  Queens[i] = 1;	//将Queens[i]的值置1,从第1列开始 
			   else if (i == 0 && Queens[i] == 8)	//当第一位的值达到8时
				  iscontinue = 0;	//设置结束循环 
			   else
				  Queens[i]++;	//将Queens[i]的值取下一个值
			} else if (Queens[i] == 8)	//若已到第8列 
			   Queens[i] = 1;	//从第1列开始 
			else
			   Queens[i]++;	//将Queens[i]的值取下一个值 
		 } else if (++i < 8)
			if (Queens[i - 1] == 8)
			   Queens[i] = 1;	//若前一个元素的值为8则Queens[i]=1
			else
			   Queens[i] = Queens[i - 1] + 1;	//否则元素的值为前一个元素的下一个值
	  }
	  if (iscontinue)	//若还有有方案 
	  {
		 Output();	//输出一种方案 
		 if (Queens[6] < 8)	//若例数第2列的值未超过8 
			Queens[6]++;	//修改倒数第二位的值 
		 else
			Queens[6] = 1;	//从第1列开始 
		 i = 6;	//开始寻找下一个满足条件的解 
	  }
   }
}
int main()
{
   printf("八皇后排列方案:\n");
   Queen();	//调用函数查找排列方案 
   getch();
   return 0;
}
