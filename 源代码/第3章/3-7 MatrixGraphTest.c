#include <stdio.h>
#include "3-6 AdjMatrixGraph.c"
int main()
{
    MatrixGraph G; //定义保存邻接矩阵结构的图 
    int i,j;
    printf("输入生成图的类型(0:无向图,1:有向图):");
    scanf("%d",&G.GraphType); //图的种类
    printf("输入图的顶点数量和边数量:");
    scanf("%d,%d",&G.VertexNum,&G.EdgeNum); //输入图顶点数和边数 
    for(i=0;i<G.VertexNum;i++)  //清空矩阵 
        for(j=0;j<G.VertexNum;j++)
            G.Edges[i][j]=MAXVALUE; //设置矩阵中各元素的值为最大值         
    CreateMatrixGraph(&G); //创建用邻接表保存的图 
    printf("邻接矩阵数据如下:\n");
    OutMatrix(&G);
    getch();
    return 0;
}
