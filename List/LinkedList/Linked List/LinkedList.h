#pragma once

enum { TRUE = 1, FALSE = 0 };

typedef int LData;

struct Node
{
	int data;
	Node* nextNode;
};

struct LinkedList
{
	Node* cur;
	Node* head;
	Node* before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
};

typedef LinkedList List;

void ListInit(List* plist);
void ListInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));
