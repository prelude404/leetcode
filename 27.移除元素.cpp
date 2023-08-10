/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>

using namespace std;

// 本题解法：快慢双指针法
// 优化：左右双指针法（直接把数组最右侧赋给左侧相等位置）
// int n = nums.size();
// int left = 0;
// for (int right = 0; right < n; right++) {
//     if (nums[right] != val) {
//         nums[left] = nums[right];
//         left++;
//     }
// }
// return left;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int slow(0),fast(0);
        if(nums.empty()){return 0;}
        while(fast<len)
        {
            if(nums[fast]!=val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end

