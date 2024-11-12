#ifndef RED_BLACK_H
#define RED_BLACK_H

#include<iostream>

enum class Color{
    Red,
    Black
};

class treenode
{
    public:
        int value;
        treenode*left;
        treenode*right;
        treenode*father;
        Color color;
        treenode(int val=0):value(val),left(nullptr),
                            right(nullptr),father(nullptr),
                            color(Color::Red){};
        ~treenode(){
            delete left;
            left=nullptr;
            delete right;
            right=nullptr;
        }
        void swiftColor()
        {
            if(color==Color::Black)color=Color::Red;
            else    color=Color::Black;
        }
};



class Red_Black_Tree
{
    private:
        treenode*root;
        //实际上的二叉搜索插入
        int bstInsert(treenode*&current,treenode* &val);
        void treeRemove(treenode*node);
        void leftHand(treenode*node);
        void rightHand(treenode*node);
        void Inorder(treenode*node);
        void Preorder(treenode*node);
    public:
        Red_Black_Tree();//之后再补充对于数组来构建的树
        //外层封装
        void insert(int val);
        //void remove(int val);
        void fixInsert(treenode *&node);
        void inorder();
        void preorder();
        ~Red_Black_Tree();
        
};

/*
    首先，在开始之前我们需要了解一下红黑树的一些性质
    1~红黑树它本质上也是一颗二叉搜索树，满足(左<根<右)的基本属性    左根右
    2~在红黑树中，根和叶子节点都是黑色(这里的叶子节点指的是空节点)  根叶黑
    3~在红黑树中不存在俩个连续的红色节点                           不红红
    4~任意节点到叶所有路径上的黑色节点数都相同                      根叶同
*/

/*
    这里需要对红黑树的插入情况进行一定的解析
    首先，我们需要明确，对于红黑树中插入的节点，我们默认是红色的
    应该对于红色节点的插入，是可能不会破坏任何一条红黑树的性质的
    对于破坏性质的情况，也只可能破坏红黑树的不红红和根叶黑性质，
    相对于插入黑色节点来说影响更小
*/

/*
    1~插入节点是根节点  此时直接将该节点颜色从红转黑即可
    
    当插入节点不是根节点时，我们需要考虑插入节点的叔叔节点，也就是父节点的同级节点
    2~插入节点的叔叔节点是红色
        此时我们需要对该节点的父节点，叔节点，爷节点进行变色
        然后以爷节点作为插入节点，判断此时是否破坏了红黑树的性质
    3~当插入节点的叔叔节点为黑色
        此时，我们就需要想AVL树一样去判断此时树是LL，RR，LR，RL中哪一种情况了
        再根据这些情况对树进行必要的调整
*/

/*
    插入一个节点后，我们判断插入节点，该插入节点父节点，叔节点，爷节点
    构建的子树

    回顾一下这个类型的判断，在这里其实就是这里的爷节点需要根据什么路径才能
    到达这个插入节点
    
    1~当该子树是一个LL型时，需要进行一个右旋操作
      以爷节点为旋转点进行右旋，对父节点(旋转中心点)和爷节点(旋转点)进行变色
    2~RR型，需要进行一个左旋操作
      以爷节点为一个旋转点，对其进行左旋，接下来对旋转点和旋转中心点进行变色
    3~LR型，需要先左旋爷的左孩子，再右旋爷节点，对最后一次的旋转点和旋转中心点进行变色
    4~RL型，需要先右旋爷的右孩子，在左旋爷节点，对最后一次的旋转点和旋转中心点进行变色
*/

#endif