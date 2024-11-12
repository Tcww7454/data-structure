#include"avl.h"
#include"red_black.h"
void testAVL()
{
    AVL_TREE avl_first;
    avl_first.insert(1);
    avl_first.insert(2);
    avl_first.insert(3);
    avl_first.remove(2);
    avl_first.inorder(); // 检查插入后的树结构
}

void testRed_Black()
{
    Red_Black_Tree red_black_tree;
    red_black_tree.insert(1);
    red_black_tree.insert(3);
    red_black_tree.insert(2);
    red_black_tree.insert(4);
    std::cout<<"Preorder:\n";
    red_black_tree.preorder();
    std::cout<<std::endl;
    std::cout<<"Inorder:\n";
    red_black_tree.inorder();
}

int main()
{
    //testAVL();
    testRed_Black();
    return 0;
}

