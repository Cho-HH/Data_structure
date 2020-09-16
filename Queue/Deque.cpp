#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

void QInit(Deque * pq)
{
	pq->head = nullptr;
	pq->tail = nullptr;
}

int IsEmpty(Deque * pq)
{
	if (pq->head == nullptr)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque * deq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (IsEmpty(deq))
	{
		deq->tail = newNode;
		deq->head->prevNode = nullptr;
		deq->head->nextNode = nullptr;
		deq->tail->nextNode = nullptr;
		deq->tail->prevNode = nullptr;
		newNode->nextNode = nullptr;
	}
	else
	{
		newNode->nextNode = deq->head;
		deq->head->prevNode = newNode;	
	}

	newNode->prevNode = nullptr;
	deq->head = newNode;
}

void DQAddLast(Deque * deq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (IsEmpty(deq))
	{
		deq->head = newNode;
		deq->head->prevNode = nullptr;
		deq->head->nextNode = nullptr;
		deq->tail->nextNode = nullptr;
		deq->tail->prevNode = nullptr;
		newNode->prevNode = deq->tail;
	}
	else
	{
		newNode->prevNode = deq->tail;
		deq->tail->nextNode = newNode;
	}

	newNode->nextNode = nullptr;
	deq->tail = newNode;
}

Data DQRemoveFirst(Deque * deq)
{
	Node* rnode = deq->head;
	Data rdata = deq->head->data;
	if (IsEmpty(deq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	deq->head = deq->head->nextNode;
	free(rnode);

	if (deq->head == nullptr)
		deq->tail = nullptr;
	else
		deq->head->prevNode= nullptr;

	return rdata;
}

Data DQRemoveLast(Deque * deq)
{
	Node* rnode = deq->tail;
	Data rdata = deq->tail->data;
	if (IsEmpty(deq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	deq->tail = deq->tail->prevNode;
	free(rnode);

	if (deq->tail == nullptr)
		deq->head = nullptr;
	else
		deq->tail->nextNode = nullptr;

	return rdata;
}

Data DQGetFirst(Deque * deq)
{
	return deq->head->data;
}

Data DQGetLast(Deque * deq)
{
	return deq->tail->data;
}

