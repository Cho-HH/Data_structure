#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); //���̵�����
	plist->before = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->nextNode = plist->head->nextNode;
	plist->head->nextNode = newNode;
}

void SInsert(List* plist, LData data) //�����Ͱ� ���ĵǾ� �ִٸ�
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head; //���̳��
	newNode->data = data;

	while (pred->nextNode != NULL && plist->comp(data, pred->nextNode->data) != 0)
		pred = pred->nextNode;

	newNode->nextNode = pred->nextNode;
	pred->nextNode = newNode;

	(plist->numOfData)++;
}

void ListInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);

}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->nextNode == NULL)
		return FALSE;

	plist->before = plist->head; //���̳��
	plist->cur = plist->head->nextNode; //ù��° ���

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->head->nextNode == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->nextNode;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->nextNode = plist->cur->nextNode;
	//before�� �ִ� ������ �� �������θ� ����� List����
	//cur�� before�� �̵���Ű�� ����
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}
