#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100
#include<stdio.h>
#include<malloc.h>
#include<math.h>
/*
* ��������˳��洢��������ȫ�������Ĵ洢�ṹ����ţ�Ȼ��洢��������
*/
#define MAXSIZE 100
typedef char Type;
typedef Type SqBiTree[MAXSIZE];//��������,�ֶ���һ����������



/*����������ʽ�洢*/
typedef struct BiNode
{
	Type data;
	struct BiNode* lchild, * rchild;//���Һ���ָ��

}BiNode,*BiTree;



//��ʽ�������������
int PreOrderTraverse(BiTree T);
int visit(BiTree T);

//��ʽ�������������
int InOrderTraverse(BiTree T);

//��ʽ�������������
int PostOrderTraverse(BiTree T);


//��������ķǵݹ����
int InOrderStackTraverse(BiTree T);
void LevelOrder(BiNode* b);
//������
BiTree CreaBiTree();
//���ƶ�����
int Copy(BiTree T, BiTree* newT);

//�������
int Depth(BiTree T);

//�ڵ���
int NodeCount(BiTree T);

//Ҷ�ӽڵ���
int LeadCount(BiTree T);
