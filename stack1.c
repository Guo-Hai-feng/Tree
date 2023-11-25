#include"stack.h"
int InitSqStack(SqStack *s)
{
	//构造一个新栈，内容存放在堆区，还要释放空间
	s->base = (SELemtype*)malloc(size * sizeof(SELemtype));

	//初始化失败，报错
	if (!s->base)  exit(-2);

	//栈顶等于栈底
	s->top = s->base;
	s->stacksize = size;

	return OK;
}


int push(SqStack* s, SELemtype e)
{
	//是否栈已经满了
	if (s->top - s->base == s->stacksize)
	{
		printf("栈上溢\n");
		return ERROR;
	}
	//插入元素为E的新栈顶元素 
	*s->top++ = e;
	return OK;
}


int pop(SqStack* s, SELemtype* e)
{
	//若栈不空，删除栈顶元素，用e返回其值 ,否则返回ERROR 
	if (s->top == s->base)
	{
		printf("栈下溢\n");
		return ERROR;
	}
	s->top = s->top--;
	*e = *s->top;
	return OK;
}


SELemtype GetSqStackTop(SqStack s)
{
	//若栈不空，则用e返回栈顶元素
	if (s.top == s.base)
		return -2;

	return *(s.top);
}
//若栈s为空栈，则返回TRUE,否则返回FALSE； status Stackempty(SqStack s)
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
		//释放空间
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
