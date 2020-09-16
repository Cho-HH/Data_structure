#pragma once

enum 
{
	TRUE = 1,
	FALSE=0,
	QUE_LEN=100
};

typedef int Data;

struct CQueue
{
	int front;
	int rear; //²¿¸®
	Data queArr[QUE_LEN];
};

typedef CQueue Queue;

void QInit(Queue* pq);
int IsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);
