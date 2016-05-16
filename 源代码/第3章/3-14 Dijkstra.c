void Dijkstra(MatrixGraph G)
{
    int weight[VERTEX_MAX];//某源点到各顶点的最短路径长度
    int path[VERTEX_MAX];//某源点到终点经过的顶点集合的数组
    int tmpvertex[VERTEX_MAX];//最短路径的终点集合
    int i,j,k,v0,min;
    printf("\n请输入源点的编号:");
    scanf("%d",&v0);
    v0--; //编号自减1(因数组是从0开始) 
    for(i=0;i<G.VertexNum;i++) //初始辅助数组 
    {
        weight[i]=G.Edges[v0][i]; //保存最小权值 
        if(weight[i]<MAXVALUE && weight[i]>0) //有效权值 
            path[i]=v0; //保存边
        tmpvertex[i]=0; //初始化顶点集合为空 
    }
    tmpvertex[v0]=1; //将顶点v0添加到集合U中 
    weight[v0]=0; //将源顶点的权值设为0 
    for(i=0;i<G.VertexNum;i++)
    {
        min=MAXVALUE; //将min中保存一个最大值 
        k=v0; //源顶点序号 
        for(j=0;j<G.VertexNum;j++) //在U集合中查找未用顶点的最小权值 
            if(tmpvertex[j]==0 && weight[j]<min)
            {
                min=weight[j];
                k=j;
            }
        tmpvertex[k]=1;   //将顶点k加入集合U
        for(j=0;j<G.VertexNum;j++) //以顶点k为中间点，重新计算权值 
            if(tmpvertex[j]==0 && weight[k]+G.Edges[k][j]<weight[j]) //有更小权值的路径 
            {
                weight[j]=weight[k]+G.Edges[k][j]; //更新权值 
                path[j]=k;
            }
    }
    printf("\n顶点%c到各顶点的最短路径为(终点 < 源点):\n",G.Vertex[v0]);
    for(i=0;i<G.VertexNum;i++)//输出结果
    {
        if(tmpvertex[i]==1)
        {
            k=i;            
            while(k!=v0)
            {
                j=k;
                printf("%c < ",G.Vertex[k]);
                k=path[k];
            }
            printf("%c\n",G.Vertex[k]);
        }else
            printf("%c<-%c:无路径\n",G.Vertex[i],G.Vertex[v0]);
    }
}
