/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

#include <vector>

using namespace std;

// 初步思路：递归，如果每一个节点的左右子树元素个数差小于等于1，则为平衡树（证明见1382官方题解）
// 取数组的中间值作为根节点，左侧所有元素作为左子树成员，右侧所有元素作为右子树成员

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, (nums.size()-1));
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums,int low, int high) {
        
        if(low > high) {return nullptr;}
        
        int mid = (low+high)/2;
        
        TreeNode* node = new TreeNode();
        // 指针一定要预先分配内存再为其进行赋值（括号内可以调用任意一种构造函数）
        
        node->val = nums[mid];
        node->left = sortedArrayToBST(nums, low, mid-1);
        node->right = sortedArrayToBST(nums, mid+1, high);

        return node;
    }
};
// @lc code=end

