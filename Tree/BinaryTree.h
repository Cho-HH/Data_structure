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
 
//��Ʈ��� ����
void InorderTraverse(BTreeNode* bt); //���� ��ȸ
void PreorderTraverse(BTreeNode* bt); //����
void PostorderTraverse(BTreeNode* bt); //����

void DeleteTree(BTreeNode* bt);