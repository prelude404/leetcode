/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// 初步思路：root的左右子树在相反的搜索方式下（左右/右左）是相同的

// 迭代方法：采用队列结构进行广度优先搜索，队列结构维系
// 把根节点加入队列两次，每次出队列两个节点比较是否相同
// 入队列其中一个的左（右）节点和另一个的右（左）节点
// 判断是否存在时需随时false出去
// 可以保证每次出队列的两个节点是镜像节点

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
    bool isSymmetric(TreeNode* root) {
        
        if(!root) {return true;} // 空树

        return isSameTree(root->left, root->right);
    }

private:
    bool isSameTree(TreeNode* n_left, TreeNode* n_right){
        
        // 把判断节点是否存在的语句写在开头，而不是用复杂的if
        if(!n_left && !n_right) {return true;}
        if(!n_left || !n_right) {return false;}
        
        if(n_left->val != n_right->val) {return false;}

        return isSameTree(n_left->left, n_right->right)
            && isSameTree(n_left->right, n_right->left);

        // if(!n_left->left && !n_right->right)
        // {
            
        //     if(!n_left->right && !n_right->left){
        //         return true;
        //     } // 外侧内侧均为空
            
        //     if(n_left->right && n_right->left){
        //         return isSameTree(n_left->right, n_right->left);
        //     } // 外侧为空，内侧存在
        // }
        // else if(n_left->left && n_right->right)
        // {
        //     if(!n_left->right && !n_right->left){
        //         return isSameTree(n_left->left, n_right->right);
        //     } // 外侧存在，内侧为空

        //     if(n_left->right && n_right->left){
        //         return isSameTree(n_left->left, n_right->right)
        //             && isSameTree(n_left->right, n_right->left);
        //     } // 外侧内侧均存在
        // }
        
        // return false; // 子节点存在情况不一致（这句不能写在else里）
    }
};
// @lc code=end

