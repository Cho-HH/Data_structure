#pragma once

enum { TRUE = 1, FALSE = 0 };

typedef int Data;

struct Node
{
	Data data;
	Node* nextNode;
	Node* prevNode;
};

struct DBLinkedList
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
};

typedef DBLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrev(List* plist, Data* pdata);

void LRemove(List* plist);
int LCount(const List* plist);
