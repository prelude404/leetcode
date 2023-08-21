/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include <vector>

using namespace std;

// 初步思路：迭代方法，vector维护栈结构，根节点出栈后分别放入右、左子节点

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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<TreeNode*> v;
        vector<int> ans;
        
        v.push_back(root);
        
        while(!v.empty())
        {
            TreeNode* cur = v.back();
            v.pop_back();
            ans.push_back(cur->val);
            
            if(cur->right){
                v.push_back(cur->right);
            }
            
            if(cur->left){
                v.push_back(cur->left);
            }
        }

        return ans;
    }
};
// @lc code=end

