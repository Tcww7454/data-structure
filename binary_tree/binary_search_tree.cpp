#include"binary_search_tree.h"
#include"tree.h"
#include<climits>
#include<algorithm>
#include<iostream>

binary_search_tree::binary_search_tree(node*Node):tree(Node){};

binary_search_tree::~binary_search_tree()
{
    destory_tree(Root);
}

//废案
// void binary_search_tree::insert(int value,node*Node=nullptr,int flag)
// {
//     //通过这样一步可以实现用户层使用一个参数调用，也可以通过重载来进行实现，这里就不演示了
//     //其实不应该这么写了，有时间再改吧，这个小问题
//     if(!flag&&Node==nullptr)
//     {
//         Node=Root;
//         flag=1;
//     }
//     /*
//      eg:            往其中插入4的话二叉搜索
//       5                       5
//      / \                     / \
//     1   6                   1   6
//                             \
//                               4
//     */
//     if(!Node)//二叉搜索树只需要插到最底部就行了，AVL树需要考虑的可就多了
//     {
//         Node=new node(value);
//         return ;
//     }
//     if(value>Node->val)
//         insert(value,Node->right,flag);
//     else if(value<Node->val)
//         insert(value,Node->left,flag);
//     //值相等时不做处理
// }

void binary_search_tree::insert(int value)
{
    insert(value,Root);//将该函数设为私有，保证其能够使用父类的Root成员
}

void binary_search_tree::insert(int value,node*&Node)
{
    if(!Node)
    {
        Node=new node(value);
    }
    if(value>Node->val)
        insert(value,Node->right);
    else if(value<Node->val)
        insert(value,Node->left);
}

bool binary_search_tree::search(int value)
{
    node*temp=Root;
    while(temp)
    {
        if(temp->val==value)return true;
        else if(temp->val>value)temp=temp->left;
        else if(temp->val<value)temp=temp->right;
    }
    return false;
}

int binary_search_tree::findmax()
{
    node*temp=Root;
    if(!temp)
        return INT_MIN;
    while(temp->right)
    {
        temp=temp->right;
    }
    return temp->val;
}

int binary_search_tree::findmin()
{
    node*temp=Root;
    if(!temp)
        return INT_MAX;
    while(temp->left)
    {
        temp=temp->left;
    }
    return temp->val;
}

// bool binary_search_tree::deleteNode(int value)
// {
//     node*&temp=Root;
//     while(temp&&temp->val!=value)
//     {
//         if(temp->val>value)
//         temp=temp->left;
//         else if(temp->val<value)
//         temp=temp->right;
//         else
//         break;
//     }
//     if(temp->val==value)
//     {

//     }
// }

void binary_search_tree::remove(int value)
{
    Root=remove(Root,value);
}

node* binary_search_tree::findmin_ty(node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

node* binary_search_tree::remove(node* root, int value) 
{
        // 找不到节点，返回空
        if (!root)
            return root;

        // 在左子树中查找要删除的值
        if (value < root->val) {
            root->left = remove(root->left, value);
        }
        // 在右子树中查找要删除的值
        else if (value > root->val) {
            root->right = remove(root->right, value);
        }
        // 找到要删除的节点
        else {
            // 情况 1：叶子节点
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            
            // 情况 2：只有一个子节点
            else if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            
            // 情况 3：有两个子节点
            // 找到右子树的最小值（后继节点）
            node* temp = findmin_ty(root->right);
            
            // 用后继节点的值替换当前节点的值
            root->val = temp->val;
            
            // 删除后继节点
            root->right = remove(root->right, temp->val);
        }
        
        return root;
}



void binary_search_tree::preorder(node*root)
{
    if(root==nullptr)return ;
    std::cout<<root->val<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void binary_search_tree::inorder(node*root)
{
    if(root==nullptr)return;
    inorder(root->left);
    std::cout<<root->val<<"\t";
    inorder(root->right);
}

void binary_search_tree::postorder(node*root)
{
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->val<<"\t";
}