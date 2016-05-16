#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct polyn //�������ʽ��Ľṹ 
{
    float coef;  //ϵ����
    int expn;  //ָ��
    struct polyn *next; //ָ����һ�� 
}POLYN,*pPOLYN;
void PolynInput(pPOLYN *p) //����һԪ����ʽ
{
    int i,min=INT_MIN; //INT_MINΪint�͵���С�� 
    pPOLYN p1,p2;    
    if(!(*p=(POLYN *)malloc(sizeof(POLYN)))) //Ϊͷ�������ڴ� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(0); 
    }
    (*p)->coef=0; //����ͷ����ϵ��Ϊ0 
    printf("����ö���ʽ������:");
    scanf("%d",&((*p)->expn));  //ʹ��ͷ����ָ���򱣴�����
    (*p)->next=NULL;
    for(i=0;i<(*p)->expn;i++) //�������ʽ���� 
    {
        if(!(p1=(pPOLYN)malloc(sizeof(POLYN)))) //���䱣��һ������ʽ����ڴ� 
        {
            printf("�ڴ����ʧ��!\n");
            exit(0); 
        }
        printf("��%d��ϵ��:",i+1);
        scanf("%f",&(p1->coef));
        do{
            printf("��%d��ָ��:",i+1);
            scanf("%d",&(p1->expn));
            if(p1->expn<min)
                printf("\nǰ��ָ��ֵ����С��ǰһ��ָ��ֵ%d!\n��������!\n",(*p)->next->expn);
        }while(p1->expn<min); //ʹÿһ���ָ��Ϊ���� 
        min=p1->expn; //���汾�������ָ����Ϊ�ο����� 
        p1->next=(*p)->next;//���ڵ����������(���뵽����ͷ����ĵ�1��λ��) 
        (*p)->next=p1;
    }
    p1=(*p)->next;//�ϲ�����ʽ��ָ��ֵ��ͬ����
    while(p1)
    {
        p2=p1->next; //ȡ��һ�ڵ� 
        while(p2 && p2->expn==p1->expn) //���ڵ���Ч������q����ָ����ͬ 
        {
            p1->coef+=p2->coef; //�ۼ�ϵ�� 
            p1->next=p2->next; //ɾ��rָ��Ľڵ� 
            free(p2); //�ͷ�p2�ڵ�ռ�õ��ڴ� 
            p2=p1->next; //������һ�ڵ� 
            (*p)->expn--; //�ܽڵ�����1 
        }
        p1=p1->next;
    }
}
void PolynPrint(pPOLYN p) //�������ʽ 
{
    pPOLYN p1;
    int i;
    printf("\n\n�����Ķ���ʽ����%d�\n",p->expn);
    p1=p->next;
    i=1;
    while(p1)
    {
        printf("��%d��,ϵ��:%g,ָ��:%d\n",i++,p1->coef,p1->expn);
        p1=p1->next;
    }
    printf("\n");
}
void PolynAdd(pPOLYN pa,pPOLYN pb) //����ʽ��� pa=pa+pb
{
    pPOLYN pa1,pb1,pc1,p;
    pa1=pa->next;  //ָ�򱻼�����ĵ�1����Ч�� 
    pb1=pb->next; //ָ������� �ĵ�1����Ч��
    pc1=pa; //ָ�򱻼����� 
    pc1->next=NULL;
    pa->expn=0; //��ն���ʽ��Ŀ���� 
    while(pa1 && pb1) //��������ʽ��δ���� 
    {
        if(pa1->expn > pb1->expn) //pa1ָ������pb1ָ�� 
        {
            pc1->next=pa1; //��pa1������������  
            pc1=pa1; 
            pa1=pa1->next; //����pa1�е���һ�� 
            pc1->next=NULL;
        }else if(pa1->expn < pb1->expn){ //pa1ָ��С��pb1ָ�� 
            pc1->next=pb1; //��pb1������ ������ 
            pc1=pb1;
            pb1=pb1->next; //����pb1�е���һ�� 
            pc1->next=NULL;
        }else{          //pa1ָ������pb1ָ��������ϵ����� 
            pa1->coef+=pb1->coef; //�ۼ����� 
            if(pa1->coef!=0) //��ϵ����Ϊ0 
            {
                pc1->next=pa1; //����ӽ����ӵ���������� 
                pc1=pa1;
                pa1=pa1->next; //����pa1�е���һ�� 
                pc1->next=NULL;
                p=pb1;
                pb1=pb1->next; //����pb1�е���һ�� 
                free(p);
            }
            else//ϵ��Ϊ0���򲻼�¼���� 
            {
                p=pa1; //����ʱָ��ָ��pa1�еĸ��� 
                pa1=pa1->next; //��������ɾ������ 
                free(p); //�ͷŸ���ռ���ڴ� 
                p=pb1; //����ʱָ��ָ��pb1�еĸ��� 
                pb1=pb1->next;//��������ɾ������ 
                free(p);//�ͷŸ���ռ���ڴ� 
                pa->expn--;//����Ҫ�����ۼӲ������˴��ȼ�1 
            }
        }
        pa->expn++; //�ۼ�һ������� 
    }
    if(pa1) //��pa1�л����� 
    {
        pc1->next=pa1; //��pa1�е�����ӵ���������� 
        while(pa1)
        {
            pa->expn++;
            pa1=pa1->next;
        }
    }
    if(pb1) //��pb1�л����� 
    {
        pc1->next=pb1; //��pb1�е�����ӵ���������� 
        while(pb1)
        {
            pa->expn++;
            pb1=pb1->next;
        }
    }
    free(pb); //�ͷ�pbͷ����ռ�Ŀռ� 
}
int main()
{
    pPOLYN pa=NULL,pb=NULL; //ָ�����ʽ�����ָ�� 
    printf("�����һ������ʽ����:\n");
    PolynInput(&pa); //���ú�������һ������ʽ 
    printf("\n����ڶ�������ʽ����:\n");
    PolynInput(&pb); //���ú�����������һ������ʽ 
    PolynAdd(pa,pb); //���ö���ʽ��Ӻ��� 
    printf("\n��������ʽ֮��Ϊ��");
    PolynPrint(pa); //�������õ��Ķ���ʽ 
    getch();
    return 0;
}
