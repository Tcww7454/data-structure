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

        // ����ֵ 6
        llbt.insert(6);
        assert(llbt.getRoot() != nullptr);
        assert(llbt.getRoot()->value == 6);
        assert(llbt.getRoot()->left == nullptr);
        assert(llbt.getRoot()->right == nullptr);

        // ����ֵ 4
        llbt.insert(4);
        assert(llbt.getRoot()->left != nullptr);
        assert(llbt.getRoot()->left->value == 4);
        assert(llbt.getRoot()->left->left == nullptr);
        assert(llbt.getRoot()->left->right == nullptr);

        // ����ֵ 8
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

        // �ض����׼������ַ�����
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        // ����ǰ�����
        llbt.preorder();

        // �ָ���׼���
        std::cout.rdbuf(old);

        // ��ȡ����������֤
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

        // �ض����׼������ַ�����
        stringstream buffer;
        streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        // �����������
        llbt.inorder();

        // �ָ���׼���
        cout.rdbuf(old);

        // ��ȡ����������֤
        string result = buffer.str();
        string expected = "4 6 8 \n";

        assert(result == expected);
        cout << "LinkedList inorder correct" << endl;
    }
    /*
        ��д�����ˣ�����
        д����̫���ˣ�����
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

