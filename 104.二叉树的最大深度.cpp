/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// 初步思路：递归，返回自身层加左右字数层的更大值

// 方法2：广度优先搜索，队列维护，每次需要将该层的全部节点出队列，全部子节点入队列（层数+1）

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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        else{
            int dl = maxDepth(root->left);
            int dr = maxDepth(root->right);
            if(dl>dr){
                return (1+dl);
            }
            else{
                return (1+dr);
            }
        }
    }
};
// @lc code=end

