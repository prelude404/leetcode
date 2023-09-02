/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>

using namespace std;

// 初步思路：遍历数组，并记录需要向前移动的量（即零的个数）
// 遇到零则增加移动量，遇到非零则向前移动（准确地说是赋值）
// 最后在数组末尾部分置为零

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_num = 0;
        int siz = nums.size();
        int curr = 0;

        while(curr < siz)
        {
            if(nums[curr]==0){
                zero_num++;
            }
            else{
                nums[curr-zero_num] = nums[curr];
            }
            curr++;
        }

        for(int curr=siz-zero_num; curr<siz; curr++)
        {
            nums[curr] = 0;
        }
    }
};
// @lc code=end

