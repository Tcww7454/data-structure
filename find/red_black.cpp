#include"red_black.h"

/*
    此处还需要对红黑树的调整情况进行分析下，
    注意，红黑树每次插入的调整其实只会涉及到4个节点
    插入节点，相对的父节点，爷节点，叔节点
    每次调整只需要对这几个节点进行有限次的修改就能保证红黑树的性质
*/

Red_Black_Tree::Red_Black_Tree():root(nullptr){}

void Red_Black_Tree::treeRemove(treenode*node)
{
    if(node==nullptr)return ;

    treeRemove(node->left);
    treeRemove(node->right);
    delete node;
}

Red_Black_Tree::~Red_Black_Tree()
{

}


void Red_Black_Tree::insert(int val)
{
    treenode* node=new treenode(val);
    int type=bstInsert(root,node);
    if(type==-1)//试图插入一个已有的值
    {
        std::cout<<"error same num\t\n";
    }
    else if(type==0)//插入根节点，只需要修改根节点的颜色
    {
        root->swiftColor();
    }
    else//常规插入
    {
        fixInsert(node);
    }
}
    

/*
这里的root指的是当前遍历到的节点为止，node为插入节点
不使用treenode* &的有福了
使用treenode&虽然这个current=node是能够实现的，
但是current与nullptr是无法比较的
只使用treenode*node会使得递归一次时能够正确的设置节点,
但第二层开始函数就会丢失对current原对象的修改权了
*/

/*
干脆在这里对这种指针传递的影响进行一下分析吧
这里的话需要理解首先是指针传递于引用传递的区别
对于指针传递，其本质上也是一个值传递，
只是由于指针中储存的是地址的副本，而这个副本中的地址由于是一模一样的
所以对于这个指针副本来说，我们可以通过副本来访问对应地址中的元素并进行想要的修改
但是，我们需要明白，副本只是副本，即使对这个副本本身进行修改，也不会影响本来的数据
这就是为什么下面的使用指针传递会导致无法正确的插入节点的原因，只会在一层的函数中正确运行
*/

int Red_Black_Tree::bstInsert(treenode* &current,treenode* &node)
{
    //当节点为空时就可以在这个节点插入了
    if(current==nullptr&&root==nullptr)
    { 
        current=node;
        return 0;//0表示插入的是根节点
        //只有在第一次插入的情况下才会插入根节点
        //使用红黑树应该保证不会出现相同数据
        //所以这里不需要考虑一个重复插入根节点的可能
    }
    else if(current==nullptr&&root!=nullptr)
    { 
        current=node;
        return 1;//0表示插入的是根节点
        //只有在第一次插入的情况下才会插入根节点
        //使用红黑树应该保证不会出现相同数据
        //所以这里不需要考虑一个重复插入根节点的可能
    }
    
    //大于节点值往右子树查找
    if(node->value>current->value)
    { 
        node->father=current;
        return bstInsert(current->right,node);
    }
    //小于节点值往左子树查找
    else if(node->value<current->value)
    {
        node->father=current;
        return bstInsert(current->left,node);
    }
    return -1;//如果输出-1表示企图插入一个已有的值
}

/*
左右旋操作是一块相对独立的实现
这里不需要对其进行多深的分析，
主要是要搞清楚之后的恢复结构各自要对对应的哪些节点旋转
*/

//先搞清楚我们的一个旋转操作对象问题
/*
首先，我们传给函数的参数所代表的节点其实是这次操作的节点
接下来，我们需要去找到旋转操作的旋转点和旋转中心点
在红黑树中，这一次的旋转点的父节点对应旋转中心点，爷节点对应旋转点
然后就可以对这些进行旋转操作了
需要注意的是，旋转节点的旋转不是在左旋操作中寻找的，而是传递进去的
所以这里的参数应该是需要旋转的节点
*/


//再次注意下，这里就不用使用指针的引用了，这里不会有递归的操作
void Red_Black_Tree::leftHand(treenode *Node)
{
    if(Node==nullptr||Node->right==nullptr)
    return ;

    /*
    此处旋转操作操作数会是插入节点的爷节点
    由于旋转还需要一个中心点，所以找到这个节点的右子节点就行
    这里一定会是右子节点，至于原因是由于产生需要左旋操作的情况，不说
    左旋操作需要把当前节点接到当前节点的右孩子的左孩子上，
    并且把当前节点的父节点赋给这个右孩子，同时把当前节点的父节点赋值右孩子
    */
    treenode* cenOfRa=Node->right;

     // 将 cenOfRa 的左子树（可能为空）设为 Node 的右子树
    Node->right = cenOfRa->left;
    if(cenOfRa->left!=nullptr)
    cenOfRa->left->father=Node;//更新子节点的父节点

   cenOfRa->father=Node->father;
   if(Node->father==nullptr)
    root=cenOfRa;//更新根节点
   else if(Node==Node->father->left)
    Node->father->left=cenOfRa;
   else 
    Node->father->right=cenOfRa;

    //更新父子关系
   cenOfRa->left=Node;
   Node->father=cenOfRa;
}

