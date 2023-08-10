/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <string>

using namespace std;
// 本题思路用word判断是否到达最后一个单词
// 延伸：使用两个while（遍历尾部空格+遍历最后一个单词）

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int len = s.size();
        bool word = false; // 判断是否到达最后一个单词
        for(int i=s.size()-1; i>=0; i--)
        {
            if(!word)
            {
                if(s[i]==' ')
                {
                    continue;
                }
                else
                {
                    count += 1;
                    word = true;
                }
            }
            else
            {
                if(s[i]==' ')
                {
                    break;
                }
                else
                {
                    count += 1;
                }
            }
        }
        return count;
    }
};
// @lc code=end

