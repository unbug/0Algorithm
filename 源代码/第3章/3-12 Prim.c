#define USED 0    //已使用，加入U集合 
#define NOADJ -1  //非邻接顶点 
void Prim(MatrixGraph G)//最小生成树
{
    int i,j,k,min,sum=0;
    int weight[VERTEX_MAX];//权值
    char tmpvertex[VERTEX_MAX];//临时顶点信息
    
    for(i=1;i<G.VertexNum;i++) //保存邻接矩阵中的一行数据 
    {
        weight[i]=G.Edges[0][i]; //权值 
        if(weight[i]==MAXVALUE)
            tmpvertex[i]=NOADJ; //非邻接顶点 
        else
            tmpvertex[i]=G.Vertex[0]; //邻接顶点 
    }
    tmpvertex[0]=USED; //将0号顶点并入U集 
    weight[0]=MAXVALUE; //设已使用顶点权值为最大值 
    for(i=1;i<G.VertexNum;i++)
    {
        min=weight[0]; //最小权值 
        k=i;
        for(j=1;j<G.VertexNum;j++) //查找权值最小的一个邻接边 
            if(weight[j]<min && tmpvertex[j]>0) //找到具有更小权值的未使用边 
            {
                min=weight[j]; //保存权值 
                k=j; //保存邻接点序号 
            }
        sum+=min;//累加权值 
        printf("(%c,%c),",tmpvertex[k],G.Vertex[k]); //输出生成树一条边 
        tmpvertex[k]=USED; //将编号为k的顶点并入U集 
        weight[k]=MAXVALUE; //已使用顶点的权值为最大值 
        for(j=0;j<G.VertexNum;j++) //重新选择最小边 
            if(G.Edges[k][j]<weight[j] && tmpvertex[j]!=0)
            {
                weight[j]=G.Edges[k][j]; //权值 
                tmpvertex[j]=G.Vertex[k]; //上一个顶点信息 
            }
    }
    printf("\n最小生成树的总权值为:%d\n",sum);
}
