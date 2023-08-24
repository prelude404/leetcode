/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

#include <string>

using namespace std;

// 初步思路：number=i=∑_0^(n−1)​a_i​×26^i（26进制）

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int siz = columnTitle.size();
        char cur_al;
        int cur_num;
        int tot_num = 0;
        
        for(int i = 0; i < siz; i++)
        {
            cur_al = columnTitle[i];
            cur_num = cur_al - 'A' + 1;
            tot_num = tot_num * 26 + cur_num;
        }

        return tot_num;
    }
};
// @lc code=end

