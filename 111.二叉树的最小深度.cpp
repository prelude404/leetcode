/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

#include <queue>
// <algorithm>中有min和max函数
// <deque>是双端队列，在队首和队尾都可以push和pop

using namespace std;

// 最小深度：从根节点到最近叶子节点的最短路径上的节点数量
// 叶节点：既没有左子节点又没有右子节点的节点

// 初步思路：队列进行广度优先搜索，遇到叶节点则return当前层数

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
    int minDepth(TreeNode* root) {
        
        if(!root) {return 0;}

        int ans = 0;
        queue<TreeNode*> q;
        
        q.push(root);

        while(!q.empty())
        {   
            ans++; // 即当前处理层

            int siz = q.size(); // 当前层个数

            while(siz > 0)
            {
                TreeNode* cur = q.front(); // 获取队首尾元素(front()和back())
                q.pop(); // 弹出队首元素返回void（pop()和push(*)）
                
                if(!cur->left && !cur->right){
                    return ans; // 一旦到达叶节点，则为最短，返回
                }
                
                if(cur->left){
                    q.push(cur->left);
                }
                
                if(cur->right){
                    q.push(cur->right);
                }

                siz--;
            }
        }
        return ans;
    }
};
// @lc code=end

