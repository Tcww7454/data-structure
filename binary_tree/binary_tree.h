#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include"tree.h"

class binary_tree:public tree
{
    public:
        binary_tree(node*root=nullptr);
        void preorder(node*root);
        void inorder(node*root);
        void postorder(node*root);
        ~binary_tree();
};

#endif