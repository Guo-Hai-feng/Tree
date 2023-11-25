#include"stack.h"
int InitSqStack(SqStack *s)
{
	//����һ����ջ�����ݴ���ڶ�������Ҫ�ͷſռ�
	s->base = (SELemtype*)malloc(size * sizeof(SELemtype));

	//��ʼ��ʧ�ܣ�����
	if (!s->base)  exit(-2);

	//ջ������ջ��
	s->top = s->base;
	s->stacksize = size;

	return OK;
}


int push(SqStack* s, SELemtype e)
{
	//�Ƿ�ջ�Ѿ�����
	if (s->top - s->base == s->stacksize)
	{
		printf("ջ����\n");
		return ERROR;
	}
	//����Ԫ��ΪE����ջ��Ԫ�� 
	*s->top++ = e;
	return OK;
}


int pop(SqStack* s, SELemtype* e)
{
	//��ջ���գ�ɾ��ջ��Ԫ�أ���e������ֵ ,���򷵻�ERROR 
	if (s->top == s->base)
	{
		printf("ջ����\n");
		return ERROR;
	}
	s->top = s->top--;
	*e = *s->top;
	return OK;
}


SELemtype GetSqStackTop(SqStack s)
{
	//��ջ���գ�����e����ջ��Ԫ��
	if (s.top == s.base)
		return -2;

	return *(s.top);
}
//��ջsΪ��ջ���򷵻�TRUE,���򷵻�FALSE�� status Stackempty(SqStack s)
int Stackempty(SqStack s)
{
	if (s.top == s.base)
	{
		return OK;
	}
	else
		return ERROR;
}

int SqStackLength(SqStack s)
{
	return s.top - s.base;
}

void ClearSqStack(SqStack* s)
{
	s->top = s->top;
}

int DestorySqStack(SqStack* s)
{
	if (s->base)
	{
		//�ͷſռ�
		free(s->base);	
		s->base = NULL;
		s->top = NULL;
	}
	s->stacksize = 0;
	return OK;
}

void PrintStack(SqStack s)
{
	SELemtype* pstr = s.base;
	while (pstr != s.top)
	{
		printf("%c", *pstr);
	}

}
