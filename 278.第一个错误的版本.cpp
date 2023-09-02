/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

// 初步思路：双指针low与high，通过判断mid的好坏进行二分查找

// @lc code=start

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int mid;
        
        while(low < high)
        {
            // 防止整型运算的溢出
            mid = (high-low)/2 + low;

            if(isBadVersion(mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }
};
// @lc code=end

