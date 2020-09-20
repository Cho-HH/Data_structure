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
	//�θ� �ε����� �ڽ��ε��� /2
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
	//�� ���� �ڽĳ�� �� ���� �켱������
	//�ڽĳ�� �ε����� ��ȯ
	if (GetLChildIDX(idx) > ph->numOfData) 
		//�ڽĳ�尡 ������
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		//�ڽĳ�尡 ���ʿ� �ϳ�������
		return GetLChildIDX(idx);
	else
		//�ڽĳ�尡 �� �� ������
	{
		//������ �ڽĳ���� �켱������ ���ٸ�(���� �۴ٸ�)
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
	Data retData = (ph->heapArr[1]); //�켱������ ���� ���� ��Ʈ��� ����(������ ����)
	Data lastElem = ph->heapArr[ph->numOfData];

	int parentidx = 1;
	int childidx;

	while (childidx = GetHiPriChildIDX(ph, parentidx))
	{
		if (ph->comp(lastElem, ph->heapArr[childidx]) >= 0)
			break;

		//�񱳴������ ��ġ�� �� ���� �ø�
		ph->heapArr[parentidx] = ph->heapArr[childidx];
		//��������尡 ����� ��ġ������ �� ���� ����
		parentidx = childidx;
	}

	ph->heapArr[parentidx] = lastElem;
	ph->numOfData--;
	return retData;
}

//main�Լ��� ���ǵǾ�� ��
//HeapInit(&heap,DataPriorityComp);
int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}