/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// 变量的作用域在其定义的代码块内部
// for, do-while, if-else语句内部定义的变量在循环/条件语句外部不可访问

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre_str(strs[0]);
        int len(strs.size());
        int pre_len(pre_str.size());
        for(int i=1; i<len; i++)
        {
            // 不断获取pre_str与strs[i]的最长公共前缀
            int j=0;
            while(pre_str[j]==strs[i][j] && j<pre_len) {j++;}
            pre_len = j;
            pre_str = pre_str.substr(0,j);
            if(!j) return ""; // 前i项无相同前缀时已可直接返回
        }
        return pre_str;
    }
};
// @lc code=end

