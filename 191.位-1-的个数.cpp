/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

#include <cstdint>

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i=0; i<32; i++)
        {
            // 位运算
            // count += n & 1;
            // n >>= 1;

            // 十进制（更快）
            count += n % 2;
            n /= 2;
        }
        return count;
    }
};
// @lc code=end

