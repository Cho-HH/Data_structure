#pragma once

enum
{
	TRUE = 1,
	FALSE = 0
};

typedef int Data;

struct Node
{
	Data data;
	Node* nextNode;
	Node* prevNode;
};

struct Deque
{
	Node* head;
	Node* tail;
};

void QInit(Deque* pq);
int IsEmpty(Deque* pq);

void DQAddFirst(Deque* deq, Data data);
void DQAddLast(Deque* deq, Data data);

Data DQRemoveFirst(Deque* deq);
Data DQRemoveLast(Deque* deq);

Data DQGetFirst(Deque* deq);
Data DQGetLast(Deque* deq);
