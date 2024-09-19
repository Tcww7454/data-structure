#include"tree.h"

tree::tree(node*node)
{
    Root=node;
}

void tree::destory_tree(node*Root)
{
    if(Root==nullptr)return ;
    destory_tree(Root->left);
    destory_tree(Root->right);
    delete Root;
}

tree::~tree()
{
    destory_tree(Root);
}