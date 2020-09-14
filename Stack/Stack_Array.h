#pragma once

enum
{
	TRUE = 1,
	FALSE = 0,
	STACK_LEN = 100
};

typedef int Data;

struct ArrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
};

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int IsEmpty(Stack* pstack);

void Push(Stack* pstack, Data data);
Data Pop(Stack* pstack);
Data Peek(Stack* pstack);

