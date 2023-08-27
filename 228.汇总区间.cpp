/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

#include <vector>
#include <string>

using namespace std;

// 初步思路：只保证当前元素及之前所有元素的正确
// 设定三个数字：当前数字，前一数字，字符串开头数字
// ① 若当前数字减前一数字为1，它并不会出现在cur_str中，过
// ② 若不为1，需要将cur_str加入vector，分两种情况：
// pre_int != start_int，cur_str需带->
// pre_int == start_int，cur_str无需做改动
// ③ 此时cur_str为当前元素，且start_str更新
// ④ 遍历结束，需将最后一个cur_str加入vector，也分两种情况：
// pre_int != start_int和pre_int == start_int

// 出现问题：Overflow，改采用pre_int+1 == cur_int

// 改进：双指针，不从遍历的角度，而从找到下一个字符串元素的角度
// 首先确定low，在for中加while，根据+1 && <n条件确定high
// 判断low==high，进而确定字符串元素
// 下一次查找从low=high+1开始，for(int i=0,j; i<siz; i=j+1)

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        
        vector<string> ans;
        string cur_str;
        
        int cur_int = nums[0];
        int start_int = nums[0];
        int pre_int;

        cur_str = to_string(cur_int);
        int siz = nums.size();

        for(int i=1; i<siz; i++)
        {
            cur_int = nums[i];
            pre_int = nums[i-1];

            if(pre_int+1 == cur_int){
                continue;
            }
            else if(pre_int != start_int){
                cur_str = cur_str + "->" + to_string(pre_int);
            }

            ans.emplace_back(cur_str);
            
            cur_str = to_string(cur_int);
            start_int = cur_int;
        }
        
        if(cur_int != start_int){
            cur_str = cur_str + "->" + to_string(cur_int);
        }
        ans.emplace_back(cur_str);

        return ans;
    }
};
// @lc code=end

