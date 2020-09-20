#pragma once

enum
{
	TRUE = 1,
	FALSE = 0,
	HEAP_LEN = 100
};

typedef char Data;
typedef int(*PriorityComp)(Data, Data);

struct Heap
{
	PriorityComp comp;
	int numOfData;
	Data heapArr[HEAP_LEN];
};

void HeapInit(Heap* ph, PriorityComp pc);
int IsEmpty(Heap* ph);

void Insert(Heap* ph, Data data);
Data Delete(Heap* ph);
