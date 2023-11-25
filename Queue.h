#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#define MAXQSIZE 100
typedef  BiTree QDataType;
#define OK 1
#define ERROR 0

//��ʽ����
//ͷ�ڵ㲻�������ݣ�����
typedef struct Qnode
{
	struct Qnode* next;//����ʵ���б�
	QDataType data;//�洢������
}QueueNode, * QuenePtr;

typedef struct Queue
{
	QuenePtr head;//����ͷ
	QuenePtr tail;//����β
}LinkQueue;

void QueueInit(LinkQueue* pq);
void Queuedestroy(LinkQueue* pq);
void QueuePush(LinkQueue* pq, QDataType x);
int QueuePop(LinkQueue* pq, QDataType* x);
QDataType QueueFront(LinkQueue pq, QDataType* x);

int QueueEmpty(LinkQueue pq);


