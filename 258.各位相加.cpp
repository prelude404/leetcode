/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// 初步思路：循环模拟，时间复杂度O(log(num))
// 时间空间复杂度O(1)方法：return (num - 1) % 9 + 1;

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        while(num > 9)
        {
            int temp = 0;
            while(num>0)
            {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        return num;
    }
};
// @lc code=end

