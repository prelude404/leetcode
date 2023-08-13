/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

#include <vector>

using namespace std;

// 初步思路：1.要遍历树；2.要比较值；3.随时return（基于中序遍历）

// 方法1：深度优先搜索（Depth-First Search, DFS）（底层：遍历）（根+左子树+右子树）（递归极简代码如下）
// if (p == null) return q == null;
// return q != null && p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);

// 方法2：广度优先搜索（Breadth-First Search, BFS）（逐层地访问节点进行遍历）
// 需要利用队列结构（先进先出，出列后需将子节点入列）

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
    /// @brief 
    /// @param p 
    /// @param q 
    /// @return 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {return true;} // 均为空
        if(!p || !q) {return false;} // 一空一不空

        vector<TreeNode*> s_p = {p};
        vector<TreeNode*> s_q = {q};
        
        while(!s_p.empty())
        {
            TreeNode* n_p = s_p.back();
            TreeNode* n_q = s_q.back();
            
            if(n_p->left && n_q->left)
            {
                s_p.push_back(n_p->left);
                n_p->left = nullptr;
                
                s_q.push_back(n_q->left);
                n_q->left = nullptr;
            }
            else if(!n_p->left && !n_q->left)
            {
                if(n_p->val != n_q->val) {return false;}

                s_p.pop_back();
                s_q.pop_back();
            }
            else {return false;}

            if(n_p->right && n_q->right)
            {
                s_p.push_back(n_p->right);
                s_q.push_back(n_q->right);
            }
            else if(n_p->right || n_q->right){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

