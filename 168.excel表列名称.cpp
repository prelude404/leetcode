/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

#include <string>

using namespace std;

// 初步思路：相当于将columnNumber转化为26进制数，再将每个位对应字母进行拼接
// A-Z对应的字母应当为1-26，但是直接对26取余得到的结果为1-25,0
// A-Z应直接映射到0-25然后直接加'A'，且若结果是'Z'需在columNumber减去26而不是0

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        // 在循环外定义可以防止每次循环变量副本的重新创建和释放，略微减小内存空间
        int cur_num;
        char cur_al;
        
        while(columnNumber > 0)
        {
            cur_num = (columnNumber - 1) % 26;
            cur_al = 'A' + cur_num;
            ans = cur_al + ans;
            columnNumber = (columnNumber - 1) / 26;
        }

        return ans;
    }
};
// @lc code=end

