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
	BTreeNode* pNode = nullptr; //�θ� ���
	BTreeNode* cNode = nullptr;//���� ���
	BTreeNode* nNode = nullptr;//new ���

	while (cNode != nullptr)
	{
		if (data == GetData(cNode))//�������ߺ� X
			return;

		pNode = cNode; //���� ����� �θ��带 ����
		//���� ����� ������ġ�� �ľ��ϱ� ����

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != nullptr)
		//�� ��尡 ��Ʈ��尡 �ƴ� ���
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, cNode);
		else
			MakeRightSubTree(pNode, cNode);
	}
	else
		*pRoot = nNode; //��Ʈ�������
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
