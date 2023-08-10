/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <vector>

// 思路：双指针
// 快指针表示遍历数组到达的下标位置(i)
// 慢指针表示下一个不同元素要填入的下标位置(k)

using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        if(nums.empty()){return 0;}

        int pre_num = nums[k];
        int len = nums.size();

        for(int i=1; i<len; ++i)
        {
            if(nums[i]>pre_num)
            {
                k++;
                nums[k] = nums[i];
                pre_num = nums[k];
            }
        }

        return (k+1); // k为索引号，作为不重复数字个数时需+1
    }
};
// @lc code=end

