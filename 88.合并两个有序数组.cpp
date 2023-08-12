/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <vector>

using namespace std;

// 初步思路：从后向前遍历，双指针，谁大谁放
// 逆向双指针相比于正向的优点：空间复杂度由O(m+n)变为O(1)
// 一些改进：可以将i_1==-1和i_2==-1时的赋值也写进while里，条件变为(i_1>=0 || i_2>=0)

// 方法2：先将nums2全部放入nums1末尾再使用sort()


// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i_1 = m-1;
        int i_2 = n-1;
        int i = m+n-1;

        if(!n){return;}
        if(!m){nums1 = nums2; return;}
        
        while(i_1>=0 && i_2>=0)
        {
            if(nums1[i_1]>nums2[i_2])
            {
                nums1[i] = nums1[i_1];
                i_1--;
                i--;
            }
            else
            {
                nums1[i] = nums2[i_2];
                i_2--;
                i--;
            }
        }
        if(i_1>=0)
        {
            return;
        }
        else
        {
            while(i_2>=0)
            {
                nums1[i_2] = nums2[i_2];
                i_2--;
            }
        }
    }
};
// @lc code=end

