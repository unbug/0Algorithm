#include <stdio.h>
int main()
{
   int a[20][20],m,n,k,time,i,j,row,col,row1,col1,sum,flag; //����A����ÿ�껨���� 
   FILE *fp1, *fp2;
   if ((fp1 = fopen("peanuts.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1,"%d%d%d\n",&m,&n,&k); //���ļ���ȡ�С��С�ʱ�� 
   for(i=0;i<m;i++) //���뻨�������� 
       for(j=0;j<n;j++)
           fscanf(fp1,"%d",&a[i][j]);       
   fclose(fp1); //�ر��ļ� 
   row=col=0;//��ʼλ��
   sum=0; //��ժ�û�������
   flag=1; //�Ƿ���ȥ��ժ���� 
   do{
       row1=col1=0; //���浱ǰ�������λ������ 
       for(i=0;i<m;i++) //�ҳ�������������λ�� 
       {
           for(j=0;j<n;j++)
           {
               if(a[i][j]>a[row1][col1])
               {
                   row1=i;
                   col1=j;
               }
           }
       }
       time=abs(row-row1)+abs(col-col1)+row1+1;//�����ԭ�㵽������������λ��ժ�����󣬻ص�·�����赥λʱ��
       if(k<time || a[row1][col1]==0) //��ʣ��ʱ�䲻������Ŀ��λ�û�������Ϊ0 
            flag=0; //����ժ 
       if(flag==1) //�����Բ�ժ���� 
       {
           sum+=a[row1][col1]; //�ۼ�ժ�õĻ������� 
           k=k-abs(row-row1)-abs(col-col1)-1; //����ʣ���ʱ�� 
           row=row1; //�Ե�ǰ����λ��Ϊ��ʼ�㣬������һ������ 
           col=col1;
           a[row][col]=0; //����ժ�������λ����0 
       }
   }while(flag==1); //�����ܲ�ժ���� 
   if ((fp2 = fopen("peanuts.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n",sum);
   fprintf(fp2,"%d\n",sum);
   fclose(fp2);
   getch();
   return 0;
}
