#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef BiTree SELemtype;
#define OK 1
#define ERROR 0
/*
栈的顺序存储：顺序栈
栈的链序存储：链序栈
*/

//栈的顺序存储
typedef struct
{
	SELemtype* base;//栈底
	SELemtype* top;//栈顶，为了方便，通常top指向真正的栈顶的上一个，方便栈的运算
	SELemtype stacksize;//栈的大小
}SqStack;

int InitSqStack(SqStack *s);

int DestorySqStack(SqStack* s);

int SqStackLength(SqStack s);

SELemtype GetSqStackTop(SqStack s);

void ClearSqStack(SqStack* s);

int push(SqStack *s, SELemtype e);
//出栈的值保存在e中

int pop(SqStack *s, SELemtype *e);

void PrintStack(SqStack s);

int Stackempty(SqStack s);







