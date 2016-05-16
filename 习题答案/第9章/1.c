#include <stdio.h>

int main()
{
   int l,r,i,t,b,num=0;

   FILE *fp1, *fp2;
   if ((fp1 = fopen("no1_in.txt", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d %d", &l,&r);
   fclose(fp1);   

   for(i=l;i<=r;i++)
   {
       t=i;
       while(t)
       {
           b=t%10;
           if(b==3)
               num++;
           t=t/10;
       }
   }  

   if ((fp2 = fopen("no1_out.txt", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("Total=%d\n", num);
   fprintf(fp2, "%d\n", num);
   fclose(fp2);   
    getch();
    return 0;
}