#include"Queue.h"

void QueueInit(LinkQueue *pq)
{
	LinkQueue temp;

	//ͷ�ڵ㲢���洢��Ϣ
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
	//����һ���µĿռ�
	QuenePtr newnode = (QuenePtr)malloc(sizeof(QueueNode));

	newnode->data = x;
	newnode->next = NULL;

	//β�ڵ�ָ�����һ��
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