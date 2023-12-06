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

//中序遍历的非递归算法
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

//层次遍历
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

//链式二叉树的创建
BiTree CreaBiTree()
{
	int in;
	char ch;
	printf("请输入关键字项和其他数据域,输入-1关键字表示空节点\n");
	scanf("%d,%c", &in, &ch);

	//如果输入-1，表示空节点
	if (in == -1)
	{
		return NULL;
	}

	//创建当前节点
	BiTree node = (BiTree)malloc(sizeof(BiNode));
	node->data.key = in;
	node->data.otherinfo = ch;

	//递归构建左子树和右子树
	printf("为节点%d构建左子树：\n", in);
	node->lchild = CreaBiTree();
	printf("为节点%d构建右子树：\n", in);
	node->rchild = CreaBiTree();
	return node;
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


//计算深度
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

//计算二叉树的节点数
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


//计算叶子节点数
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
