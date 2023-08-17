/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include <vector>

using namespace std;

// 初步思路：前一层的节点在下一层都有左节点和右节点
// 前一层相邻节点的右/左节点指向的是同一节点
// 由队列进行数据维护，存储节点值并放入向量

// 然而：并未给出TreeNode的定义，考虑直接利用下标计算

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // if(!numRows) {return {};} // 指定size为0时也为空
        
        vector<vector<int>> ans(numRows);
        // ans[0] = {1};
        
        for(int cur_num=0; cur_num<numRows; ++cur_num)
        {
            // vector<int> cur_row(cur_num+1); // 大小为行索引+1
            ans[cur_num].resize(cur_num+1); // 想要使用索引就得先把size弄对
            ans[cur_num][0] = ans[cur_num][cur_num] = 1; // 可以连着赋值

            for(int i=1; i<cur_num;++i)
            {
                ans[cur_num][i] = ans[cur_num-1][i-1] + ans[cur_num-1][i];
            }
        }

        return ans;
    }
};
// @lc code=end

