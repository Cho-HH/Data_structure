#pragma once

enum { TRUE = 1, FALSE = 0 };

typedef int LData;

struct Node
{
	int data;
	Node* nextNode;
};

struct CLinkedList
{
	Node* cur;
	Node* tail;
	Node* before;
	int numOfData;
};

typedef CLinkedList List;

void ListInit(List* plist);
void ListInsert(List* plist, LData data); //������ ��带 �߰�
void ListInsertFront(List* plist, LData data); //�Ӹ��� ��带 �߰�

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);
