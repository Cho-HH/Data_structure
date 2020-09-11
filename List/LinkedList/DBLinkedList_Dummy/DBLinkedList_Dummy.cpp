#include "DBLinkedList_Dummy.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist) 
{
	plist->cur = nullptr;
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->head->nextNode = plist->tail;
	plist->head->prevNode = nullptr;
	plist->tail->prevNode = plist->head;
	plist->tail->nextNode = nullptr;
	plist->numOfData = 0;

}

void LInsert(List* plist, Data data)
//tail이 추가되었으니 꼬리에 새 데이더 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->nextNode = plist->tail;
	plist->tail->prevNode = newNode;
	newNode->prevNode = plist->tail->prevNode;
	plist->tail->prevNode->nextNode = newNode;
	
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head->nextNode == plist->tail)
		return FALSE;

	plist->cur = plist->head->nextNode;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Data* pdata)
{
	if (plist->head->nextNode == plist->tail)
		return FALSE;

	plist->cur = plist->cur->nextNode;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrev(List* plist, Data* pdata)
{
	if (plist->head->nextNode == plist->tail)
		return FALSE;

	plist->cur = plist->cur->prevNode;
	*pdata = plist->cur->data;
	return TRUE;
}

void LRemove(List* plist) //cur Node 삭제
{
	Node* rpos = plist->cur;
	
	rpos->prevNode->nextNode = rpos->nextNode;
	rpos->nextNode->prevNode = rpos->prevNode;
	plist->cur = plist->cur->prevNode;

	free(rpos);
	(plist->numOfData)--;
}

int LCount(const List* plist)
{
	return plist->numOfData;
}