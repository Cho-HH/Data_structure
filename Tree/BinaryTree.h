#pragma once

typedef int Data;

struct BTreeNode
{
	Data data;
	BTreeNode* left;
	BTreeNode* right;
};

BTreeNode* MakeBTreeNode();
Data GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, Data data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
 
//루트노드 기준
void InorderTraverse(BTreeNode* bt); //중위 순회
void PreorderTraverse(BTreeNode* bt); //전위
void PostorderTraverse(BTreeNode* bt); //후위

void DeleteTree(BTreeNode* bt);