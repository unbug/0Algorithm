 #include <time.h>
 #include <stdio.h>
int main()
 {
   int n,m,i=0;
   srand(time(NULL));
   n=rand() % 100 + 1;
   do{
       printf("������������:");
       scanf("%d",&m);
       i++;
       if (m>n)
           printf("����!������̫����!\n");
       else if (m<n)
           printf("����!������̫С��!\n");
   }while(m!=n);
    printf("�����!\n");
    printf("���²���%d�Ρ�\n",i);
    if(i<=5)
        printf("��̫�����ˣ���ô��Ͳ³����ˣ�");
    else if(i>5)
        printf("����Ľ��������Ա����³�����");
    getch();
    return 0;
}