void Red_Black_Tree::rightHand(treenode *Node)
{
    //左旋与右旋基本一样，只需要改变下左右的节点就行
    if(Node==nullptr||Node->right==nullptr)
    return ;

    treenode* cenOfRa=Node->left;

     // 将 cenOfRa 的右子树（可能为空）设为 Node 的左子树
    Node->left = cenOfRa->right;
    if(cenOfRa->right!=nullptr)
    cenOfRa->right->father=Node;//更新子节点的父节点

   cenOfRa->father=Node->father;
   if(Node->father==nullptr)
    root=cenOfRa;//更新根节点
   else if(Node==Node->father->left)
    Node->father->left=cenOfRa;
   else 
    Node->father->right=cenOfRa;

    //更新父子关系
   cenOfRa->right=Node;
   Node->father=cenOfRa;
}

//这个函数用于在插入常规节点时对红黑树的性质修复
void Red_Black_Tree::fixInsert(treenode *&node)
{
    while(node!=root&&node->father->color==Color::Red)
    {   
        //取出叔节点,需先判断当前是左子还是右子
        //这些情况是LL这些型的第一个字母的判断
        if(node->father==node->father->father->left)
        {
            treenode *uncle=node->father->father->right;
            //空节点为黑色，注意这点
            if(uncle!=nullptr &&uncle->color==Color::Red)
            {
                uncle->swiftColor();//叔节点颜色翻转
                uncle->father->swiftColor();//爷节点颜色翻转
                node->father->swiftColor();//父节点颜色翻转
                //爷节点为根节点，不会重复进入循环，需要在这里修复
                if(node->father->father==root)
                {
                    node->father->father->swiftColor();
                }
                node=node->father->father;//往爷节点递推上去修复
            }
            //能进入这个else的情况只有叔节点为黑，此时需要分情况考虑
            else
            {
                //我们前面已经确定了这个大if是L型，即插入在爷节点的左子树
                //接下来进行判断时插入在了父节点的左右那颗子树上

                //这时是从爷的左树走到父点，再由父点左树走到子点
                if(node==node->father->left)//LL型
                {
                    //可以在选择完后进行一次的颜色调整，我选择在这里调整
                    
                    //此时我们需要对爷节点进行右旋操作
                    rightHand(node->father->father);
                    node->father->swiftColor();
                    node->father->father->swiftColor();

                }
                else//进入这个小else意味着是LR型情况
                {
                    //在这种情况下，需要对爷节点的左孩子进行左旋，然后对爷节点右旋
                    //可以简化，但是这样逻辑更明确
                    //我们的操作是相对于旋转中心点的情况

                    //接下来需要对插入节点和插入节点的爷节点进行变色，考虑在旋转前实现


                    leftHand(node->father->father->left);
                    rightHand(node->father->father);

                    node->swiftColor();
                    node->father->father->swiftColor();
                }
            }
        }
        //这个大else就是以R开头的俩种情况
        else
        {
             treenode *uncle=node->father->father->left;
            //空节点为黑色，注意这点
            if(uncle!=nullptr &&uncle->color==Color::Red)
            {
                uncle->swiftColor();//叔节点颜色翻转
                uncle->father->swiftColor();//爷节点颜色翻转
                node->father->swiftColor();//父节点颜色翻转
                //爷节点为根节点，不会重复进入循环，需要在这里修复
                if(node->father->father==root)
                {
                    node->father->father->swiftColor();
                }
                node=node->father->father;//往爷节点递推上去修复
            }
            //能进入这个else的情况只有叔节点为黑，此时需要分情况考虑
            else
            {
                //我们前面已经确定了这个大if是R型，即插入在爷节点的右子树
                //接下来进行判断时插入在了父节点的左右那颗子树上

                //这时是从爷的右树走到父点，再由父点右树走到子点
                if(node==node->father->right)//RR型
                {
                    //可以在选择完后进行一次的颜色调整，我选择在这里调整
       
                    //此时我们需要对爷节点进行左旋操作
                    leftHand(node->father->father);

                    node->father->swiftColor();
                    node->father->father->swiftColor();
                }
                else//进入这个小else意味着是RL型情况
                {
                    //在这种情况下，需要对爷节点的左孩子进行左旋，然后对爷节点右旋
                    //可以简化，但是这样逻辑更明确
                    //我们的操作是相对于旋转中心点的情况

                    //接下来需要对插入节点和插入节点的爷节点进行变色，考虑在旋转前实现
                    rightHand(node->father->father->right);
                    leftHand(node->father->father);
                    node->swiftColor();
                    node->father->father->swiftColor();
                    
                }
            }
        }
    }
    root->color = Color::Black;  // 根节点永远是黑色
}

void Red_Black_Tree::Inorder(treenode*node)
{
    if( node ==nullptr)return ;
    Inorder(node->left);
    std::cout << node->value << " (" << (node->color == Color::Red ? "Red" : "Black") << ")" << std::endl;
    Inorder(node->right);
}

void Red_Black_Tree::inorder()
{
    Inorder(root);
}

void Red_Black_Tree::Preorder(treenode*node)
{
    if( node ==nullptr)return ;
    std::cout << node->value << " (" << (node->color == Color::Red ? "Red" : "Black") << ")" << std::endl;
    Inorder(node->left);
    Inorder(node->right);
}

void Red_Black_Tree::preorder()
{
    Preorder(root);
}