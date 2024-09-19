#pragma once
#include "LinkedListBinaryTree.h"

typedef bool COLOR;
const COLOR RED = true;
const COLOR BLACK = false;

// �������� ԭ���ĺ����̫������
// ɾ���ڵ㹦�ܴ�����

class RBTreeNode : public Node {
public:
    COLOR color;
    
    RBTreeNode(COLOR clr, int val) :Node(val) {
        color = clr;
    }
};

class RedBlackTree :
    public LinkedListBinaryTree
{
private:
    bool isRed(Node* node);

    RBTreeNode* insertHelper(Node* node, int item);
public :
    RedBlackTree() {} // ���û����Ĭ�Ϲ��캯��

    /*
      ������ �Һ��� ���Ǻ�ɫ��ʱ��
      �����Һ��ӵ���ɫ��תΪ��ɫ 
      Ȼ����Ϊ���ڵ㵽Ҷ�ӽڵ��·���ϵĺ�ɫ�ڵ���Ŀ�̶�
      ���Ըýڵ����ɫ��ת
    */
    void flipColors(RBTreeNode* node);

    // ����
    RBTreeNode* rotateRight(RBTreeNode* node);

    //����
    RBTreeNode* rotateLeft(RBTreeNode* node);

    void insert(int item)override {
        root = insertHelper(root, item);
        if (root != nullptr) {
            static_cast<RBTreeNode*>(root)->color = BLACK; // ȷ�����ڵ����ɫʼ���Ǻ�ɫ
        }
    }
};

