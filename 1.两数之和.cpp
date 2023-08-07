/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
// vector标准库用法 p86

using namespace std;

/*
1. 暴力搜索，利用i和j进行两层的遍历
2. 哈希表，使得j的查找target-num[i]的时间复杂度变为O(1)
*/

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        // j=i++先赋值再自增；j=++i先自增再赋值；for中无区别
        for(int i=0; i<len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(nums[i]+nums[j]==target)
                {return {i,j};}
            }
        }
        return {};
    }
};
// @lc code=end

