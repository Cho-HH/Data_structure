#include "ListQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QInit(Queue * pq)
{
	pq->front = nullptr;
	pq->rear = nullptr;
}

int IsEmpty(Queue * pq)
{
	if (pq->front == nullptr)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->nextNode = nullptr;

	if (IsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->nextNode = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue * pq)
{
	Node* delNode;
	Data retData;

	if (IsEmpty(pq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}
	;
	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->nextNode;

	free(delNode);
	return retData;
}

Data QPeek(Queue * pq)
{
	if (IsEmpty(pq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	return pq->front->data;
}