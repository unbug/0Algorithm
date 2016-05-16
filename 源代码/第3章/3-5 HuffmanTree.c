#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    int weight; //Ȩֵ 
    int parent; //�������� 
    int left; //���������
    int right; //��������� 
}HuffmanTree;
typedef char *HuffmanCode;  //Huffman���� 
void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2)
//��1~x�����ѡ��parent���Ϊ0,Ȩ����С��������� 
{
     int i;
     HuffmanTree *ht1,*ht2,*t;
     ht1=ht2=NULL; //��ʼ���������Ϊ�� 
     for(i=1;i<=n;++i) //ѭ������1~n����㣨����Ҷ���ͷ�Ҷ��㣩 
     {
         if(!ht[i].parent) //�����Ϊ��(����parent=0) 
         {
             if(ht1==NULL) //���ָ��1Ϊ�� 
             {
                 ht1=ht+i; //ָ���i����� 
                 continue; //����ѭ�� 
             }
             if(ht2==NULL) //���ָ��2Ϊ�� 
             {
                 ht2=ht+i; //ָ���i����� 
                 if(ht1->weight>ht2->weight) //�Ƚ���������Ȩ�أ�ʹht1ָ��Ľ��Ȩ��С 
                 {
                     t=ht2;
                     ht2=ht1;
                     ht1=t;
                 }
                 continue; //����ѭ�� 
             }
             if(ht1 && ht2) //��ht1��ht2����ָ�붼��Ч 
             {
                 if(ht[i].weight<=ht1->weight) //��i�����Ȩ��С��ht1ָ��Ľ�� 
                 {
                     ht2=ht1; //ht2����ht1����Ϊ��ʱht1ָ��Ľ���Ϊ��2С�� 
                     ht1=ht+i; //ht1ָ���i����� 
                 }else if(ht[i].weight<ht2->weight){ //����i�����Ȩ��С��ht2ָ��Ľ�� 
                     ht2=ht+i; //ht2ָ���i����� 
                 }
             }
         }
     }
     if(ht1>ht2){ //���ӱȽϣ�ʹ���������ΪҶ��� 
         *bt2=ht1-ht;
         *bt1=ht2-ht;
     }else{
         *bt1=ht1-ht;
         *bt2=ht2-ht;
     }
}

void CreateTree(HuffmanTree *ht,int n,int *w)
{
    int i,m=2*n-1;//�ܵĽڵ���
    int bt1,bt2; //������������� 
    if(n<=1) return ; //ֻ��һ����㣬�޷����� 
    for(i=1;i<=n;++i) //��ʼ��Ҷ��� 
    {
        ht[i].weight=w[i-1];
        ht[i].parent=0;
        ht[i].left=0;
        ht[i].right=0;
    }
    for(;i<=m;++i)//��ʼ��������� 
    {
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].left=0;
        ht[i].right=0;
    }
    for(i=n+1;i<=m;++i) //��������Ҷ��㣬����Huffman�� 
    {
        SelectNode(ht,i-1,&bt1,&bt2); //��1~i-1�����ѡ��parent���Ϊ0,Ȩ����С��������� 
        ht[bt1].parent=i;
        ht[bt2].parent=i;
        ht[i].left=bt1;
        ht[i].right=bt2;
        ht[i].weight=ht[bt1].weight+ht[bt2].weight;
    }
}
void HuffmanCoding(HuffmanTree *ht,int n,HuffmanCode *hc)//,char *letters)
{
     char *cd;
     int start,i;
     int current,parent;    
     cd=(char*)malloc(sizeof(char)*n);//������ʱ���һ���ַ��ı�����  
     cd[n-1]='\0'; //�����ַ���������־ 
     for(i=1;i<=n;i++)
     {
         start=n-1;
         current=i;
         parent=ht[current].parent;//��ȡ��ǰ���ĸ���� 
         while(parent) //����㲻Ϊ�� 
         {
             if(current==ht[parent].left)//���ý���Ǹ�����������  
               cd[--start]='0'; //����Ϊ0 
             else //������Ǹ����������� 
               cd[--start]='1'; //����Ϊ1 
             current=parent; //���õ�ǰ���ָ�򸸽�� 
             parent=ht[parent].parent; //��ȡ��ǰ���ĸ�������    
         }
         hc[i-1]=(char*)malloc(sizeof(char)*(n-start));//���䱣�������ڴ� 
         strcpy(hc[i-1],&cd[start]); //�������ɵı���           
     }
     free(cd); //�ͷű���ռ�õ��ڴ� 
}

