#include <stdio.h>
#define MAXN 10000 //��·�ܳ���
#define REGION 100 //�������� 
int main()
{
   int start[REGION],end[REGION],tree[MAXN];
   int i,j,m,total,l;   
   FILE *fp1, *fp2;
   total=0;
   for(i=0;i<MAXN;i++) //����ÿ��1����1���� 
       tree[i]=1;       
   if ((fp1 = fopen("tree.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1,"%d%d",&l,&m); //������·���Ⱥ��������� 
   for(i=0;i<m;i++) //����������ʼ��ͽ��������� 
       fscanf(fp1,"%d%d",&start[i],&end[i]);
   fclose(fp1); //�ر��ļ� 
   for(i=0;i<m;i++) //����������Ϊ������
       for(j=start[i];j<=end[i];j++)
           tree[j]=0;
   for(i=0;i<=l;i++) //ͳ���������� 
       if(tree[i])
           total++;
   if ((fp2 = fopen("tree.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fprintf(fp2,"%d\n",total); //����������ļ� 
   fclose(fp2); //�ر��ļ� 
   printf("%d\n",total);  //�����������Ļ 
    getch();
    return 0;
}
