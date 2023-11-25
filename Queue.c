#include"Queue.h"

void QueueInit(LinkQueue *pq)
{
	LinkQueue temp;

	//头节点并不存储信息
	temp.head = (QuenePtr)malloc(sizeof(QueueNode));

	temp.tail = temp.head;
	temp.tail->next = NULL;
	*pq = temp;
}


void Queuedestroy(LinkQueue* pq)
{
	QuenePtr temp = NULL;
	while (pq->head)
	{
		temp = pq->head->next;
		free(pq->head);
		pq->head = temp;
	}
}


void QueuePush(LinkQueue *pq, QDataType x)
{
	//开辟一个新的空间
	QuenePtr newnode = (QuenePtr)malloc(sizeof(QueueNode));

	newnode->data = x;
	newnode->next = NULL;

	//尾节点指向最后一个
	pq->tail->next = newnode;
	pq->tail = newnode;

}
int QueuePop(LinkQueue* pq,QDataType* x)
{
	if (pq->head == pq->tail)
		return ERROR;
	
	QuenePtr next = pq->head->next;
	*x = next->data;
	pq->head->next = next->next;
	if (pq->tail == next)
		pq->tail = pq->head;

	free(next);

	return OK;


}
int QueueFront(LinkQueue pq,QDataType*x)
{
	if (pq.head == pq.tail)
		return ERROR;
	*x = pq.head->data;
}
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail -> data;
//
//}
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	int n = 0;
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		++n;
//		cur = cur->next;
//	}
//	return n;
//}

int QueueEmpty(LinkQueue pq)
{
	if (pq.head == NULL)
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}