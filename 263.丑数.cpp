/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// 初步思路：将2、3和5的因数除尽，判断结果是否为1
// 注意：负数和零均不是丑数
// 先5再3再2可以使数字缩小更快，位数少的数字计算也更快

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        while(n%5 == 0) n/=5;
        while(n%3 == 0) n/=3;
        while(n%2 == 0) n/=2;
        if(n==1) return true;
        else return false;
    }
};
// @lc code=end

