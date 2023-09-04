/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// 初步思路：以4为一轮

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};
// @lc code=end

