/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <string>
// string标准库用法 p75

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int len = s.size();
        // int整数相除向下取整；
        // 可利用(double)2/5强制类型转换得到0.4
        int half_len = len/2 + 1;
        for(int i=0; i<half_len; i++)
        {
            if(s[i] != s[len-i-1])
            {return false;}
        }
        return true;
    }
};
// @lc code=end

