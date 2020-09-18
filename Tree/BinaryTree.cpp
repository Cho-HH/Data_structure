#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

BTreeNode * MakeBTreeNode()
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

Data GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, Data data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != nullptr)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != nullptr)
		free(main->right);

	main->right = sub;
}

void InorderTraverse(BTreeNode * bt)
{
	if (bt == nullptr)
		return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode * bt)
{
	if (bt == nullptr)
		return;

	printf("%d \n", bt->data);
	InorderTraverse(bt->left);
	InorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode * bt)
{
	if (bt == nullptr)
		return;

	InorderTraverse(bt->left);
	InorderTraverse(bt->right);
	printf("%d \n", bt->data);
}

void DeleteTree(BTreeNode * bt)
{
	if (bt == nullptr)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);
	free(bt);
}
