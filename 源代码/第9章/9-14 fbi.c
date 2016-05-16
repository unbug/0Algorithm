#include <stdio.h>
char s[1024];	//保存01组成的串
FILE *fp2;	//输出文件指针 
char make(int left, int right)
{
   int mid;
   char lchild, rchild;
   if (left == right)	//返回叶结点 
   {
	  if (s[left] == '0')
		 return 'B';
	  else
		 return 'I';
   }
   mid = (left + right) / 2;
   lchild = make(left, mid);	//递归调用遍历左子树 
   printf("%c", lchild);
   fprintf(fp2, "%c", lchild);
   rchild = make(mid + 1, right);	//递归调用遍历右子树 
   printf("%c", rchild);
   fprintf(fp2, "%c", rchild);
   if (lchild == 'B' && rchild == 'B') //左右子树都为B  
	  return 'B';
   if (lchild == 'I' && rchild == 'I') //左右子树都为I 
	  return 'I';
   return 'F'; //左右子树不相同 
}
int main()
{
   int n, i, m;
   char ch;
   FILE *fp1;
   if ((fp2 = fopen("fbi.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   if ((fp1 = fopen("fbi.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);
   m = 1;
   for (i = 0; i < n; i++)	//求2的n次方 
	  m *= 2;
   fscanf(fp1, "%s\n", s);	//读入串 
   fclose(fp1);	//关闭输入文件 
   if (n == 0)	//若n为0 
   {
	  if (s[0] == '1')
		 ch = 'I';
	  else
		 ch = 'B';
   } else
	  ch = make(0, m - 1);
   printf("%c", ch);
   fprintf(fp2, "%c", ch);
   fclose(fp2);
   getch();
   return 0;
}
