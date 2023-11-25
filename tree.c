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
		visit(T);//访问根节点
		PreOrderTraverse(T->lchild);//递归遍历左子树
		PreOrderTraverse(T->rchild);//递归遍历右子树
	}
}
int InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK;
	else
	{		
		PreOrderTraverse(T->lchild);//递归遍历左子树
		visit(T);//访问根节点
		PreOrderTraverse(T->rchild);//递归遍历右子树
	}
}
int PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return OK;
	else
	{
		PreOrderTraverse(T->lchild);//递归遍历左子树
		PreOrderTraverse(T->rchild);//递归遍历右子树
		visit(T);//访问根节点
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
	LinkQueue pq;//初始化队列
	InitSqQueue(&pq);//初始化队列
	QueuePush(&pq, b);//根节点指针进入队列
	while (QueueEmpty(pq))//队列不等于空，则循环
	{
		QueuePop(&pq, p);//出队节点p
		printf("%c", p->data);//访问数据
		if (p->lchild != NULL)//如果p的左孩子不等于空，入队
		{
			QueuePush(&pq, p->lchild);
		}
		if (p->rchild != NULL)//如果右孩子不等于空，入队
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
		CreaBiTree((*T)->lchild);//构造左子树
		CreaBiTree((*T)->rchild);//构造右子树
	}
	return OK;
}

//复制二叉树
int Copy(BiTree T, BiTree* newT)
{
	if (T == NULL)
	{
		*newT = NULL;
	}
	else
	{
		//如果根节点不为空的话，就要进行复制，首先开辟一个新的空间
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
