#include "Circular_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->before = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void ListInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->nextNode = newNode;
	}
	else
	{
		newNode->nextNode = plist->tail->nextNode;
		plist->tail->nextNode = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

void ListInsertFront(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) //첫번째 노드
	{
		plist->tail = newNode;
		newNode->nextNode = newNode;
	}
	else
	{
		plist->tail->nextNode = newNode;
		newNode->nextNode = plist->tail->nextNode;
	}

	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->nextNode;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur->nextNode;
	plist->cur = plist->cur->nextNode;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node*rpos = plist->cur;
	LData rdata = rpos->data;
	 
	//1.삭제할 노드가 tail인 경우
	//2.삭제할 노드가 리스트에 홀로 남은 경우
	if (rpos == plist->tail)
	{
		if (plist->tail->nextNode == plist->tail)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->nextNode = plist->cur->nextNode;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}