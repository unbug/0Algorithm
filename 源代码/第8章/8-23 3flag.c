#include <stdio.h>
int iCount = 0;	//保存对调的次数 
void swap(char *x, char *y)
{
   char t;
   t = *x;
   *x = *y;
   *y = t;
   iCount++;	//累加对调次数 
}
int main()
{
   char color[] = "rwbwwbrbwr";	//表示旗子排列的数组 
   int B = 0, W = 0, R = strlen(color) - 1;
   int i;
   printf("三色旗最初排列效果:");
   for (i = 0; i <= R; i++)	//输出最初的旗子排列 
	  printf("%c", color[i]);
   printf("\n");
   while (color[W] == 'b')	//若是白旗 
   {
	  B++;	//向后移动蓝旗标识 
	  W++;	//向后移动白旗标识 
   }
   while (color[R] == 'r')	//若红旗 
	  R--;	//向前移动红旗标识 
   while (W <= R)	//循环执行,直到白色标识大于红色标识 
   {
	  if (color[W] == 'r')	//若是红色旗 
	  {
		 swap(&color[W], &color[R]);	//对调红色旗和白色旗 
		 R--;	//向前移动红旗标识  
		 while (color[R] == 'r')	//若是红色旗 
			R--;	//向前移动红旗标识
	  }
	  while (color[W] == 'w')	//若是白色旗 
		 W++;	//向前移动白旗标识
	  if (color[W] == 'b')	//若是蓝色旗 
	  {
		 swap(&color[W], &color[B]);	//对调白色和蓝色旗 
		 B++;	//向后移动蓝旗标识
		 W++;	//向后移动白旗标识
	  }
   }
   printf("通过%d次对调完成,具体结果如下:\n", iCount);
   for (i = 0; i < strlen(color); i++)	//输出移动后的效果 
	  printf("%c", color[i]);
   printf("\n");
   getch();
   return 0;
}
