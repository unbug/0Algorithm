#include <stdio.h>
int number; //记录移动的步数 
void output(int frog[]) //输出经过一次移动后青蛙的队列 
{
   int i;
   printf("第%2d步:", number++); //输出步数 
   for (i = 0; i <= 6; i++)
   {
	  if(frog[i]==0) //若为空格 
	      printf(" □");
      else if(frog[i]==1) //向右移动的青蛙 
          printf(" ◆");
      else //向左移动的青蛙 
          printf(" ◇");
   }
   printf("\n");
}
void swap(int *a, int *b) //交换两只青蛙的位置 
{
   int t;
   t = *a;
   *a = *b;
   *b = t;
}
int main()
{
   int frog[7] = { 1, 1, 1, 0, -1, -1, -1 };	//初始化数组,1表示向右的青蛙, -1表示向左的青蛙, 0为空位
   int i, flag;
   output(frog);
   while (frog[0] + frog[1] + frog[2] != -3 || frog[4] + frog[5] + frog[6] != 3)	//判断游戏是否结束，若还没有完成青蛙的交换则继续进行循环
   {
	  flag = 1;	//flag为青蛙移动一步的标记1：尚未移动青蛙 0：已经移动青蛙
	  for (i = 0; flag && i < 5; i++)//循环检查现有排列	
      {
		 if (frog[i] == 1 && frog[i + 1] == -1 && frog[i + 2] == 0)//若向右的青蛙可以向右跳过
		 {
			swap(&frog[i], &frog[i + 2]); //向右跳动 
			output(frog); //输出移动一次各青蛙的位置 
			flag = 0;
		 }
	  }
	  for (i = 0; flag && i < 5; i++)//循环检查现有排列 
	  {
		 if (frog[i] == 0 && frog[i + 1] == 1 && frog[i + 2] == -1)//若向左的青蛙可以向左跳
		 {
			swap(&frog[i], &frog[i + 2]); //向左跳动 
			output(frog);//输出移动一次各青蛙的位置
			flag = 0;
		 }
	  }
	  for (i = 0; flag && i < 6; i++)//循环检查现有排列 
	  {
		 if (frog[i] == 1 && frog[i + 1] == 0 && (i == 0 || frog[i - 1] != frog[i + 2]))	//若向右移动青蛙不会产生阻塞
		 {
			swap(&frog[i], &frog[i + 1]);//向右跳动 
			output(frog);//输出移动一次各青蛙的位置
			flag = 0;
		 }
	  }
	  for (i = 0; flag && i < 6; i++)//循环检查现有排列 
	  {
		 if (frog[i] == 0 && frog[i + 1] == -1 && (i == 5 || frog[i - 1] != frog[i + 2]))	//若向左移动青蛙不会产生阻塞
		 {
			swap(&frog[i], &frog[i + 1]);//向左跳动 
			output(frog);//输出移动一次各青蛙的位置
			flag = 0;
		 }
	  }
   }
   getch();
   return 0;
}
