void Dijkstra(MatrixGraph G)
{
    int weight[VERTEX_MAX];//ĳԴ�㵽����������·������
    int path[VERTEX_MAX];//ĳԴ�㵽�յ㾭���Ķ��㼯�ϵ�����
    int tmpvertex[VERTEX_MAX];//���·�����յ㼯��
    int i,j,k,v0,min;
    printf("\n������Դ��ı��:");
    scanf("%d",&v0);
    v0--; //����Լ�1(�������Ǵ�0��ʼ) 
    for(i=0;i<G.VertexNum;i++) //��ʼ�������� 
    {
        weight[i]=G.Edges[v0][i]; //������СȨֵ 
        if(weight[i]<MAXVALUE && weight[i]>0) //��ЧȨֵ 
            path[i]=v0; //�����
        tmpvertex[i]=0; //��ʼ�����㼯��Ϊ�� 
    }
    tmpvertex[v0]=1; //������v0��ӵ�����U�� 
    weight[v0]=0; //��Դ�����Ȩֵ��Ϊ0 
    for(i=0;i<G.VertexNum;i++)
    {
        min=MAXVALUE; //��min�б���һ�����ֵ 
        k=v0; //Դ������� 
        for(j=0;j<G.VertexNum;j++) //��U�����в���δ�ö������СȨֵ 
            if(tmpvertex[j]==0 && weight[j]<min)
            {
                min=weight[j];
                k=j;
            }
        tmpvertex[k]=1;   //������k���뼯��U
        for(j=0;j<G.VertexNum;j++) //�Զ���kΪ�м�㣬���¼���Ȩֵ 
            if(tmpvertex[j]==0 && weight[k]+G.Edges[k][j]<weight[j]) //�и�СȨֵ��·�� 
            {
                weight[j]=weight[k]+G.Edges[k][j]; //����Ȩֵ 
                path[j]=k;
            }
    }
    printf("\n����%c������������·��Ϊ(�յ� < Դ��):\n",G.Vertex[v0]);
    for(i=0;i<G.VertexNum;i++)//������
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
            printf("%c<-%c:��·��\n",G.Vertex[i],G.Vertex[v0]);
    }
}
