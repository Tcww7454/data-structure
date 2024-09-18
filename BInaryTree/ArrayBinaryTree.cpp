#include "ArrayBinaryTree.h"

void ArrayBinaryTree::insert(int value)
{
	if (tree[0] == -1) {
		tree[0] = value;
		return;
	}
	else{
		insertAt(0, value);
	}
}

void ArrayBinaryTree::preorder()
{
	preorder(0);
}

void ArrayBinaryTree::inorder()
{
	inorder(0);
}

void ArrayBinaryTree::posorder()
{
	posorder(0);
}

void ArrayBinaryTree::insertAt(int index, int value)
{
	if (tree[index] == -1) {
		tree[index] = value;
	}
	else if (value < tree[index]) {
		insertAt(2 * index + 1, value);
	}
	else
		insertAt(2 * index + 2, value);
}

void ArrayBinaryTree::preorder(int index)
{
	if (index >= tree.size() || tree[index] == -1)
		return;
	cout << tree[index] << " ";
	preorder(2 * index + 1);
	preorder(2 * index + 2);

}

void ArrayBinaryTree::inorder(int index)
{
	if (index >= tree.size() || tree[index] == -1)
		return;
	preorder(2 * index + 1);
	cout << tree[index] << " ";
	preorder(2 * index + 2);
}

void ArrayBinaryTree::posorder(int index)
{
	if (index >= tree.size() || tree[index] == -1)
		return;
	preorder(2 * index + 1);
	preorder(2 * index + 2);
	cout << tree[index] << " ";
}
