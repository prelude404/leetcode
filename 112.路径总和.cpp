/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// 初步思路：从上往下层层遍历，于是想到了递归调用left和right
// 记录当前走过路径的长度：换一个思路，target把“父节点”的值减掉再往下传
// 遇到叶节点且值刚好为targer则返回true；遇到空节点则返回false(层次遍历不下去了)

// 方法2：迭代方法，基于广度的搜索
// 维护两个队列，一个储存节点一个储存当前走过路径
// 每次pop时判断是否为叶节点并达到target
// 每次push时需将自身值加上父节点走过路径

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root) {return false;}
        if(!root->left && !root->right && root->val==targetSum) {return true;}

        return hasPathSum(root->left, targetSum-root->val)
            || hasPathSum(root->right, targetSum-root->val);
    }
};
// @lc code=end

