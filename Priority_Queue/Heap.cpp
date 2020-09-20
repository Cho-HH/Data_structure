#include "Heap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->comp = pc;
	ph->numOfData = 0;
}

int IsEmpty(Heap * ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	//부모 인덱스는 자식인덱스 /2
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return idx * 2 + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	//두 개의 자식노드 중 높은 우선순위의
	//자식노드 인덱스값 반환
	if (GetLChildIDX(idx) > ph->numOfData) 
		//자식노드가 없으면
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		//자식노드가 왼쪽에 하나있으면
		return GetLChildIDX(idx);
	else
		//자식노드가 둘 다 있으면
	{
		//오른쪽 자식노드의 우선순위가 높다면(값이 작다면)
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void Insert(Heap * ph, Data data)
{
	int idx = ph->numOfData + 1;

	while(idx!=1)
	{
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData++;
}

Data Delete(Heap * ph)
{
	Data retData = (ph->heapArr[1]); //우선순위가 가장 높은 루트노드 저장(삭제를 위해)
	Data lastElem = ph->heapArr[ph->numOfData];

	int parentidx = 1;
	int childidx;

	while (childidx = GetHiPriChildIDX(ph, parentidx))
	{
		if (ph->comp(lastElem, ph->heapArr[childidx]) >= 0)
			break;

		//비교대상노드의 위치를 한 레벨 올림
		ph->heapArr[parentidx] = ph->heapArr[childidx];
		//마지막노드가 저장될 위치정보를 한 레벨 내림
		parentidx = childidx;
	}

	ph->heapArr[parentidx] = lastElem;
	ph->numOfData--;
	return retData;
}

//main함수에 정의되어야 함
//HeapInit(&heap,DataPriorityComp);
int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}