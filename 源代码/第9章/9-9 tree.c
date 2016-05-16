#include <stdio.h>
#define MAXN 10000 //马路总长度
#define REGION 100 //区域总数 
int main()
{
   int start[REGION],end[REGION],tree[MAXN];
   int i,j,m,total,l;   
   FILE *fp1, *fp2;
   total=0;
   for(i=0;i<MAXN;i++) //设置每隔1米种1棵树 
       tree[i]=1;       
   if ((fp1 = fopen("tree.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1,"%d%d",&l,&m); //读入马路长度和区域数量 
   for(i=0;i<m;i++) //读入区域起始点和结束点数据 
       fscanf(fp1,"%d%d",&start[i],&end[i]);
   fclose(fp1); //关闭文件 
   for(i=0;i<m;i++) //将区域部设置为不种树
       for(j=start[i];j<=end[i];j++)
           tree[j]=0;
   for(i=0;i<=l;i++) //统计树的总数 
       if(tree[i])
           total++;
   if ((fp2 = fopen("tree.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fprintf(fp2,"%d\n",total); //输出总数到文件 
   fclose(fp2); //关闭文件 
   printf("%d\n",total);  //输出总数到屏幕 
    getch();
    return 0;
}
