/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

#include <vector>
#include <unordered_set>

using namespace std;

// 初步思路：哈希表，遍历nums并放入set，判断当前元素是否在set中
// 时间复杂度O(N)，空间复杂度O(N)

// 方法2：排序后判断相邻元素是否相等
// 时间复杂度O(logN)，空间复杂度O(1)

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> set;
        int siz = nums.size();
        
        for(int i=0; i<siz; i++)
        {
            if(set.count(nums[i])) return true;
            set.emplace(nums[i]);
        }

        return false;
    }
};
// @lc code=end

