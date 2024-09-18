#pragma once
#include<iostream>
#include<vector>

using namespace std;
class BinaryTree
{
public:
	virtual void insert(int value) = 0;

	virtual void preorder() = 0;

	virtual void inorder() = 0;

	virtual void posorder() = 0;
};

