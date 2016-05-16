#include <stdio.h>
typedef struct goods
{
    double *value; //价值
    double *weight; //重量
    char *select; //是否选中到方案 
    int num;//物品数量 
    double limitw; //限制重量
}GOODS;
double maxvalue,totalvalue;//方案最大价值,物品总价值 
char *select1; //临时数组 
void backpack(GOODS *g, int i, double tw, double tv)//参数为物品i,当前选择已经达到的重量和tw,本方案可能达到的总价值 
{
   int k;
   if (tw + g->weight[i] <= g->limitw)//将物品i包含在当前方案,且重量小于等于限制重量 
   {
	  select1[i] = 1; //选中第i个物品 
	  if (i < g->num - 1) //若物品i不是最后一个物品 
		 backpack(g, i + 1, tw + g->weight[i], tv); //递归调用,继续添加下一物品 
	  else //若已到最后一个物品 
	  {
		 for (k = 0; k < g->num; ++k) //将状态标志复制到option数组中 
			g->select[k] = select1[k];
		 maxvalue = tv; //保存当前方案的最大价值 
	  }
   }
   select1[i] = 0; //取消物品i的选择状态 
   if (tv - g->value[i] > maxvalue)//若物品总价值减去物品i的价值还大于maxv方案中已有的价值,说明还可以继续向方案中添加物品 
   {
	  if (i < g->num - 1) //若物品i不是最后一个物品 
		 backpack(g, i + 1, tw, tv - g->value[i]); //递归调用,继续加入下一物品 
	  else //若已到最后一个物品 
	  {
		 for (k = 0; k < g->num; ++k) //将状态标志复制到option数组中 
			g->select[k] = select1[k];
		 maxvalue = tv - g->value[i]; //保存当前方案的最大价值(从物品总价值中减去物品i的价值)
	  }
   }
}
int main()
{
   double sumweight;
   GOODS g;
   int i;
   printf("背包最大重量:");
   scanf("%lf",&g.limitw);
   printf("可选物品数量:"); 
   scanf("%d",&g.num);
   if(!(g.value = (double *)malloc(sizeof(double)*g.num)))//分配内存保存物品价值 
   {
       printf("内存分配失败\n");
       exit(0); 
   }
   if(!(g.weight = (double *)malloc(sizeof(double)*g.num)))//分配内存保存物品的重量 
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   if(!(g.select = (char *)malloc(sizeof(char)*g.num)))//分配内存保存物品的重量 
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   if(!(select1 = (char *)malloc(sizeof(char)*g.num)))//分配内存保存物品的重量 
   {
       printf("内存分配失败\n");
       exit(0);   
   }
   totalvalue=0;   
   for (i = 0; i < g.num; i++)
   {
	  printf("输入第%d号物品的重量和价值:",i + 1);
	  scanf("%lf%lf",&g.weight[i],&g.value[i]);
	  totalvalue+=g.value[i];//统计所有物品的价值总和 
   }
   printf("\n背包最大能装的重量为:%.2f\n\n",g.limitw);
   for (i = 0; i < g.num; i++)
	  printf("第%d号物品重:%.2f,价值:%.2f\n", i + 1, g.weight[i], g.value[i]);
   for (i = 0; i < g.num; i++)//初始设各物品都没加入选择集 
       select1[i]=0;
   maxvalue=0;//加入方案物品的总价值 
   backpack(&g,0,0.0,totalvalue); //第0号物品加入方案,总重量为0,所有物品价值为totalvalue 
   sumweight=0; 
   printf("\n可将以下物品装入背包,使背包装的物品价值最大:\n");
   for (i = 0; i < g.num; ++i)
	  if (g.select[i])
	  {
		 printf("第%d号物品,重量:%.2f,价值:%.2f\n", i + 1, g.weight[i], g.value[i]);
		 sumweight+=g.weight[i];
      }	 
   printf("\n总重量为: %.2f,总价值为:%.2f\n", sumweight, maxvalue );
   getch();
   return 0;
}
