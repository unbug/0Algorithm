#include <stdio.h>
#include "3-10 GraphTrav.c"
int main()
{
    MatrixGraph G; //定义保存邻接表结构的图 
    int path[VERTEX_MAX];
    int i,j,s,t;
    char select;
    do
    {
        printf("输入生成图的类型(0:无向图,1:有向图):");
        scanf("%d",&G.GraphType); //图的种类
        printf("输入图的顶点数量和边数量:");
        scanf("%d,%d",&G.VertexNum,&G.EdgeNum); //输入图顶点数和边数 
        for(i=0;i<G.VertexNum;i++)  //清空矩阵 
            for(j=0;j<G.VertexNum;j++)
                G.Edges[i][j]=MAXVALUE; //设置矩阵中各元素的值为0         
        CreateMatrixGraph(&G); //生成邻接表结构的图
        printf("邻接矩阵数据如下:\n");
        OutMatrix(&G); //输出邻接矩阵             
        DFSTraverse(&G); //深度优先搜索遍历图 
        BFSTraverse(&G); //广度优先搜索遍历图
        printf("图遍历完毕，继续进行吗?(Y/N)"); 
        scanf(" %c",&select);
    }while(select!='N' && select!='n');    
    getch();
    return 0;
}
