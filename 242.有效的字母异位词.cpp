/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <unordered_map>
// 不能使用<unordered_map>进行遍历比较，一般它使用迭代器进行迭代
// 即使无序映射的键值对完全相同，它们遍历的顺序也可能不同
// 除非在保证键值对数量相同情况下，对一个unordered_map进行迭代与另一个比较
using namespace std;

// 进阶思路：遍历string时，一个键对应的值++，另一个键对应的值--
// 最后遍历map判断每个键对应的值是否为0

// 其他思路：异位词相当于排序以后相等，直接return s_sorted == t_sorted

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int> hash;
        int siz = s.size();
        char cur;
        
        for(int i=0; i<siz; i++)
        {
            cur = s[i];
            if(hash.count(s[i])){
                hash[cur]++;
            }
            else{
                hash.emplace(cur,1);
            }
        }

        for(int i=0; i<siz; i++)
        {
            cur = t[i];
            if(hash.count(cur)){
                hash[cur]--;
            }
            else{
                return false;
            }
        }

        for(const auto& pair : hash){
            if(pair.second != 0) return false;
        }

        return true;
    }
};
// @lc code=end

