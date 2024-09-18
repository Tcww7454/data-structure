#pragma once
#include "BinaryTree.h"

//一般用于表示满二叉树
class ArrayBinaryTree :
    public BinaryTree
{
public:
	ArrayBinaryTree(int size = 127) {
		tree.resize(30, -1); //初始化所有节点为空
	}

	void insert(int value) override;

	void preorder() override;

	void inorder() override;

	void posorder() override;

	void levelorder() override;

	void removeElement(int val)override;
private:
	vector<int> tree;

	void insertAt(int index, int value);

	void preorder(int index);

	void inorder(int index);

	void posorder(int index);
};
