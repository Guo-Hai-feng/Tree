#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#define MAXSIZE 100
typedef char Type;

//三叉链表
typedef struct TriNode
{
	Type data;
	struct TriNode* lchild, * rchild, * parent;//方便找前驱
}TriNode, * TriTree;



//线索二叉树
/*二叉树的链式存储*/
typedef struct BiThrNode
{
	Type data;
	int ltag, rtag;//标志域
	struct BiNode* lchild, * rchild;//左右孩子指针

}BiThrNode, * BiThrTree;



//双亲表示法
typedef struct PTNode
{
	Type data;
	int parent;//双亲位置域
}PTNode;

typedef struct
{
	PTNode node[MAX_TREE_SIZE];
	int r, n;//根节点的位置和节点个数
}Ptree;



//孩子链表
//孩子结构：child|next
//双亲节点结构：data|firstchild
typedef struct CTNode
{
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct
{
	Type data;
	ChildPtr firstchild;//孩子链表头指针
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
}CTree;



//孩子兄弟表示法
typedef struct CSNode
{
	Type data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTtree;
