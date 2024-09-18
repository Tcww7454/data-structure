#include<iostream>
#include"LinkedListBinaryTree.h"
#include"ArrayBinaryTree.h"
#include <cassert>
#include<sstream>
using namespace std;

class LinkedListBinaryTreeTest {
public:
	static void insertTest() {
        LinkedListBinaryTree llbt;

        // 插入值 6
        llbt.insert(6);
        assert(llbt.getRoot() != nullptr);
        assert(llbt.getRoot()->value == 6);
        assert(llbt.getRoot()->left == nullptr);
        assert(llbt.getRoot()->right == nullptr);

        // 插入值 4
        llbt.insert(4);
        assert(llbt.getRoot()->left != nullptr);
        assert(llbt.getRoot()->left->value == 4);
        assert(llbt.getRoot()->left->left == nullptr);
        assert(llbt.getRoot()->left->right == nullptr);

        // 插入值 8
        llbt.insert(8);
        assert(llbt.getRoot()->right != nullptr);
        assert(llbt.getRoot()->right->value == 8);
        assert(llbt.getRoot()->right->left == nullptr);
        assert(llbt.getRoot()->right->right == nullptr);

        cout << "LinkedList insert correct" << endl;
	}

    static void preorderTest() {

        /*
        excepted :
                6
               / \
              4   8
            preorder result 6 4 8
        */
        LinkedListBinaryTree llbt;
        llbt.insert(6);
        llbt.insert(4);
        llbt.insert(8);

        // 重定向标准输出到字符串流
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        // 调用前序遍历
        llbt.preorder();

        // 恢复标准输出
        std::cout.rdbuf(old);

        // 获取输出结果并验证
        std::string result = buffer.str();
        std::string expected = "6 4 8 \n";

        assert(result == expected);
        cout << "LinkedList preorder correct" << endl;
    }

    static void inorderTest() {

        /*
        excepted :
                6
               / \
              4   8
            preorder result 4 6 8
        */
        LinkedListBinaryTree llbt;
        llbt.insert(6);
        llbt.insert(4);
        llbt.insert(8);

        // 重定向标准输出到字符串流
        stringstream buffer;
        streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        // 调用中序遍历
        llbt.inorder();

        // 恢复标准输出
        cout.rdbuf(old);

        // 获取输出结果并验证
        string result = buffer.str();
        string expected = "4 6 8 \n";

        assert(result == expected);
        cout << "LinkedList inorder correct" << endl;
    }
    /*
        不写测试了！！！
        写测试太累了！！！
    */
};


int main() {
   /* LinkedListBinaryTreeTest::insertTest();

    LinkedListBinaryTreeTest::preorderTest();

    LinkedListBinaryTreeTest::inorderTest();*/

    ArrayBinaryTree abt;
    abt.insert(6);
    abt.insert(4);
    abt.insert(8);

    abt.posorder();
}

