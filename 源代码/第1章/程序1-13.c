#include <stdio.h>
#include <time.h>
void play(int n)
{
    int i,m=0,t=0;
    for(i=0;i<n;i++)
    {
        t=rand()%6+1;
        m+=t;
        printf("\t��%d��:%d;\n",i+1,t);
    }
    printf("\t�ܵ���Ϊ:%d\n",m);                    
}
int main(void)
{
    int c;//��������
    int n;//�������� 
    int i,m;
    do{
        srand(time(NULL));
        printf("������������(����0�˳�):");
        scanf("%d",&n);
        if(n==0) break;//����һ������ 
        printf("\n���뱾�ֲ�������(����0�˳�):");
        scanf("%d",&c);
        if(c==0) break;
        for(i=0;i<c;i++)
        {
            printf("\n��%dλѡ������������Ϊ��\n",i+1); 
            play(n);
        }
        printf("\n");
    }while(1);
    return 0;
}

