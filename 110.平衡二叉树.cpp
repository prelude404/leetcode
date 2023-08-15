/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

#include <algorithm>

// 初步思路：自上而下递归调用（两层是一种浪费啊...
// 根节点平衡需要满足：1.自身平衡：左右子树高度差小于等于1（利用getHeight()）； 2.左右子树平衡
// 时间复杂度：O(n^2)； 空间复杂度：O(n)

// 方法2：自底向上的递归
// 合理利用getHeight()的递归，利用-1来保存不平衡的信息
// 利用-1这步封神了！Bruno Mars在维密唱的Young Girls也太好听了！
// 若左右子树不平衡getHeight(root->left/right)==-1或是左右子树的高度差大于1，则返回-1
// 时间复杂度：O(n)； 空间复杂度：O(n)

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
    bool isBalanced(TreeNode* root) {
        return getHeight(root)!= -1;
    }

private:
    int getHeight(TreeNode* root){
        if(!root) {return 0;}        
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        if(left==-1 || right==-1 || abs(left-right)>1){
            return -1;
        }
        else{
            return std::max(left,right)+1;
        }
    }
};

// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if(!root) {return true;}
//         return abs(getHeight(root->left)-getHeight(root->right)) <= 1
//             && isBalanced(root->left)
//             && isBalanced(root->right);
//     }

// private:
//     int getHeight(TreeNode* root){
//         if(!root) {return 0;}        
//         return std::max(getHeight(root->left), getHeight(root->right))+1;
//     }
// };

// @lc code=end

