#include <stdio.h>
char s[1024];	//����01��ɵĴ�
FILE *fp2;	//����ļ�ָ�� 
char make(int left, int right)
{
   int mid;
   char lchild, rchild;
   if (left == right)	//����Ҷ��� 
   {
	  if (s[left] == '0')
		 return 'B';
	  else
		 return 'I';
   }
   mid = (left + right) / 2;
   lchild = make(left, mid);	//�ݹ���ñ��������� 
   printf("%c", lchild);
   fprintf(fp2, "%c", lchild);
   rchild = make(mid + 1, right);	//�ݹ���ñ��������� 
   printf("%c", rchild);
   fprintf(fp2, "%c", rchild);
   if (lchild == 'B' && rchild == 'B') //����������ΪB  
	  return 'B';
   if (lchild == 'I' && rchild == 'I') //����������ΪI 
	  return 'I';
   return 'F'; //������������ͬ 
}
int main()
{
   int n, i, m;
   char ch;
   FILE *fp1;
   if ((fp2 = fopen("fbi.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   if ((fp1 = fopen("fbi.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n);
   m = 1;
   for (i = 0; i < n; i++)	//��2��n�η� 
	  m *= 2;
   fscanf(fp1, "%s\n", s);	//���봮 
   fclose(fp1);	//�ر������ļ� 
   if (n == 0)	//��nΪ0 
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
