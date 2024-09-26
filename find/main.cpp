#include"avl.h"

int main()
{
    AVL_TREE avl_first;
    avl_first.insert(1);
    avl_first.insert(2);
    avl_first.insert(3);
    avl_first.remove(2);
    avl_first.inorder(); // 检查插入后的树结构
    return 0;
}

