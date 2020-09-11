#include "ArrayList.h"

void ListInit(List * plist)
{
	plist->numOfData = 0;
	plist->curPos = -1;
}

void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("저장 불가");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	plist->curPos = 0;
	*pdata = plist->arr[plist->curPos];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->curPos >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPos)++;
	*pdata = plist->arr[plist->curPos];
	return TRUE;
}

LData LRemove(List * plist)
{
	for (int i = plist->curPos; i < (plist->numOfData) - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPos)--;

	return plist->arr[plist->curPos];
}

int LCount(List * plist)
{
	return plist->numOfData;
}

