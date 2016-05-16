#define USED 0    //��ʹ�ã�����U���� 
#define NOADJ -1  //���ڽӶ��� 
void Prim(MatrixGraph G)//��С������
{
    int i,j,k,min,sum=0;
    int weight[VERTEX_MAX];//Ȩֵ
    char tmpvertex[VERTEX_MAX];//��ʱ������Ϣ
    
    for(i=1;i<G.VertexNum;i++) //�����ڽӾ����е�һ������ 
    {
        weight[i]=G.Edges[0][i]; //Ȩֵ 
        if(weight[i]==MAXVALUE)
            tmpvertex[i]=NOADJ; //���ڽӶ��� 
        else
            tmpvertex[i]=G.Vertex[0]; //�ڽӶ��� 
    }
    tmpvertex[0]=USED; //��0�Ŷ��㲢��U�� 
    weight[0]=MAXVALUE; //����ʹ�ö���ȨֵΪ���ֵ 
    for(i=1;i<G.VertexNum;i++)
    {
        min=weight[0]; //��СȨֵ 
        k=i;
        for(j=1;j<G.VertexNum;j++) //����Ȩֵ��С��һ���ڽӱ� 
            if(weight[j]<min && tmpvertex[j]>0) //�ҵ����и�СȨֵ��δʹ�ñ� 
            {
                min=weight[j]; //����Ȩֵ 
                k=j; //�����ڽӵ���� 
            }
        sum+=min;//�ۼ�Ȩֵ 
        printf("(%c,%c),",tmpvertex[k],G.Vertex[k]); //���������һ���� 
        tmpvertex[k]=USED; //�����Ϊk�Ķ��㲢��U�� 
        weight[k]=MAXVALUE; //��ʹ�ö����ȨֵΪ���ֵ 
        for(j=0;j<G.VertexNum;j++) //����ѡ����С�� 
            if(G.Edges[k][j]<weight[j] && tmpvertex[j]!=0)
            {
                weight[j]=G.Edges[k][j]; //Ȩֵ 
                tmpvertex[j]=G.Vertex[k]; //��һ��������Ϣ 
            }
    }
    printf("\n��С����������ȨֵΪ:%d\n",sum);
}
