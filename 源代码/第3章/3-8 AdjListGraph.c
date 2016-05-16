#define VERTEX_MAX 20   //ͼ����󶥵���   
typedef struct edgeNode   
{
    int Vertex; //������Ϣ(��Ż���ĸ) 
    int weight; //Ȩֵ
    struct edgeNode *next; //ָ����һ������ָ�� (��ǰ�����ָ�����һ���㹹��һ����) 
}EdgeNode; //�ڽӱ�߽ṹ 

typedef struct   
{
    EdgeNode* AdjList[VERTEX_MAX]; //ָ��ÿ�������ָ��
    int VextexNum,EdgeNum; //ͼ�Ķ���������ͱߵ�����  
    int GraphType; //ͼ������(0:����ͼ��1:����ͼ)
}ListGraph;  //ͼ�Ľṹ 

void CreateGraph(ListGraph *G); //����ͼ���ڽӱ�   
void OutList(ListGraph *G); //����ڽӱ�

void CreateGraph(ListGraph *G)  //�����ڽӱ�ṹͼ
{
    int i,weight;
    int start,end;
    EdgeNode *s;
    for(i=1;i<=G->VextexNum;i++)//��ͼ�и�����ָ����� 
        G->AdjList[i]=NULL;
    for(i=1;i<=G->EdgeNum;i++) //������ߵ��������� 
    {
        getchar();
        printf("��%d����:",i); 
        scanf("%d,%d,%d",&start,&end,&weight); //����ߵ������յ�
        s=(EdgeNode *)malloc(sizeof(EdgeNode)); //���뱣��һ��������ڴ� 
        s->next=G->AdjList[start]; //���뵽�ڽӱ��� 
        s->Vertex=end; //�����յ���
        s->weight=weight; //����Ȩֵ 
        G->AdjList[start]=s; //�ڽӱ��Ӧ����ָ��õ� 
        if(G->GraphType==0) //��������ͼ���ٲ��뵽�յ�ı�����
        {
            s=(EdgeNode *)malloc(sizeof(EdgeNode)); //���뱣��һ��������ڴ� 
            s->next=G->AdjList[end];
            s->Vertex=start;
            s->weight=weight;
            G->AdjList[end]=s;
        }
    }   
} 
void OutList(ListGraph *G)
{
    int i;
    EdgeNode *s;
    for(i=1;i<=G->VextexNum;i++)
    {
        printf("����%d",i); 
        s=G->AdjList[i];
        while(s)
        {
            printf("->%d(%d)",s->Vertex,s->weight); 
            s=s->next;
        }
        printf("\n");
    }
}
