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

Node* LinkedListBinaryTree::searchBSTHelper(Node* node, int val)
{
	if (node == nullptr || node->value == val)
		return node;
	if (val > node->value) {
		return searchBSTHelper(node->right, val);
	}
	return searchBSTHelper(node->left, val);
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

Node* LinkedListBinaryTree::searchBST(int val)
{
	return searchBSTHelper(root, val);
}

void LinkedListBinaryTree::removeElement(int val)
{
	// ��ȡHibbard ɾ��
	Node* node = searchBST(val);
	if (node == nullptr) return;

	// ���Ҹ��ڵ�
	Node* parent = nullptr;
	Node* current = root;
	while (current != nullptr && current->value != val){
		parent = current;
		if (val < current->value) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	// ��һ����� : ΪҶ�ڵ�

	if (node->left == nullptr && node->right == nullptr) {
		if (parent == nullptr) {
			root = nullptr;
		}
		else if (parent->left == node) {
			parent->left = nullptr;
		}
		else {
			parent->right = nullptr;
		}
		delete node;
		return;
	}

	// �ڶ������ : ���Һ��Ӷ�����
	if (node->left != nullptr && node->right != nullptr) {
		//���ҵ������������ұߵĽڵ�
		Node* rightestNode = node->left;
		Node* rightestNodeParent = node;
		while (rightestNode->right != nullptr) {
			rightestNodeParent = rightestNode;
			rightestNode = rightestNode->right;
		}
		node->value = rightestNode->value;
		// �������ұ߽ڵ�ĸ��ڵ�ָ��
		if (rightestNodeParent->right == rightestNode) {
			rightestNodeParent->right = rightestNode->left;
		}
		else {
			rightestNodeParent->left = rightestNode->left; 
		}
		delete rightestNode;
		return;
	}
	// ��������� : ֻ�������ӻ����Һ���
	Node* child = (node->left != nullptr) ? node->left : node->right;
	if (parent == nullptr) {
		// Ҫɾ�����Ǹ��ڵ���ֻ��һ������
		root = child;
	}
	else if (parent->left == node) {
		parent->left = child;
	}
	else {
		parent->right = child;
	}
	delete node;
}

