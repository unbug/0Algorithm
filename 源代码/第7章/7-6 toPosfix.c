#include <stdio.h>
#include <stdlib.h>
int PRI(char op) //�趨��������ȼ�
{
   switch (op)
   {
   case '+':
   case '-':
	  return 1;
   case '*':
   case '/':
	  return 2;
   default:
	  return 0;
   }
}
char *toPosfix(char *infix)		// �������ʽ
{
   int length=strlen(infix);
   char *stack,*buf,*p,flag;
   char op;
   int i,top=0;
   if(!(stack=(char *)malloc(sizeof(char)*length))) //��Ϊջ�ڴ�ռ�
   {
       printf("�ڴ����ʧ��!\n");
       exit(0); 
   } 
   if(!(buf=(char *)malloc(sizeof(char)*length*2))) //���������ʽ�ַ��� 
   {
       printf("�ڴ����ʧ��!\n");
       exit(0); 
   }
   p=buf;
   for(i=0;i<length;i++)
   {
	  op=infix[i]; //��ȡ���ʽ��һ���ַ� 
	  switch(op) //�����ַ�������ջ���� 
	  {
	  case '(': //Ϊ������ 
		 if(top<length) //��ջδ�� 
		 {
			top++; //�޸�ջ��ָ�� 
			stack[top]=op; //�����������ջ
		 }
		 flag=0;
		 break;
	  case '+':
	  case '-':
	  case '*':
	  case '/':
		 while(PRI(stack[top])>=PRI(op)) //�ж�ջ��������뵱ǰ������ļ��� 
		 {
            *p++=stack[top]; //��ջ�е���������浽�ַ��� 
			top--; //�޸�ջ��ָ�� 
			flag=0;
		 }
		 if(top<length) //ջδ�� 
		 {
			top++; //�޸�ջ��ָ�� 
			stack[top]=op; //�����������ջ 
			if(flag==1)
                *p++=','; //���һ�����ŷָ����� 
            flag=0;
		 }
		 break;
	  case ')': //������ 
		 while(stack[top]!= '(') //��ջ��һֱ�ҵ������� 
		 {
            *p++=stack[top]; //��ջ������������浽�ַ��� 
			top--; //�޸�ջ��ָ�� 
		 }
		 flag=0;
		 top--; //�ٽ��޸�ջ��ָ�룬�������ų�ջ 
		 break;
	  default: //�����ַ�(���֡���ĸ�ȷ������)
		 *p++=op;
		 flag=1;
		 break;
	  }
   }
   while (top>0) //��ջ��Ϊ�� 
   {
	  *p++=stack[top]; //��ջ�е��������ջ 
	  top--; //�޸�ջ��ָ�� 
   }
   free(stack);//�ͷ�ջռ�õ��ڴ� 
   *p='\0';
   return (buf); //�����ַ��� 
}
double calc(double d1, char op, double d2) //���㺯�� 
{
   switch (op) //������������в��� 
   {
   case '+':
	  return d1 + d2;
   case '-':
	  return d1 - d2;
   case '*':
	  return d1 * d2;
   case '/':
	  return d1 / d2;
   }
   return 0;
}
double eval(char *postfix)		//������ʽ��ֵ 
{
   double *stack,num,k=1.0; //kΪϵ�� 
   int i,length,top=0,dec=0,flag;//decΪ0��ʾ����,Ϊ1��ʾС��,flag=1��ʾ����������ջ 
   char token;

   length=strlen(postfix);
   if(!(stack=(double *)malloc(sizeof(double)*length)))
   {
       printf("�ڴ����ʧ��!\n");
       exit(0); 
   }
   num=0;
   for(i=0;i<length;i++)
   {
	  token=postfix[i]; //ȡ��һ���ַ� 
	  switch(token)
	  {
	  case '+': //��������� 
	  case '-':
	  case '*':
	  case '/':
         if(top<length && flag==1) //��ջδ�� 
		 {
 		    top++; //�޸�ջ��ָ�� 
    		stack[top]=(double)num; //�����ֱ��浽ջ��
    		num=0;
         }         
		 stack[top-1]=calc(stack[top-1], token, stack[top]);//ȡ��ջջǰ����Ԫ�ؽ������㣬������浽ջ�� 
		 top--; //�޸�ջ��ָ�� 
		 dec=0;//����Ϊ����	
         flag=0;//��һ��������������ջ	 
		 break;
	  default: //��Ϊ����� 
	     if(token==',') //��Ϊ����
         {
    		 if(top<length) //��ջδ�� 
    		 {
    			top++; //�޸�ջ��ָ�� 
    			stack[top]=(double)num; //�����ֱ��浽ջ��
    			num=0;
    			dec=0;
                break; 
    		 }
         }
   		 else if(token=='.')
   		 {
            k=1.0;
            dec=1;
            break;
         }
         if(dec==1) //С������ 
         {
            k=k*0.1;
            num=num+(token-'0')*k;
         }
         else
         {
             num=num*10+token-'0';
         }
         flag=1;//������Ҫ��� 
		 break;
	  }
   }
   return stack[top]; //����ջ���Ľ�� 
}
int main()
{
   char infix[80];
   printf("������ʽ:");
   scanf("%s",infix); 
   printf("������ʽ:%s\n", infix);
   printf("������ʽ:%s\n", toPosfix(infix));
   printf("������ʽ��ֵ:%lf\n",eval(toPosfix(infix)));
   getch();
   return 0;
}
