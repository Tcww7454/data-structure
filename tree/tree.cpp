#include"tree.h"
#include<iostream>

using std::cout;
void tree::destorytree(NODE*node)
{
    if(node==nullptr)return; //此时代表该节点为空，已销毁
    destorytree(node->left);
    destorytree(node->right);
    delete node;
}

tree::tree():root(nullptr){};

tree::tree(NODE*node):root(node){};


tree::~tree()
{
    destorytree(root);
}

void tree::preorder(NODE* node)
{
    if(node==nullptr)return;
    cout<<node->value<<"\t";
    preorder(node->left);
    preorder(node->right);
    
}

void tree::inorder(NODE* node)
{
    if(node==nullptr)return;
    inorder(node->left);
    cout<<node->value<<"\t";
    inorder(node->right);
}
void tree::postorder(NODE* node)
{
    if(node==nullptr)return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value << "\t";
}

NODE* tree::insert(NODE* node, int value)
{
    if (node == nullptr) {
        return new NODE(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}