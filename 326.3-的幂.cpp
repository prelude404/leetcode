/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// 初步思路：除三取余
// 答案取巧：找到32位有符号整数中最大的3的幂，判断n是否为其约束
// 最大的3的幂：3^19=1162261467

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467 % n == 0;
    }
};
// @lc code=end

