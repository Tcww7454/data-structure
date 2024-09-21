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

        virtual void preorder(node*root)=0;
        virtual void inorder(node*root)=0;
        virtual void postorder(node*root)=0;
        virtual void insert(int value)=0;

        virtual ~tree();
};

#endif