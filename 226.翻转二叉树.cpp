/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

#include <queue>

using namespace std;

// 初步思路：翻转二叉树相当于对每一节点的左右子节点进行交换
// 1. 递归方法，交换自身节点，再分别对左右子节点调用翻转函数
// 2. 迭代方法，遍历所有节点，若存在子节点则进行翻转
// 决定使用广度优先搜索方法进行层次遍历，实现每一节点的子节点翻转

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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* cur;
        TreeNode *left, *right;

        while(!que.empty())
        {
            cur = que.front();
            left = cur->left;
            right = cur->right;
            
            cur->left = right;
            cur->right = left;

            if(left) que.push(left);
            if(right) que.push(right);
            
            que.pop();
        }

        return root;
    }
};
// @lc code=end

