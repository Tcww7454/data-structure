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

void LinkedListBinaryTree::levelorder()
{
	queue<Node*> nodeQueue;

	if (root != nullptr)
		nodeQueue.push(root);
	else
		return;

	while (!nodeQueue.empty()) {
		int size = nodeQueue.size();
		for (int i = 0; i < size; ++i) {
			Node* front = nodeQueue.front();
			nodeQueue.pop();
			if (front->left != nullptr) {
				nodeQueue.push(front->left);
			}
			if (front->right != nullptr) {
				nodeQueue.push(front->right);
			}
			cout << front->value << " ";
		}
		cout << endl;
	}
}

void LinkedListBinaryTree::removeElement(int val)
{
}

