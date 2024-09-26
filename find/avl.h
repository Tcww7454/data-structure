#ifndef AVL_H
#define AVL_H
#include<iostream>
#include<algorithm>

class TreeNode
{
    public:
        int val;
        int height;//节点高度
        TreeNode*left;
        TreeNode*right;
        TreeNode()=default;
        explicit TreeNode(int x=0):val(x),left(nullptr),right(nullptr),height(0){};
};

class AVL_TREE
{
    private:
        TreeNode*Root;
        //插入删除的具体实现
        TreeNode* insertHelper(TreeNode*node,int val);
        TreeNode* removeHelper(TreeNode*node,int val);
        void deleteNode(TreeNode*node);
        void inorder_t(TreeNode*node);
    public:
        AVL_TREE(TreeNode*root=nullptr):Root(root){};
        int height(TreeNode*node);
        void updateHeight(TreeNode*node);
        int balanceFactor(TreeNode*node);
        TreeNode*rightRotate(TreeNode*node);
        TreeNode*leftRotate(TreeNode*node);
        TreeNode*rotate(TreeNode*node);
        //用户层插入删除
        void insert(int val);
        void remove(int val);
        ~AVL_TREE();
        bool find(int val);
        void inorder();
        void print()
        {
            //TreeNode*temp=Root;;
            std::cout<<Root->val;
        }
};

#endif