/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include <string>
#include <cctype>

using namespace std;

// cctype库：字符处理库
// 检查字符属性（大小写、字母、数字、空白），转换字符大小写
// isalnum(int c): 检查字符是否为字母或数字
// tolower(int c): 将字符转换为小写形式（对数字不起作用）

// 初步思路：0到size/2的遍历判断
// 实现前提：大小写转换，数字的保留，非字母数字的去除

// 看了答案之后：左右双指针遍历，关键在会用cctype库
// 方法2：1.遍历去除非字母数字并变小写；
//       2.构建一个反向字符串 string s1_rev(s1.rbegin(), s1.rend());
// rbegin()和rend()是字符s1的反向迭代器（reverse iterators）的开始和结束位置
//       3.返回字符串比较结果 return s1 == s1_rev


// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            
            if(!isalnum(s[left]) || !isalnum(s[right])){
                break;
            }
            
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }
        
        return true;
    }
};
// @lc code=end

