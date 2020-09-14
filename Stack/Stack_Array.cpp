#include "Stack_Array.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

int IsEmpty(Stack * pstack)
{
	if (pstack->topIndex = -1)
		return TRUE;
	else
		return FALSE;
}

void Push(Stack * pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data Pop(Stack * pstack)
{
	if (IsEmpty(pstack))
	{
		printf("Stack Memory Error");
		exit(-1);
	}

	int Idx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[Idx];
}

Data Peek(Stack * pstack)
{
	if (IsEmpty(pstack))
	{
		printf("Stack Memory Error");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
