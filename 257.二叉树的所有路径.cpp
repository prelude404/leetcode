/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

#include <vector>
#include <string>
#include <queue>

using namespace std;

// 初步思路：递归方法，深度优先，当前节点到子树叶节点的路径为当前节点和子树节点的拼接
// 进阶思路：昨天睡前想到的！呜呜呜！然后醒来忘了！再看了标准答案又想起来了呜呜！
// 广度优先搜索，两个队列维护： ① 节点队列；② 根节点到当前节点路径字符串队列

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return{};

        vector<string> ans;
        
        queue<TreeNode*> que;
        queue<string> path;
        
        que.push(root);
        path.push(to_string(root->val));

        TreeNode* cur_node;
        string cur_str;

        while(!que.empty())
        {
            cur_node = que.front();
            cur_str = path.front();

            que.pop();
            path.pop();

            if(!cur_node->left && !cur_node->right)
            {
                ans.push_back(cur_str);
                continue;
            }

            if(cur_node->left)
            {
                que.push(cur_node->left);
                path.push(cur_str+"->"+to_string(cur_node->left->val));
            }

            if(cur_node->right)
            {
                que.push(cur_node->right);
                path.push(cur_str+"->"+to_string(cur_node->right->val));
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         if(!root) return {}; // 空节点
        
//         string root_str = to_string(root->val);

//         if(!root->left && !root->right) return {root_str};

//         // 每次都要完整遍历一次感觉特别不优雅
//         vector<string> left_vec = binaryTreePaths(root->left);
//         for(string& left_str : left_vec){
//             left_str = root_str + "->" + left_str;
//         }
//         vector<string> right_vec = binaryTreePaths(root->right);
//         for(string& right_str : right_vec){
//             right_str = root_str + "->" + right_str;
//         }

//         // 利用insert()函数以及向量的begin()和end()迭代器将两个向量合并
//         left_vec.insert(left_vec.end(),right_vec.begin(),right_vec.end());
        
//         return left_vec;
//     }
// };
// @lc code=end