void Encode(HuffmanCode *hc,char *alphabet,char *str,char *code)
//��һ���ַ���ת��ΪHuffman����
//hcΪHuffman����� ,alphabetΪ��Ӧ����ĸ��,strΪ��Ҫת�����ַ���,code����ת���Ľ�� 
{
     
     int len=0,i=0,j;
     code[0]='\0';
     while(str[i])
     {
         j=0;
         while(alphabet[j]!=str[i])
             j++;         
         strcpy(code+len,hc[j]); //����Ӧ��ĸ��Huffman���븴�Ƶ�codeָ��λ�� 
         len=len+strlen(hc[j]); //�ۼ��ַ������� 
         i++;
     }
     code[len]='\0';
}

void Decode(HuffmanTree *ht,int m,char *code,char *alphabet,char *decode)
//��һ��Huffman������ɵ��ַ���ת��Ϊ�����ַ��� 
//htΪHuffman������,mΪ�ַ�����,alphabetΪ��Ӧ����ĸ��,strΪ��Ҫת�����ַ���,decode����ת���Ľ�� 
{
     int position=0,i,j=0;
     m=2*m-1;
     while(code[position]) //�ַ���δ���� 
     {
          for(i=m;ht[i].left && ht[i].right; position++) //��Huffman���в�����������Ϊ�� ���Թ���һ��Huffman���� 
          {
              if(code[position]=='0') //����λΪ0 
                  i=ht[i].left; //���������� 
              else //����λΪ 1 
                  i=ht[i].right; //���������� 
          }
          decode[j]=alphabet[i-1]; //�õ�һ����ĸ
          j++;//������һ�ַ� 
     }  
     decode[j]='\0'; //�ַ�����β 
}
int main()
{
    int i,n=4,m; 
    char test[]="DBDBDABDCDADBDADBDADACDBDBD";
    char code[100],code1[100];
    char alphabet[]={'A','B','C','D'}; //4���ַ�
    int w[]={5,7,2,13} ;//4���ַ���Ȩ�� 
    HuffmanTree *ht;
    HuffmanCode *hc;    
    m=2*n-1;    
    ht=(HuffmanTree *)malloc((m+1)*sizeof(HuffmanTree)); //�����ڴ棬����շ����� 
    if(!ht)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(0);    
    }
    hc=(HuffmanCode *)malloc(n*sizeof(char*));
    if(!hc)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(0);    
    }
    
    CreateTree(ht,n,w); //�����շ����� 
    HuffmanCoding(ht,n,hc); //���ݺշ��������ɺշ������� 
    for(i=1;i<=n;i++) //ѭ������շ������� 
        printf("��ĸ:%c,Ȩ��:%d,����Ϊ %s\n",alphabet[i-1],ht[i].weight,hc[i-1]);
    
    Encode(hc,alphabet,test,code); //���ݺշ����������ɱ����ַ��� 
    printf("\n�ַ���:\n%s\nת����Ϊ:\n%s\n",test,code); 
    
    Decode(ht,n,code,alphabet,code1); //���ݱ����ַ������ɽ������ַ��� 
    printf("\n����:\n%s\nת����Ϊ:\n%s\n",code,code1); 
    getch();
    return 0;
}

