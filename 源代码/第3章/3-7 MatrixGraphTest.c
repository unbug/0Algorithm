#include <stdio.h>
#include "3-6 AdjMatrixGraph.c"
int main()
{
    MatrixGraph G; //���屣���ڽӾ���ṹ��ͼ 
    int i,j;
    printf("��������ͼ������(0:����ͼ,1:����ͼ):");
    scanf("%d",&G.GraphType); //ͼ������
    printf("����ͼ�Ķ��������ͱ�����:");
    scanf("%d,%d",&G.VertexNum,&G.EdgeNum); //����ͼ�������ͱ��� 
    for(i=0;i<G.VertexNum;i++)  //��վ��� 
        for(j=0;j<G.VertexNum;j++)
            G.Edges[i][j]=MAXVALUE; //���þ����и�Ԫ�ص�ֵΪ���ֵ         
    CreateMatrixGraph(&G); //�������ڽӱ����ͼ 
    printf("�ڽӾ�����������:\n");
    OutMatrix(&G);
    getch();
    return 0;
}
