#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#define MAXSIZE 100
typedef char Type;

//��������
typedef struct TriNode
{
	Type data;
	struct TriNode* lchild, * rchild, * parent;//������ǰ��
}TriNode, * TriTree;



//����������
/*����������ʽ�洢*/
typedef struct BiThrNode
{
	Type data;
	int ltag, rtag;//��־��
	struct BiNode* lchild, * rchild;//���Һ���ָ��

}BiThrNode, * BiThrTree;



//˫�ױ�ʾ��
typedef struct PTNode
{
	Type data;
	int parent;//˫��λ����
}PTNode;

typedef struct
{
	PTNode node[MAX_TREE_SIZE];
	int r, n;//���ڵ��λ�úͽڵ����
}Ptree;



//��������
//���ӽṹ��child|next
//˫�׽ڵ�ṹ��data|firstchild
typedef struct CTNode
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct
{
	Type data;
	ChildPtr firstchild;//��������ͷָ��
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
}CTree;



//�����ֵܱ�ʾ��
typedef struct CSNode
{
	Type data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTtree;
