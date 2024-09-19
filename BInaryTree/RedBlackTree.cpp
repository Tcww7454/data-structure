#include "RedBlackTree.h"

bool RedBlackTree::isRed(Node* node)
{
    if (node == nullptr) return false; 
    RBTreeNode* tmp = static_cast<RBTreeNode*>(node);
    return tmp->color == RED;
}

RBTreeNode* RedBlackTree::insertHelper(Node* node, int item)
{
    if (node == nullptr)
        return new RBTreeNode(RED, item);

    RBTreeNode* rbNode = static_cast<RBTreeNode*>(node);

    if (item > rbNode->value) {
        rbNode->right = insertHelper(rbNode->right, item);
    }
    else if (item < rbNode->value) {
        rbNode->left = insertHelper(rbNode->left, item);
    }
    else {
        return rbNode; // �������ظ�����
    }

    // �������������
    if (isRed(rbNode->right) && !isRed(rbNode->left))
        rbNode = rotateLeft(rbNode);

    // �������������
    if (isRed(rbNode->left) && isRed(rbNode->left->left))
        rbNode = rotateRight(rbNode);

    // ������ɫ��ת�����
    if (isRed(rbNode->left) && isRed(rbNode->right))
        flipColors(rbNode);

    return rbNode;
}

void RedBlackTree::flipColors(RBTreeNode* node)
{
    node->color = !node->color;

    // node�����Һ��ӽڵ㲻����color���� ����ǿ������ת��
    RBTreeNode* left = static_cast<RBTreeNode*>(node->left);
    RBTreeNode* right = static_cast<RBTreeNode*>(node->right);

    if (left && right) {
        left->color = !left->color;
        right->color = !right->color;
    }
}

RBTreeNode* RedBlackTree::rotateRight(RBTreeNode* node)
{
    if (node == nullptr || node->left == nullptr) {
        return nullptr; // ������ת
    }

    RBTreeNode* x = static_cast<RBTreeNode*>(node->left);
    node->left = x->right;
    x->right = node;

    std::swap(x->color, node->color);

    return x;
}

RBTreeNode* RedBlackTree::rotateLeft(RBTreeNode* node)
{
    if (node == nullptr || node->right == nullptr) {
        return nullptr; // ������ת
    }

    RBTreeNode* x = static_cast<RBTreeNode*>(node->right);
    node->right = x->left;
    x->left = node;

    std::swap(x->color, node->color);

    return x;
}

