#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef BiTree SELemtype;
#define OK 1
#define ERROR 0
/*
ջ��˳��洢��˳��ջ
ջ������洢������ջ
*/

//ջ��˳��洢
typedef struct
{
	SELemtype* base;//ջ��
	SELemtype* top;//ջ����Ϊ�˷��㣬ͨ��topָ��������ջ������һ��������ջ������
	SELemtype stacksize;//ջ�Ĵ�С
}SqStack;

int InitSqStack(SqStack *s);

int DestorySqStack(SqStack* s);

int SqStackLength(SqStack s);

SELemtype GetSqStackTop(SqStack s);

void ClearSqStack(SqStack* s);

int push(SqStack *s, SELemtype e);
//��ջ��ֵ������e��

int pop(SqStack *s, SELemtype *e);

void PrintStack(SqStack s);

int Stackempty(SqStack s);







