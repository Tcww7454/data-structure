#include"tree.h"
#include"binary_tree.h"
#include<iostream>
#include<queue>

binary_tree::binary_tree(node*root)
{
    Root=root;
}

void binary_tree::preorder(node*root)
{
    if(root==nullptr)return ;
    std::cout<<root->val<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void binary_tree::inorder(node*root)
{
    if(root==nullptr)return;
    inorder(root->left);
    std::cout<<root->val<<"\t";
    inorder(root->right);
}

void binary_tree::postorder(node*root)
{
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->val<<"\t";
}

binary_tree::~binary_tree()
{
    destory_tree(Root);
}


void binary_tree::insert(int value)
{
    node*temp=new node(value);
    if(Root==nullptr)
    {
        Root=temp;
        return ;
    }
    else
    {
        std::queue<node*>q;
        q.push(Root);

        while(!q.empty())
        {
            node* current=q.front();
            q.pop();

            if(current->left==nullptr)
            {
                current->left=temp;
                return ;
            }
            else
                q.push(current->left);

            if(current->right==nullptr)
            {
                current->right=temp;
                return ;
            }
            else
                q.push(current->right);
        }
    }
}