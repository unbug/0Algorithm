#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int main()
{
    int i,n,sum=0; 
    double x,y;
    printf("����������:");
    scanf("%d",&n); 
    srand(time(NULL));    
    for(i=1;i<n;i++)
    {
        x=(double)rand()/RAND_MAX; //����0~1֮���һ������� 
        y=(double)rand()/RAND_MAX;//����0~1֮���һ������� 
        if((x*x+y*y)<=1) //������Ӱ���� 
            sum++; //���� 
    }
    printf("PI=%f\n",(double)4*sum/n); //������ 
    getch();
    return 0; 
}
