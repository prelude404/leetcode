/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// 初步思路：2的幂大于等于1，且除2取余始终为0

// 方法2：位运算，2的幂的二进制表达为100...0
// return n > 0 && (n & (n - 1)) == 0;
// return n > 0 && (n & -n) == n;

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        
        while(n>1){
            if(n%2 == 1) return false;
            n /= 2;
        }

        return true;
    }
};
// @lc code=end

