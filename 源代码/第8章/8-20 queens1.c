#include <stdio.h >
int iCount = 0;//记录解的序号的全局变量
int Queens[8];//记录皇后在各列上的放置位置的全局数组
void Output()//输出一个解，即一种没有冲突的放置方案
{
   int i,j,flag=1;
   printf("第%2d种方案(★表示皇后):\n", ++iCount);//输出序号。 
   printf("  ");
   for(i=1;i<=8;i++)
       printf("▁");
   printf("\n");
   for (i = 0; i < 8; i++)
   {
       printf("▕");
       for (j = 0; j < 8; j++)
       {
           if(Queens[i]-1 == j)
               printf("★");
           else
           {
               if (flag<0)
                   printf("  ");
               else
                   printf("█");               
           }
           flag=-1*flag;
       }
       printf("▏\n");
       flag=-1*flag;
   }
   printf("  ");
   for(i=1;i<=8;i++)
       printf("▔");
   printf("\n");  
   getch();
}
int IsValid(int n)//断第n个皇后是否与前面皇后行成攻击
{
   int i;
   for (i = 0; i < n; i++)//第n个皇后与前面n－1个皇后比较 
   {
 	  if (Queens[i] == Queens[n])//两个皇后在同一行上，返回0。
		 return 0;
 	  if (abs(Queens[i] - Queens[n]) == (n - i))//两个皇后在同一对角线上，返回0。
		 return 0;
   }
   return 1;//没有冲突，返回1。
}
void Queen(int n)//在第n列放置皇后
{
   int i;
   if (n == 8)//若8个皇后已放置完成
   {
	  Output(); //输出 
	  return;
   }
   for (i = 1; i <= 8; i++)//在第n列的各个行上依次试探
   { 
	  Queens[n] = i;//在该列的第i行上放置皇后。 
	  if (IsValid(n))//没有冲突，就开始下一列的试探
		 Queen(n + 1); //递归调用进行下一步 
   }
}
int main()
{ 
   printf("八皇后排列方案:\n"); 
   Queen(0);//从第0列开始递归试探 
   getch();
   return 0;
}
