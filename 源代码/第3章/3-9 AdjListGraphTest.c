#include <stdio.h>
#include "3-8 AdjListGraph.c"
int main()
{
    ListGraph G; //���屣���ڽӱ�ṹ��ͼ 
    printf("��������ͼ������(0:����ͼ,1:����ͼ):");
    scanf("%d",&G.GraphType); //ͼ������
    printf("����ͼ�Ķ��������ͱ�����:");
    scanf("%d,%d",&G.VextexNum,&G.EdgeNum); //����ͼ�������ͱ��� 
    printf("���빹�ɸ��ߵ��������㼰Ȩֵ(�ö��ŷָ�):\n"); 
    CreateGraph(&G); //�����ڽӱ�ṹ��ͼ
    printf("���ͼ���ڽӱ�:\n");
    OutList(&G); 
    getch();
    return 0;
}
