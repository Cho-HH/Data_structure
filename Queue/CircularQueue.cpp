#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int IsEmpty(Queue * pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
	if (IsEmpty(pq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
	if (IsEmpty(pq))
	{
		printf("Queue Memory Error");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1) //배열의 마지막 요소의 인덱스
		return 0;
	else
		return pos + 1;

}