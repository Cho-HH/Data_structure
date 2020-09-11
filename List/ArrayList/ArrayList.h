#pragma once
#include "Point.h"

enum { TRUE = 1, FALSE = 0, LIST_LEN = 100 };
typedef Point* LData;

struct ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPos;
};

typedef ArrayList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData*pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

