#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = nullptr;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode* pNode = nullptr; //부모 노드
	BTreeNode* cNode = nullptr;//현재 노드
	BTreeNode* nNode = nullptr;//new 노드

	while (cNode != nullptr)
	{
		if (data == GetData(cNode))//데이터중복 X
			return;

		pNode = cNode; //현재 노드의 부모노드를 저장
		//실제 노드의 저장위치를 파악하기 위함

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != nullptr)
		//새 노드가 루트노드가 아닐 경우
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, cNode);
		else
			MakeRightSubTree(pNode, cNode);
	}
	else
		*pRoot = nNode; //루트노드지정
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode* cNode = bst;
	BSTData cd;

	while (cNode != nullptr)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return nullptr;
}
