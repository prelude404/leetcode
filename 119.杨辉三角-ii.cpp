/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre_row(0);
        vector<int> cur_row(1,1);
        
        for(int i=1; i<=rowIndex; ++i)
        {
            pre_row = cur_row;
            cur_row.resize(i+1);
            cur_row[0] = cur_row[i] = 1;
            for(int j=1; j<i; j++)
            {
                cur_row[j] = pre_row[j-1] + pre_row[j];
            }
        }

        return cur_row;
    }
};
// @lc code=end

