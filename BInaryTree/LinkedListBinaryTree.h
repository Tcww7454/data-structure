#pragma once
#include "BinaryTree.h"

class Node {
public:
    Node* left;
    Node* right;
    int value;
    Node(int val) :value(val) {
        left = nullptr;
        right = nullptr;
    }
};

class LinkedListBinaryTree :
    public BinaryTree
{
private:
    Node* root;

    void preorder(Node* node);

    void inorder(Node* node);

    void posorder(Node* node);

    Node* insert(Node* node, int val);
public:
    LinkedListBinaryTree():root(nullptr){}

    void insert(int value) override {
        root = insert(root, value);
    }

    void preorder() override {
        preorder(root);
        cout << endl;
    }

    void inorder() override {
        inorder(root);
        cout << endl;
    }

    void posorder() override {
        posorder(root);
        cout <<endl;
    }

    Node* getRoot() const {
        return root;
    }
};

