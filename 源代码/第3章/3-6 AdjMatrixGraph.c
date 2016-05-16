#define VERTEX_MAX 26   //图的最大顶点数   
#define MAXVALUE 32767 //最大值(可设为一个最大整数) 
typedef struct
{
    char Vertex[VERTEX_MAX]; //保存顶点信息(序号或字母)
    int Edges[VERTEX_MAX][VERTEX_MAX]; //保存边的权 
    int isTrav[VERTEX_MAX]; //遍历标志 
    int VertexNum; //顶点数量 
    int EdgeNum;//边数量 
    int GraphType; //图的类型(0:无向图，1:有向图)    
}MatrixGraph; //定义邻接矩阵图结构 

void CreateMatrixGraph(MatrixGraph *G);//创建邻接矩阵图 
void OutMatrix(MatrixGraph *G); //输出邻接矩阵

void CreateMatrixGraph(MatrixGraph *G)//创建邻接矩阵图 
{
    int i,j,k,weight;
    char start,end; //边的起始顶点 
    printf("输入各顶点信息\n");
    for(i=0;i<G->VertexNum;i++) //输入顶点 
    {
        getchar();
        printf("第%d个顶点:",i+1);
        scanf("%c",&(G->Vertex[i])); //保存到各顶点数组元素中 
    }
    printf("输入构成各边的两个顶点及权值(用逗号分隔):\n"); 
    for(k=0;k<G->EdgeNum;k++)  //输入边的信息 
    {
        getchar(); //暂停输入 
        printf("第%d条边：",k+1);
        scanf("%c,%c,%d",&start,&end,&weight);
        for(i=0;start!=G->Vertex[i];i++); //在已有顶点中查找始点 
        for(j=0;end!=G->Vertex[j];j++); //在已有顶点中查找结终点 
        G->Edges[i][j]=weight; //对应位置保存权值，表示有一条边
        if(G->GraphType==0)  //若是无向图
            G->Edges[j][i]=weight;//在对角位置保存权值  
    }
}

void OutMatrix(MatrixGraph *G)//输出邻接矩阵 
{
    int i,j;
    for(j=0;j<G->VertexNum;j++)
        printf("\t%c",G->Vertex[j]);          //在第1行输出顶点信息 
    printf("\n");
    for(i=0;i<G->VertexNum;i++) 
    {
        printf("%c",G->Vertex[i]);
        for(j=0;j<G->VertexNum;j++)
        {
            if(G->Edges[i][j]==MAXVALUE) //若权值为最大值 
                printf("\t∞");          //输出无穷大符号 
            else
                printf("\t%d",G->Edges[i][j]); //输出边的权值 
        }
        printf("\n");
    }             
}
