#include <stdio.h>
#include "3-10 GraphTrav.c"
int main()
{
    MatrixGraph G; //���屣���ڽӱ�ṹ��ͼ 
    int path[VERTEX_MAX];
    int i,j,s,t;
    char select;
    do
    {
        printf("��������ͼ������(0:����ͼ,1:����ͼ):");
        scanf("%d",&G.GraphType); //ͼ������
        printf("����ͼ�Ķ��������ͱ�����:");
        scanf("%d,%d",&G.VertexNum,&G.EdgeNum); //����ͼ�������ͱ��� 
        for(i=0;i<G.VertexNum;i++)  //��վ��� 
            for(j=0;j<G.VertexNum;j++)
                G.Edges[i][j]=MAXVALUE; //���þ����и�Ԫ�ص�ֵΪ0         
        CreateMatrixGraph(&G); //�����ڽӱ�ṹ��ͼ
        printf("�ڽӾ�����������:\n");
        OutMatrix(&G); //����ڽӾ���             
        DFSTraverse(&G); //���������������ͼ 
        BFSTraverse(&G); //���������������ͼ
        printf("ͼ������ϣ�����������?(Y/N)"); 
        scanf(" %c",&select);
    }while(select!='N' && select!='n');    
    getch();
    return 0;
}
