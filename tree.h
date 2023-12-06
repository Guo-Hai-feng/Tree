#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100
#include<stdio.h>
#include<malloc.h>
#include<math.h>
/*
* 二叉树的顺序存储，按照完全二叉树的存储结构，编号，然后存储在数组中
*/
#define MAXSIZE 100
typedef char Type;
typedef Type SqBiTree[MAXSIZE];//定义数组,现定义一个整型数组



/*二叉树的链式存储*/
typedef struct BiNode
{
	Type data;
	struct BiNode* lchild, * rchild;//左右孩子指针

}BiNode,*BiTree;



//链式二叉树先序遍历
int PreOrderTraverse(BiTree T);
int visit(BiTree T);

//链式二叉树中序遍历
int InOrderTraverse(BiTree T);

//链式二叉树后序遍历
int PostOrderTraverse(BiTree T);


//中序遍历的非递归操作
int InOrderStackTraverse(BiTree T);
void LevelOrder(BiNode* b);
//先序建立
BiTree CreaBiTree();
//复制二叉树
int Copy(BiTree T, BiTree* newT);

//计算深度
int Depth(BiTree T);

//节点数
int NodeCount(BiTree T);

//叶子节点数
int LeadCount(BiTree T);
