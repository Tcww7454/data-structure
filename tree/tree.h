#ifndef TREE
#define TREE

class NODE
{
    public:
        int value;
        NODE* left;
        NODE *right;
        NODE(int value):value(value),left(nullptr),right(nullptr){};
};

class tree
{
private:
    NODE* root;
    void destorytree(NODE*node);
    
public:
    tree();//待扩展，等待由数组构建树
    tree(NODE*root);
    ~tree();
    void preorder(NODE* node);
    void inorder(NODE* node);
    void postorder(NODE* node);
    NODE* insert(NODE* node, int value);
    NODE* getRoot(){return root;};
};

#endif