/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>

using namespace std;

// 初步思路：分治(Divide and Conquer) + 递归
// 需要考虑target存在于nums中和不存在于nums中的情况
// 考虑的情况过多使得递归并不简洁==》搜索插入位置只需索引计算和数值比较

// 二分法的索引边界条件很值得考虑！！！

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // 空时left和right均为0，返回0，无需特殊化
        while(left < right)
        {
            // 利用二进制数右移一位则除以2的特性
            // 防止(right+left)造成的溢出且效率比除法高
            int mid = ((right - left) >> 1) + left;
            
            // 个人理解：无论target是否存在于数组nums中
            // 采用这种方式可以保证插入的left <= index <= right
            if(target <= nums[mid])
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left; // 最终left和right一定相等
    }
};

// class Solution {
// private:
//     int dcInsert(vector<int>& nums, int target, int low, int high)
//     {
        
//         int mid = (low+high)/2;
//         int num_mid = nums[mid];
        
//         if(low == high){return low;} // 末端情况1
        
//         if((high-low)==1) // 末端情况2
//         {
//             if(target == nums[low]) {return low;}
//             else {return high;}
//         }

//         // 保证分治后的（nums[low] <= target <= nums[high]）
//         if(target < num_mid)
//         {
//             return dcInsert(nums, target, low, mid);;
//         }
//         else if(target > num_mid)
//         {
//             return dcInsert(nums, target, mid, high);
//         }
//         else
//         {
//             return mid;
//         }
//     }

// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int low_index = 0;
//         int high_index = nums.size()-1;
//         // 排除target在数组范围之外的情况再进行分治
//         if(target < nums[low_index]) {return low_index;}
//         else if(target > nums[high_index]) {return (high_index+1);}
//         else {return dcInsert(nums, target, low_index, high_index);}
//     }
// };
// @lc code=end

