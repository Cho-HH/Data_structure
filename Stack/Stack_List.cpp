#include "Stack_List.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack * pstack)
{
	pstack->head = nullptr;
}

int IsEmpty(Stack * pstack)
{
	if (pstack->head = nullptr)
		return TRUE;
	else
		return FALSE;
}

void Push(Stack * pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (IsEmpty(pstack))
	{
		newNode->nextNode = nullptr;
		pstack->head = newNode;
	}
	else
	{
		newNode->nextNode = pstack->head;
		pstack->head = newNode;
	}
}

Data Pop(Stack * pstack)
{
	if (IsEmpty(pstack))
	{
		printf("Stack Memory Error");
		exit(-1);
	}

	Data data = pstack->head->data;
	Node* node = pstack->head;
	
	pstack->head = pstack->head->nextNode;
	free(node);

	return data;
}

Data Peek(Stack * pstack)
{
	if (IsEmpty(pstack))
	{
		printf("Stack Memory Error");
		exit(-1);
	}

	return pstack->head->data;
}
