#define VERTEX_MAX 26   //ͼ����󶥵���   
#define MAXVALUE 32767 //���ֵ(����Ϊһ���������) 
typedef struct
{
    char Vertex[VERTEX_MAX]; //���涥����Ϣ(��Ż���ĸ)
    int Edges[VERTEX_MAX][VERTEX_MAX]; //����ߵ�Ȩ 
    int isTrav[VERTEX_MAX]; //������־ 
    int VertexNum; //�������� 
    int EdgeNum;//������ 
    int GraphType; //ͼ������(0:����ͼ��1:����ͼ)    
}MatrixGraph; //�����ڽӾ���ͼ�ṹ 

void CreateMatrixGraph(MatrixGraph *G);//�����ڽӾ���ͼ 
void OutMatrix(MatrixGraph *G); //����ڽӾ���

void CreateMatrixGraph(MatrixGraph *G)//�����ڽӾ���ͼ 
{
    int i,j,k,weight;
    char start,end; //�ߵ���ʼ���� 
    printf("�����������Ϣ\n");
    for(i=0;i<G->VertexNum;i++) //���붥�� 
    {
        getchar();
        printf("��%d������:",i+1);
        scanf("%c",&(G->Vertex[i])); //���浽����������Ԫ���� 
    }
    printf("���빹�ɸ��ߵ��������㼰Ȩֵ(�ö��ŷָ�):\n"); 
    for(k=0;k<G->EdgeNum;k++)  //����ߵ���Ϣ 
    {
        getchar(); //��ͣ���� 
        printf("��%d���ߣ�",k+1);
        scanf("%c,%c,%d",&start,&end,&weight);
        for(i=0;start!=G->Vertex[i];i++); //�����ж����в���ʼ�� 
        for(j=0;end!=G->Vertex[j];j++); //�����ж����в��ҽ��յ� 
        G->Edges[i][j]=weight; //��Ӧλ�ñ���Ȩֵ����ʾ��һ����
        if(G->GraphType==0)  //��������ͼ
            G->Edges[j][i]=weight;//�ڶԽ�λ�ñ���Ȩֵ  
    }
}

void OutMatrix(MatrixGraph *G)//����ڽӾ��� 
{
    int i,j;
    for(j=0;j<G->VertexNum;j++)
        printf("\t%c",G->Vertex[j]);          //�ڵ�1�����������Ϣ 
    printf("\n");
    for(i=0;i<G->VertexNum;i++) 
    {
        printf("%c",G->Vertex[i]);
        for(j=0;j<G->VertexNum;j++)
        {
            if(G->Edges[i][j]==MAXVALUE) //��ȨֵΪ���ֵ 
                printf("\t��");          //����������� 
            else
                printf("\t%d",G->Edges[i][j]); //����ߵ�Ȩֵ 
        }
        printf("\n");
    }             
}
