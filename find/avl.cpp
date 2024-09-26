#include"avl.h"

//高度为左子树深度-右子树深度
int AVL_TREE::height(TreeNode*node)
{
    //空节点高度为-1，叶子节点高度为0
    /*
        这里所以选择空节点深度值是为了统一后面的计算
        且-1值在非空节点时是不会取到的，故这里不会存在冲突
        就比如一个计算一个叶子节点，其俩个子节点都为空，
        此时俩个子树深度都为0，平衡因子刚好为0
        如果为0，在更新平衡因子时会出现问题，为0时根节点高度为1，不符合逻辑
        而为-1则更能符合逻辑
    */
    return node==nullptr?-1:node->height;
}

void AVL_TREE::updateHeight(TreeNode* node)
{
    node->height=std::max(height(node->left),height(node->right))+1;
}

int AVL_TREE::balanceFactor(TreeNode*node)
{
    if(node==nullptr)return 0;
    return height(node->left)-height(node->right);
}

//右旋
TreeNode* AVL_TREE::rightRotate(TreeNode*node)
{
    TreeNode *child = node->left;
    TreeNode *grandChild = child->right;
    // 以 child 为原点，将 node 向右旋转
    child->right = node;
    node->left = grandChild;
    // 更新节点高度
    updateHeight(node);
    updateHeight(child);
    // 返回旋转后子树的根节点
    return child;
}

//左旋与右旋为镜像操作，故这里只需要替换上面右旋代码中的右节点即可
TreeNode* AVL_TREE::leftRotate(TreeNode*node)
{
     TreeNode *child = node->right;
    TreeNode *grandChild = child->left;
    // 以 child 为原点，将 node 向左旋转
    child->left = node;
    node->right = grandChild;
    // 更新节点高度
    updateHeight(node);
    updateHeight(child);
    // 返回旋转后子树的根节点
    return child;
}

TreeNode* AVL_TREE::rotate(TreeNode*node)
{
    //获取节点的平衡因子并由此判断要使用哪种操作
    int _balanceFactor=balanceFactor(node);
    //左偏树
    if(_balanceFactor>1)
    {
        //右旋
        if(balanceFactor(node->left)>=0)
        {
            return rightRotate(node);
        }
        else{
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if(_balanceFactor<-1)
    {
        if(balanceFactor(node->right)<=0)
        {
            //左旋
            return leftRotate(node);
        }
        else{
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
    }
    //上诉俩种都没有便是平衡因子绝对值不超过1，无须旋转，直接返回
    return node;
}

void AVL_TREE::insert(int val)
{
    //Root=insertHelper(Root,val);
    std::cout << "Inserting value: " << val << "\n";
    Root=insertHelper(Root, val);
    if (Root) {
        std::cout << "Tree root after insertion: " << Root->val << "\n"; // 打印根节点
    }
}

TreeNode* AVL_TREE::insertHelper(TreeNode*node,int val)
{
    /*
    这里使用递归实现插入操作，在找到插入节点后，函数会逐层跳出。
    注意，此时是可能遇到部分因插入操作而失衡的节点的，
    而这里的递归操作，刚好符合了AVL树在离插入操作的最近的失衡节点进行旋转操作的特性
    因为这样能最大限度的减少操作次数
    */

    //与二叉搜索树一样，查找到最底的根节点，在该空根节点处申请内存
    if(node==nullptr)
    {
        //std::cout << "Creating new node with value: " << val << "\n"; // 调试信息
        return new TreeNode(val);
    }

    /* 1. 查找插入位置并插入节点 */
    if (val < node->val)
        node->left = insertHelper(node->left, val);
    else if (val > node->val)
        node->right = insertHelper(node->right, val);
    else
    {
        //std::cout << "Duplicate value not inserted: " << val << "\n"; // 调试信息
        return node;    // 重复节点不插入，直接返回
    }
        
    updateHeight(node); // 更新节点高度
    //std::cout << "Updated height for node " << node->val << ": " << node->height << "\n"; // 打印更新后的高度
    /* 2. 执行旋转操作，使该子树重新恢复平衡 */
    node = rotate(node);
    // 返回子树的根节点
    return node;
}

void AVL_TREE::remove(int val)
{
    Root=removeHelper(Root,val);
}

TreeNode* AVL_TREE::removeHelper(TreeNode*node,int val)
{
    //没找到该节点
    if(node==nullptr)
    return nullptr;
    /* 1. 查找节点并删除 */
    if (val < node->val)
        node->left = removeHelper(node->left, val);
    else if (val > node->val)
        node->right = removeHelper(node->right, val);
    else
    {
        if (node->left == nullptr || node->right == nullptr) 
        {
            TreeNode *child = node->left != nullptr ? node->left : node->right;
            // 子节点数量 = 0 ，直接删除 node 并返回
            if (child == nullptr) 
            {
                delete node;
                return nullptr;
            }
            // 子节点数量 = 1 ，直接删除 node
            else 
            {
                delete node;
                node = child;
            }
        } 
        else 
        {
        // 子节点数量 = 2 ，则将中序遍历的下个节点删除，并用该节点替换当前节点
        TreeNode *temp = node->right;
        while (temp->left != nullptr) 
        {
            temp = temp->left;
        }
        int tempVal = temp->val;
        node->right = removeHelper(node->right, temp->val);
        node->val = tempVal;
        }
    }
    return node;
}

bool AVL_TREE::find(int val)
{
    TreeNode*temp=Root;
    while(temp)
    {
        if(temp->val==val)return true;
        else if(temp->val>val)temp=temp->left;
        else temp=temp->right;
    }
    return false;
}

void AVL_TREE::deleteNode(TreeNode*node)
{   
    if(node==nullptr)return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

AVL_TREE::~AVL_TREE()
{
    deleteNode(Root);
}

void AVL_TREE::inorder()
{
    std::cout << "Inorder traversal:\n"; // 调试信息
    inorder_t(Root);
    std::cout << "\n"; // 使输出更整齐
}

void AVL_TREE::inorder_t(TreeNode*node)
{
    if(node==nullptr)
    {
        return ;
    }
    inorder_t(node->left);
    std::cout  << node->val << "\t"; // 输出节点值
    inorder_t(node->right);
}

//debug
// void AVL_TREE::inorder_t(TreeNode *node) {
//     if (node == nullptr) {
//         std::cout << "Reached nullptr node.\n"; // 进入空节点的调试信息
//         return;
//     }
//     std::cout << "Traversing left subtree of node with value: " << node->val << "\n"; // 调试左子树
//     inorder_t(node->left); // 遍历左子树
//     std::cout << "Visiting node with value: " << node->val << "\n"; // 输出当前节点值
//     std::cout << "Traversing right subtree of node with value: " << node->val << "\n"; // 调试右子树
//     inorder_t(node->right); // 遍历右子树
// }
