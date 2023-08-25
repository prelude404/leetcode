/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

#include <string>
#include <unordered_map>

using namespace std;

// 初步思路：利用字典对于每个pair进行判断
// 需要保证s到t，t到s均为一对一的映射，故使用两个字典

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> check_s,check_t;
        int siz = s.size();
        char c_s,c_t;
        
        for(int i=0; i<siz; i++)
        {
            c_s = s[i];
            c_t = t[i];
            
            // s到t，t到s均为一对一的映射
            if(check_s.find(c_s) == check_s.end()){
                check_s.emplace(c_s,c_t);
            }
            else if(check_s[c_s] != c_t){
                return false;
            }

            if(check_t.find(c_t) == check_t.end()){
                check_t.emplace(c_t,c_s);
            }
            else if(check_t[c_t] != c_s){
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

