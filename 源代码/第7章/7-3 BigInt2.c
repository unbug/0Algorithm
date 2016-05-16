#include<stdio.h>
#include<malloc.h>
#define MAXBIT 4 //每部分保存的最大位数 
int maxnumber; //全局部量
typedef struct node
{
    int data;
    struct node *next;
}BIGINT,*pBIGINT;   //定义链表结构
pBIGINT BigIntInput() //输入大整数
{
	int i,j,k;
	long sum;
	char c;
    pBIGINT node,ps,qs;
	struct number    //定义临时中间结构
	{
		int num;
		struct number *np;
	}*p,*q;
	p=NULL;     //链首为个位，链尾为高位
	while((c=getchar())!='\n')  //按字符接受数字
	{
		if(c>='0' && c<='9')      //若为数字就存入
		{
			if(!(q=(struct number *)malloc(sizeof(struct number))))
			{
                printf("内存分配失败!\n");
                getch();
                exit(0); 
            }
			q->num=c-'0';       //保存一位整数
			q->np=p; //加入链表 
			p=q;
		}
    }
	if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//分配表头内存
	{
        printf("内存分配失败!\n");getch();
        exit(0); 
    }	
	node->data=-1; //表头
	ps=node;
	while(p!=NULL) //保存输入各位整数的链表不为空
	{
		sum=0;
        i=0;
        k=1;
		while(i<MAXBIT  && p!=NULL) //按MAXBIT 位合并位链表
		{
			sum=sum+k*(p->num); //由低位开始累加数据 
			i++; //位数加1 
            p=p->np; //处理下一位整数 
            k=k*10; //系数 
		}
		if(!(qs=(pBIGINT)malloc(sizeof(BIGINT))))//分配保存节点的内存 
		{
            printf("内存分配失败!\n");getch();
            exit(0); 
        }
		qs->data=sum; //将组合的数据保存到节点 
		ps->next=qs; //将节点插入链表 
		ps=qs;
	}
	ps->next=node;    //完成链表
	return(node);
}
void BigIntPrint(pBIGINT result) //输出大整数 
{
	if(result->next->data!=-1) //若下一节点不是链表结尾，(通过递归找到链表的结尾 )
	{
		BigIntPrint(result->next); //递归调用输出函数 
		if(result->next->next->data==-1) //若下一节点的再下一节点是链表尾 
			printf("%d",result->next->data); //输出下一节点的数据 
		else{
			int i,k=maxnumber;
			for(i=1;i<=MAXBIT ;i++,k/=10) //中间部分的数据不足MAXBIT 位的在前面输出0 
				putchar('0'+result->next->data%(k)/(k/10));
		}
	}
}
pBIGINT BigIntInsert(pBIGINT num1,int num)//在num1节点之后插入一个新的节点，节点中保存值NUM
{
    pBIGINT node;
    if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//分配内存
    {
        printf("内存分配失败!\n");getch();
        exit(0); 
    }
    node->data=num;      //赋值
    num1->next=node;        //将新的节点添加链表num1的后面
    return(node);
}
pBIGINT BigIntAdd(pBIGINT num1,pBIGINT num2)   //完成加法操作
{
	pBIGINT num11,num21,node,temp,temp1;
	int total,number,carry;
	num11=num1->next; //被加数链表的第1个位置 
    num21=num2->next; //加数链表的第1个位置 
	if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//建立存放和的链表表头
	{
        printf("内存分配失败!\n");getch();
        exit(0); 
    }
	node->data=-1; //表头数据部分存放-1 
	temp=node; //使temp指向存放和的链表 
	carry=0; //进位变量
	while(num11->data!=-1 && num21->data!=-1)//都不是表头
	{
		total=num11->data + num21->data + carry;//对应位和上次进位数求和
		number=total % maxnumber;      //记录可以存入链表的数
		carry=total / maxnumber;       //操作maxnumber的数作为进位数
		temp=BigIntInsert(temp,number);    //把可存入的数插入链表
		num11=num11->next;      //取两数的后面部分相加
		num21=num21->next;
    }
	temp1=(num11->data!=-1)?num11:num21;//两数大小不一取尚未处理的指针
	while(temp->data!=-1)     //判断另一个是否到头
	{
		total=temp1->data+carry;//与进位数相加
		number=total%maxnumber;   //记录可存入的数
		carry=total/maxnumber;    //记录进位数
		temp=BigIntInsert(temp,number); //插入链表
		temp1=temp1->next;
	}
	if(carry)     //如果还有进位数
		temp=BigIntInsert(temp,1);//保存进位 
	temp->next=node;   //完成链表
	return(node);   //返回求和结果的链表指针
}
pBIGINT BigIntSub(pBIGINT num1,pBIGINT num2)   //完成减法操作
{
	pBIGINT num11,num21,node,temp;
	int diff,number,borrow;
	num11=num1->next; //被减数链表的第1个位置 
    num21=num2->next; //减数链表的第1个位置 
	if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//建立存放差的链表表头
	{
        printf("内存分配失败!\n");getch();
        exit(0); 
    }
	node->data=-1; //表头数据部分存放-1 
	temp=node; //使temp指向存放差的链表 
	borrow=0; //借位变量
	while(num11->data!=-1)//被减数链表未到表头
	{
		if(num21->data!=-1) //减数链表未到表头
        { 
            diff=num11->data - num21->data - borrow;//减去对应位和上次的借位数
            if(diff<0) //查减为负数，需要借位 
    		{
    		    diff=maxnumber+diff; //借位得到正数 
    		    borrow=1; //设置借位标志
            }else
                borrow=0; //清除借位标志 
            num21=num21->next;//处理下一个减数            
        }
        else
        {
            diff=num11->data - borrow;//减去借位
            borrow=0; 
        }
		temp=BigIntInsert(temp,diff);    //把可存入的数插入链表
		num11=num11->next;      //取两数的后面部分相减 
    }
	while(num21->data!=-1)     //若减数链表未到表头
	{
		diff=num21->data - borrow;//与进位数相加
        if(diff<0) //查减为负数，需要借位 
		{
		    diff=maxnumber+diff; //借位得到正数 
		    borrow=1; //设置借位标志
        }else
            borrow=0; //清除借位标志
        temp=BigIntInsert(temp,diff);    //把可存入的数插入链表   
		num21=num21->next;
	}
	temp->next=node;   //完成链表
	return(node);   //返回求差结果的链表指针
}

int main()
{
	pBIGINT num1,num2,result;
	int i;
	char op;
	maxnumber=1;
	for(i=0;i<MAXBIT;i++) //计算最大数，后面求余运算需要使用 
        maxnumber=maxnumber*10;
   printf("选择大整数的运算(+、-):");  
   scanf("%c", &op);
   fflush(stdin);
   switch (op)
   {
   case '+':
	  printf("\n输入被加数:");
	  num1=BigIntInput();
	  printf("\n输入加数:");
	  num2=BigIntInput();
	  result=BigIntAdd(num1, num2);	//加法 
	  break;
   case '-':
	  printf("\n输入被减数:");
	  num1=BigIntInput();
	  printf("\n输入减数:");
	  num2=BigIntInput();
	  result=BigIntSub(num1,num2);;	//减法 
	  break;
   default:
      printf("运算符输入错误!\n");
      break; 
   }
   if (op == '+' || op == '-')
   {
	  printf("\n结果:");
	  BigIntPrint(result);
      printf("\n");
   }
   getch();
   getch();
   return 0;
}
