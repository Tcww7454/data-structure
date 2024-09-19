#ifndef TREE_H_
#define TREE_H_

class node
{
    public:
    int val;
    node *left;
    node *right;

    node(int value):val(value),left(nullptr),right(nullptr){};
};


class tree
{
    protected:
        node*Root;
        void destory_tree(node*Root);
    public:
        
        tree(node* root=nullptr);

        virtual void preorder()=0;
        virtual void inorder()=0;
        virtual void postorder()=0;

        virtual ~tree();
};

#endif