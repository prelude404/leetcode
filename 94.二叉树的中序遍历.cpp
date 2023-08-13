/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

#include <vector>

using namespace std;

// 前序遍历（Preorder Traversal）：先访问根节点，然后按照左子树、右子树的顺序递归遍历。（中左右）
// 中序遍历（Inorder Traversal）：先按照左子树、根节点、右子树的顺序递归遍历。（左中右）
// 后序遍历（Postorder Traversal）：先按照左子树、右子树、根节点的顺序递归遍历。（左右中）
// 层次遍历（Level Order Traversal）：从根节点开始，逐层从左到右访问节点。

// 方法1：递归（简单但效率低）（本质是一种栈结构）

// 方法2：迭代（栈结构，后进先出）
// 1. 任一节点的左节点都在其前面，因此在该节点入栈后左节点（如果存在）入栈
// 2. 任一节点的右节点都在其后面，因此在该节点出栈后右节点（如果存在）入栈
// 3. 出栈的节点即栈的最上层的节点，在出栈后该节点的值被放入结果数组的末尾
// 4. 任一节点的左节点在入栈之后，该节点左节点均被记为空，防止对其重复处理

// 方法3：Morris（只改变孩子的指向，使空间复杂度为O(1)）

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// @lc code=start
/*** 迭代方法 ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {        
        
        if(!root) {return {};}

        vector<int> in_order; // 排序后的数组
        vector<TreeNode*> stack = {root}; // 维护栈结构

        while(!stack.empty())
        {
            // end()返回的是指向末尾元素位置的迭代器，back()返回末尾元素
            // 迭代器是STL标准库中的概念，与指针类似，可以用*解引用，但不能用->
            TreeNode *node = stack.back();
            
            if(node->left){
                stack.push_back(node->left);
                node->left = nullptr; // 防止对左节点重复处理
                continue;
            }
            else{
                stack.pop_back();
                in_order.push_back(node->val);
            }

            if(node->right){
                stack.push_back(node->right);
            }
        }

        return in_order;
    }
};

/*** 递归方法 ***/
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {        
        
//         vector<int> in_order;
        
//         in_push(root, in_order);

//         return in_order;
//     }

//     private:
//     // 该函数可以避免对于之前递归结果向量的遍历加入
//     // 使用引用可以对in_order向量进行更改
//     void in_push(TreeNode* root, vector<int> &in_order)
//     {
//         if(!root) {return;}
        
//         in_push(root->left,in_order);
//         in_order.push_back(root->val);
//         in_push(root->right,in_order);
//     }
// };

// @lc code=end

