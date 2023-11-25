#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#define MAXQSIZE 100
typedef  BiTree QDataType;
#define OK 1
#define ERROR 0

//链式队列
//头节点不保存数据！！！
typedef struct Qnode
{
	struct Qnode* next;//链表实现列表
	QDataType data;//存储的数据
}QueueNode, * QuenePtr;

typedef struct Queue
{
	QuenePtr head;//定义头
	QuenePtr tail;//定义尾
}LinkQueue;

void QueueInit(LinkQueue* pq);
void Queuedestroy(LinkQueue* pq);
void QueuePush(LinkQueue* pq, QDataType x);
int QueuePop(LinkQueue* pq, QDataType* x);
QDataType QueueFront(LinkQueue pq, QDataType* x);

int QueueEmpty(LinkQueue pq);


