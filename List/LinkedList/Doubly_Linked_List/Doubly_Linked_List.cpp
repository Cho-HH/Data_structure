#include "Doubly_Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist)
{
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{ //리스트의 머리에 추가
	//꼬리에 추가할 경우, 마지막노드를 가라키기 복잡
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (plist->head != NULL)
		plist->head->prevNode = newNode;
	
	newNode->prevNode = NULL;
	newNode->nextNode = plist->head;
	plist->head = newNode;

	(plist->numOfData)++ ;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;//굳이..?
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->cur->nextNode;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrev(List * plist, Data * pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->cur->prevNode;
	*pdata = plist->cur->data;
	return TRUE;
}

int LCount(const List* plist)
{
	return plist->numOfData;
}