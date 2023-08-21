/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

#include <vector>

using namespace std;

// 初步思路：迭代方法，vector维护栈结构，分别放入右、左子节点，根节点无子节点则出栈

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<TreeNode*> v;
        vector<int> ans;

        v.push_back(root);

        while(!v.empty()){
            TreeNode* cur = v.back();
            
            if(!cur->left && !cur->right){
                ans.push_back(cur->val);
                v.pop_back();
            }

            if(cur->right){
                v.push_back(cur->right);
                cur->right = nullptr;
            }

            if(cur->left){
                v.push_back(cur->left);
                cur->left = nullptr; // 重要！防止重复入栈！！！
            }
        }

        return ans;
    }
};

// @lc code=end

