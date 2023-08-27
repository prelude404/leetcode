/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <vector>
#include <unordered_map>

using namespace std;

// 初步思路：哈希表，令map的键为数字，值为上一次出现的index
// 时间复杂度O(N)，空间复杂度O(N)

// 方法2：哈希表，滑窗内元素构成set
// 时间复杂度O(N)，空间复杂度O(k)

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> dic;
        int siz = nums.size();
        
        for(int i=0; i<siz; i++)
        {
            if(dic.count(nums[i]) && (i-dic[nums[i]]) <= k){
                return true;
            }
            else{
                dic[nums[i]] = i;
            }
        }

        return false;
    }
};
// @lc code=end

