#include<iostream>
#include"tree.h"
#include"binary_tree.h"
#include"binary_search_tree.h"

//简单二叉树测试
void test_bianry_tree()
{
    binary_tree tree_first;
    tree_first.insert(1);
    tree_first.insert(2);
    tree_first.insert(3);
    tree_first.insert(4);
    tree_first.insert(5);
    tree_first.insert(6);

    std::cout<<"Preorder traversal:\t";
    tree_first.preorder(tree_first.get_root());
    std::cout<<std::endl;
    std::cout<<"Inorder traversal:\t";
    tree_first.inorder(tree_first.get_root());
    std::cout<<std::endl;
    std::cout<<"Postorder traversal:\t";
    tree_first.postorder(tree_first.get_root());
    std::cout<<std::endl;
}

//二叉搜索树测试
void test_binary_search_tree()
{
    binary_search_tree tree_first;
    tree_first.insert(1);
    tree_first.insert(2);
    tree_first.insert(3);
    tree_first.insert(4);
    tree_first.insert(5);
    tree_first.insert(6);

    std::cout<<"Preorder traversal:\t";
    tree_first.preorder(tree_first.get_root());
    std::cout<<std::endl;
    std::cout<<"Inorder traversal:\t";
    tree_first.inorder(tree_first.get_root());
    std::cout<<std::endl;
    std::cout<<"Postorder traversal:\t";
    tree_first.postorder(tree_first.get_root());
    std::cout<<std::endl;

    tree_first.remove(5);
    std::cout<<"Preorder traversal:\t";
    tree_first.preorder(tree_first.get_root());

    std::cout<<std::endl;
    std::cout<<"Max num:\t"<<tree_first.findmax()<<std::endl;
    std::cout<<"Min num:\t"<<tree_first.findmin()<<std::endl;

}


int main()
{
    //std::cout<<1;
    //test_bianry_tree();
    test_binary_search_tree();

    return 0;
}