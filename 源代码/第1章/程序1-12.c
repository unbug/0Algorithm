 #include <time.h>
 #include <stdio.h>
int main()
 {
   int n,m,i=0;
   srand(time(NULL));
   n=rand() % 100 + 1;
   do{
       printf("输入所猜数字:");
       scanf("%d",&m);
       i++;
       if (m>n)
           printf("错误!所猜数太大了!\n");
       else if (m<n)
           printf("错误!所猜数太小了!\n");
   }while(m!=n);
    printf("答对了!\n");
    printf("共猜测了%d次。\n",i);
    if(i<=5)
        printf("你太聪明了，这么快就猜出来了！");
    else if(i>5)
        printf("还需改进方法，以便更快猜出来！");
    getch();
    return 0;
}
