#ifndef BST_H_
#define BST_H_

#include"tree.h"

class binary_search_tree:public tree
{
    private:
        void insert(int value,node*&Node);
        node*remove(node*root,int value);
        node*findmin_ty(node* root);
    public:
        
        binary_search_tree(node*Node=nullptr);
        ~binary_search_tree();
        void preorder(node*root);
        void inorder(node*root);
        void postorder(node*root);
        void insert(int value);
        //注意，不能直接将Root作为默认参数，因为作用域为私有并且此时并没有实例化，不知道Root是什么
        bool search(int value);
        //bool deleteNode(int value);
        int findmax();
        int findmin();
        void remove(int value);
        node*get_root(){return Root;};
        
    
};

#endif