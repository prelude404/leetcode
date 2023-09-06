/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// 答案方法2：利用规律 4^x ≡ (3+1)^x ≡ 1^x ≡ 1 (mod 3)
// 2 * 4^x ≡ 2 * (3+1)^x ≡ 2 * 1^x ≡ 2 (mod 3)

// 答案方法1：4的幂为2的幂且1在奇数位上，即100...0后面有偶数个0
// 构建 mask=(10101010101010101010101010101010)_2 即 mask=(AAAAAAAA)_16​
// 二进制前缀“Ob/OB”；八进制前缀“0”；十六进制前缀“Ox/OX”

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        // return n>0 && (n & (n-1)) == 0 && n % 3 == 1;
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};
// @lc code=end

