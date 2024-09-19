#pragma once
#include "LinkedListBinaryTree.h"

typedef bool COLOR;
const COLOR RED = true;
const COLOR BLACK = false;

// 左倾红黑树 原本的红黑树太难敲了
// 删除节点功能待完善

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
    RedBlackTree() {} // 调用基类的默认构造函数

    /*
      当左孩子 右孩子 都是红色的时候
      把左右孩子的颜色翻转为黑色 
      然后因为根节点到叶子节点的路径上的黑色节点数目固定
      所以该节点的颜色翻转
    */
    void flipColors(RBTreeNode* node);

    // 右旋
    RBTreeNode* rotateRight(RBTreeNode* node);

    //左旋
    RBTreeNode* rotateLeft(RBTreeNode* node);

    void insert(int item)override {
        root = insertHelper(root, item);
        if (root != nullptr) {
            static_cast<RBTreeNode*>(root)->color = BLACK; // 确保根节点的颜色始终是黑色
        }
    }
};

