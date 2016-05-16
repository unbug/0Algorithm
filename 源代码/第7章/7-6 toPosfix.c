#include <stdio.h>
#include <stdlib.h>
int PRI(char op) //设定算符的优先级
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
char *toPosfix(char *infix)		// 求后序表达式
{
   int length=strlen(infix);
   char *stack,*buf,*p,flag;
   char op;
   int i,top=0;
   if(!(stack=(char *)malloc(sizeof(char)*length))) //作为栈内存空间
   {
       printf("内存分配失败!\n");
       exit(0); 
   } 
   if(!(buf=(char *)malloc(sizeof(char)*length*2))) //保存后序表达式字符串 
   {
       printf("内存分配失败!\n");
       exit(0); 
   }
   p=buf;
   for(i=0;i<length;i++)
   {
	  op=infix[i]; //获取表达式中一个字符 
	  switch(op) //根据字符进行入栈操作 
	  {
	  case '(': //为左括号 
		 if(top<length) //若栈未满 
		 {
			top++; //修改栈顶指针 
			stack[top]=op; //保存运算符到栈
		 }
		 flag=0;
		 break;
	  case '+':
	  case '-':
	  case '*':
	  case '/':
		 while(PRI(stack[top])>=PRI(op)) //判断栈顶运算符与当前运算符的级别 
		 {
            *p++=stack[top]; //将栈中的运算符保存到字符串 
			top--; //修改栈顶指针 
			flag=0;
		 }
		 if(top<length) //栈未满 
		 {
			top++; //修改栈顶指针 
			stack[top]=op; //保存运算符到栈 
			if(flag==1)
                *p++=','; //添加一个逗号分隔数字 
            flag=0;
		 }
		 break;
	  case ')': //右括号 
		 while(stack[top]!= '(') //在栈中一直找到左括号 
		 {
            *p++=stack[top]; //将栈顶的运算符保存到字符串 
			top--; //修改栈顶指针 
		 }
		 flag=0;
		 top--; //再将修改栈顶指针，将左括号出栈 
		 break;
	  default: //其他字符(数字、字母等非运算符)
		 *p++=op;
		 flag=1;
		 break;
	  }
   }
   while (top>0) //若栈不为空 
   {
	  *p++=stack[top]; //将栈中的运算符出栈 
	  top--; //修改栈顶指针 
   }
   free(stack);//释放栈占用的内存 
   *p='\0';
   return (buf); //返回字符串 
}
double calc(double d1, char op, double d2) //计算函数 
{
   switch (op) //根据运算符进行操作 
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
double eval(char *postfix)		//计算表达式的值 
{
   double *stack,num,k=1.0; //k为系数 
   int i,length,top=0,dec=0,flag;//dec为0表示整数,为1表示小数,flag=1表示有数据需入栈 
   char token;

   length=strlen(postfix);
   if(!(stack=(double *)malloc(sizeof(double)*length)))
   {
       printf("内存分配失败!\n");
       exit(0); 
   }
   num=0;
   for(i=0;i<length;i++)
   {
	  token=postfix[i]; //取出一个字符 
	  switch(token)
	  {
	  case '+': //若是运算符 
	  case '-':
	  case '*':
	  case '/':
         if(top<length && flag==1) //若栈未满 
		 {
 		    top++; //修改栈顶指针 
    		stack[top]=(double)num; //将数字保存到栈中
    		num=0;
         }         
		 stack[top-1]=calc(stack[top-1], token, stack[top]);//取出栈栈前两个元素进行运算，结果保存到栈中 
		 top--; //修改栈顶指针 
		 dec=0;//先设为整数	
         flag=0;//下一步操作不将数入栈	 
		 break;
	  default: //不为运算符 
	     if(token==',') //若为逗号
         {
    		 if(top<length) //若栈未满 
    		 {
    			top++; //修改栈顶指针 
    			stack[top]=(double)num; //将数字保存到栈中
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
         if(dec==1) //小数部分 
         {
            k=k*0.1;
            num=num+(token-'0')*k;
         }
         else
         {
             num=num*10+token-'0';
         }
         flag=1;//有数需要入库 
		 break;
	  }
   }
   return stack[top]; //返回栈顶的结果 
}
int main()
{
   char infix[80];
   printf("输入表达式:");
   scanf("%s",infix); 
   printf("中序表达式:%s\n", infix);
   printf("后序表达式:%s\n", toPosfix(infix));
   printf("后序表达式求值:%lf\n",eval(toPosfix(infix)));
   getch();
   return 0;
}
