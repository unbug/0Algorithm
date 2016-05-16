#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct polyn //定义多项式项的结构 
{
    float coef;  //系数项
    int expn;  //指数
    struct polyn *next; //指向下一项 
}POLYN,*pPOLYN;
void PolynInput(pPOLYN *p) //输入一元多项式
{
    int i,min=INT_MIN; //INT_MIN为int型的最小数 
    pPOLYN p1,p2;    
    if(!(*p=(POLYN *)malloc(sizeof(POLYN)))) //为头结点分配内存 
    {
        printf("内存分配失败!\n");
        exit(0); 
    }
    (*p)->coef=0; //设置头结点的系数为0 
    printf("输入该多项式的项数:");
    scanf("%d",&((*p)->expn));  //使用头结点的指数域保存项数
    (*p)->next=NULL;
    for(i=0;i<(*p)->expn;i++) //输入多项式各项 
    {
        if(!(p1=(pPOLYN)malloc(sizeof(POLYN)))) //分配保存一个多项式项的内存 
        {
            printf("内存分配失败!\n");
            exit(0); 
        }
        printf("第%d项系数:",i+1);
        scanf("%f",&(p1->coef));
        do{
            printf("第%d项指数:",i+1);
            scanf("%d",&(p1->expn));
            if(p1->expn<min)
                printf("\n前项指数值不能小于前一项指数值%d!\n重新输入!\n",(*p)->next->expn);
        }while(p1->expn<min); //使每一项的指数为递增 
        min=p1->expn; //保存本次输入的指数作为参考依据 
        p1->next=(*p)->next;//将节点插入链表中(插入到链表头后面的第1个位置) 
        (*p)->next=p1;
    }
    p1=(*p)->next;//合并多项式中指数值相同的项
    while(p1)
    {
        p2=p1->next; //取下一节点 
        while(p2 && p2->expn==p1->expn) //若节点有效，节与q结点的指数相同 
        {
            p1->coef+=p2->coef; //累加系数 
            p1->next=p2->next; //删除r指向的节点 
            free(p2); //释放p2节点占用的内存 
            p2=p1->next; //处理下一节点 
            (*p)->expn--; //总节点数减1 
        }
        p1=p1->next;
    }
}
void PolynPrint(pPOLYN p) //输出多项式 
{
    pPOLYN p1;
    int i;
    printf("\n\n计算后的多项式共有%d项。\n",p->expn);
    p1=p->next;
    i=1;
    while(p1)
    {
        printf("第%d项,系数:%g,指数:%d\n",i++,p1->coef,p1->expn);
        p1=p1->next;
    }
    printf("\n");
}
void PolynAdd(pPOLYN pa,pPOLYN pb) //多项式相加 pa=pa+pb
{
    pPOLYN pa1,pb1,pc1,p;
    pa1=pa->next;  //指向被加链表的第1个有效项 
    pb1=pb->next; //指向加链表 的第1个有效项
    pc1=pa; //指向被加链表 
    pc1->next=NULL;
    pa->expn=0; //清空多项式项目数量 
    while(pa1 && pb1) //两个多项式都未结束 
    {
        if(pa1->expn > pb1->expn) //pa1指数大于pb1指数 
        {
            pc1->next=pa1; //将pa1加入结果链表中  
            pc1=pa1; 
            pa1=pa1->next; //处理pa1中的下一项 
            pc1->next=NULL;
        }else if(pa1->expn < pb1->expn){ //pa1指数小于pb1指数 
            pc1->next=pb1; //将pb1加入结果 链表中 
            pc1=pb1;
            pb1=pb1->next; //处理pb1中的下一项 
            pc1->next=NULL;
        }else{          //pa1指数等于pb1指数，进行系数相加 
            pa1->coef+=pb1->coef; //累加素数 
            if(pa1->coef!=0) //若系数不为0 
            {
                pc1->next=pa1; //将相加结果添加到结果链表中 
                pc1=pa1;
                pa1=pa1->next; //处理pa1中的下一项 
                pc1->next=NULL;
                p=pb1;
                pb1=pb1->next; //处理pb1中的下一项 
                free(p);
            }
            else//系数为0，则不记录该项 
            {
                p=pa1; //用临时指针指向pa1中的该项 
                pa1=pa1->next; //从链表中删除该项 
                free(p); //释放该项占用内存 
                p=pb1; //用临时指针指向pb1中的该项 
                pb1=pb1->next;//从链表中删除该项 
                free(p);//释放该项占用内存 
                pa->expn--;//后面要进行累加操作，此处先减1 
            }
        }
        pa->expn++; //累加一个结果项 
    }
    if(pa1) //若pa1中还有项 
    {
        pc1->next=pa1; //将pa1中的项添加到结果链表中 
        while(pa1)
        {
            pa->expn++;
            pa1=pa1->next;
        }
    }
    if(pb1) //若pb1中还有项 
    {
        pc1->next=pb1; //将pb1中的项添加到结果链表中 
        while(pb1)
        {
            pa->expn++;
            pb1=pb1->next;
        }
    }
    free(pb); //释放pb头链所占的空间 
}
int main()
{
    pPOLYN pa=NULL,pb=NULL; //指向多项式链表的指针 
    printf("输入第一个多项式数据:\n");
    PolynInput(&pa); //调用函数输入一个多项式 
    printf("\n输入第二个多项式数据:\n");
    PolynInput(&pb); //调用函数，输入另一个多项式 
    PolynAdd(pa,pb); //调用多项式相加函数 
    printf("\n两个多项式之和为：");
    PolynPrint(pa); //输出运算得到的多项式 
    getch();
    return 0;
}
