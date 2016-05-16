#include <stdio.h>
#include <time.h>
void play(int n)
{
    int i,m=0,t=0;
    for(i=0;i<n;i++)
    {
        t=rand()%6+1;
        m+=t;
        printf("\t第%d粒:%d;\n",i+1,t);
    }
    printf("\t总点数为:%d\n",m);                    
}
int main(void)
{
    int c;//参赛人数
    int n;//骰子数量 
    int i,m;
    do{
        srand(time(NULL));
        printf("设置骰子数量(输入0退出):");
        scanf("%d",&n);
        if(n==0) break;//至少一个骰子 
        printf("\n输入本轮参赛人数(输入0退出):");
        scanf("%d",&c);
        if(c==0) break;
        for(i=0;i<c;i++)
        {
            printf("\n第%d位选手掷出的骰子为：\n",i+1); 
            play(n);
        }
        printf("\n");
    }while(1);
    return 0;
}

