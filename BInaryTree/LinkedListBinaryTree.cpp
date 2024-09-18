#include "LinkedListBinaryTree.h"

void LinkedListBinaryTree::preorder(Node* node)
{
	if (node == nullptr) return;
	cout << node->value << " ";
	preorder(node->left);
	preorder(node->right);
}

void LinkedListBinaryTree::inorder(Node* node)
{
	if (node == nullptr) return;
	inorder(node->left);
	cout << node->value << " ";
	inorder(node->right);
}

void LinkedListBinaryTree::posorder(Node* node)
{
	if (node == nullptr) return;
	posorder(node->left);
	posorder(node->right);
	cout << node->value << " ";
}

Node* LinkedListBinaryTree::insert(Node* node, int val)
{
	if (node == nullptr)
		return new Node(val);
	if (val > node->value) 
		node->right = insert(node->right, val);
	else 
		node->left = insert(node->left, val);
	return node;
}
