/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

#include <string>
#include <unordered_map>

// 初步思路：与205题相似，构建两个字典判断一一映射关系
// 额外工作：需要对s中的“下一个单词”进行提取

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int siz_p = pattern.size();
        int siz_s = s.size();

        unordered_map<char,string> dic_ps;
        unordered_map<string,char> dic_sp;

        char cur_p;
        string cur_s;
        int i=0,j = 0;

        while(i<siz_p && j<siz_s)
        {
            cur_p = pattern[i];
            i++;
            
            cur_s = "";

            while(s[j]!=' ' && j<siz_s)
            {
                cur_s += s[j];
                j++;
            }

            while(s[j]==' ' && j<siz_s)
            {
                j++;
            }

            if(!dic_ps.count(cur_p)){
                dic_ps[cur_p] = cur_s;
            }
            else if(dic_ps[cur_p] != cur_s){
                return false;
            }

            if(!dic_sp.count(cur_s)){
                dic_sp[cur_s] = cur_p;
            }
            else if(dic_sp[cur_s] != cur_p){
                return false;
            }
        }

        if(i!=siz_p || j!=siz_s){
            return false;
        }

        return true;
    }
};
// @lc code=end

