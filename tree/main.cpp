#include "tree.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    //std::locale::global(std::locale(""));
    NODE *first = new NODE(5);
    tree myTree(first);  // 用一个树对象来管理 root 节点

    // 插入节点
    myTree.insert(myTree.getRoot(), 3);
    myTree.insert(myTree.getRoot(), 7);
    myTree.insert(myTree.getRoot(), 2);
    myTree.insert(myTree.getRoot(), 4);
    myTree.insert(myTree.getRoot(), 6);
    myTree.insert(myTree.getRoot(), 8);

    //中文字符存在编码错误
    // 打印遍历结果
    // cout<<"前序遍历：\t";
    myTree.preorder(myTree.getRoot());
    cout << endl << std::flush;

     //cout<<"中序遍历：\t";
    myTree.inorder(myTree.getRoot());
    cout << endl << std::flush;

    //cout<<"后序遍历：\t";
    myTree.postorder(myTree.getRoot());
    cout << endl << std::flush;

    return 0;
}