#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include"tree.h"

class binary_tree:public tree
{
    public:
        binary_tree(node*root=nullptr);
        void preorder(node*root)override;
        void inorder(node*root)override;
        void postorder(node*root)override;
        //普通的二叉树这里考虑使用层序遍历来实现插入
        void insert(int value)override;
        node* get_root(){return Root;};

        ~binary_tree();
};

#endif