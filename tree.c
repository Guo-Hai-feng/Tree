#define _CRT_SECURE_NO_WARNINGS
#include"tree.h"
#include"stack.h"
#include"Queue.h"

int visit(BiTree T)
{
	printf("%d", T->data);
}

int PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK;
	else
	{
		visit(T);//���ʸ��ڵ�
		PreOrderTraverse(T->lchild);//�ݹ����������
		PreOrderTraverse(T->rchild);//�ݹ����������
	}
}
int InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK;
	else
	{		
		PreOrderTraverse(T->lchild);//�ݹ����������
		visit(T);//���ʸ��ڵ�
		PreOrderTraverse(T->rchild);//�ݹ����������
	}
}
int PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK;
	else
	{
		PreOrderTraverse(T->lchild);//�ݹ����������
		PreOrderTraverse(T->rchild);//�ݹ����������
		visit(T);//���ʸ��ڵ�
	}
}

int InOrderStackTraverse(BiTree T)
{
	BiTree p, q;
	SqStack S;
	InitSqStack(&S);
	p = T;
	while (p || Stackempty(S))
	{
		if (p)
		{
			push(&S, q);
			p = p->lchild;
		}
		else
		{
			pop(&S, q);
			printf("%c", q->data);
			p = q->rchild;
		}
	}
	return OK;
}
void LevelOrder(BiNode* b)
{
	BiNode* p;
	LinkQueue pq;//��ʼ������
	InitSqQueue(&pq);//��ʼ������
	QueuePush(&pq, b);//���ڵ�ָ��������
	while (QueueEmpty(pq))//���в����ڿգ���ѭ��
	{
		QueuePop(&pq, p);//���ӽڵ�p
		printf("%c", p->data);//��������
		if (p->lchild != NULL)//���p�����Ӳ����ڿգ����
		{
			QueuePush(&pq, p->lchild);
		}
		if (p->rchild != NULL)//����Һ��Ӳ����ڿգ����
		{
			QueuePush(&pq, p->rchild);
		}
	}
}

int CreaBiTree(BiTree* T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiNode))))
		{
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		CreaBiTree((*T)->lchild);//����������
		CreaBiTree((*T)->rchild);//����������
	}
	return OK;
}

//���ƶ�����
int Copy(BiTree T, BiTree* newT)
{
	if (T == NULL)
	{
		*newT = NULL;
	}
	else
	{
		//������ڵ㲻Ϊ�յĻ�����Ҫ���и��ƣ����ȿ���һ���µĿռ�
		(*newT) = (BiTree)malloc(sizeof(BiNode));
		(*newT)->data = T->data;
		Copy(T->lchild, &(*newT)->lchild);//
		Copy(T->lchild, &(*newT)->rchild);

	}
}

int Depth(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		return m > n ? m + 1 : n + 1;
	}
}

int NodeCount(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int m = NodeCount(T->lchild);
		int n = NodeCount(T->rchild);
		return m + n + 1;
	}
}

int LeadCount(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int m = LeadCount(T->lchild);
		int n = LeadCount(T->rchild);
		return m + n;
	}
}