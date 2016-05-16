#define VERTEX_MAX 20	//ͼ����󶥵���   

typedef struct edgeNode   
{
    int Vertex; 	//�������
    int weight; 	//Ȩֵ
    struct edgeNode *next; 	//ָ���бߵ���һ������ 
}EdgeNode; 	//�ڽӱ�߽ṹ

typedef struct
{
    EdgeNode* AdjList[VERTEX_MAX]; 	//ָ��ÿ�������ָ��
    int VextexNum,EdgeNum;	//ͼ�Ķ���������ͱߵ�����  
    int GraphType; 	//ͼ������(0:����ͼ��1:����ͼ)
}ListGraph; 	//ͼ�Ľṹ 

int Build_AdjList(ListGraph *G)  //��������ͼ�Ķ�����,����,������Ϣ�ͱߵ���Ϣ�����ڽӱ� 
{
    int i,weight;
    int start,end;
    EdgeNode *s;
    for(i=1;i<=G->VextexNum;i++)	//��ͼ�и�����ָ����� 
        G->AdjList[i]=NULL;
    for(i=1;i<=G->EdgeNum;i++) 	//������ߵ��������� 
    {
        getchar();
        printf("��%d����:",i); 
        scanf("%d,%d,%d",&start,&end,&weight);	//����ߵ������յ�
        s=(EdgeNode *)malloc(sizeof(EdgeNode)); 	//���뱣��һ��������ڴ� 
        s->next=G->AdjList[start]; 	//���뵽�ڽӱ��� 
        s->Vertex=end; 	//�����յ���
        s->weight=weight; 	//����Ȩֵ 
        G->AdjList[start]=s; 	//�ڽӱ��Ӧ����ָ��õ� 
     }
} 