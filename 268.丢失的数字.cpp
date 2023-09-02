/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

#include <vector>

using namespace std;

// 时间复杂度O(N)，空间复杂度O(1)
// 题干重点：nums.size=n; 0<=i<=n-1,0<=nums[i]<=n
// 初步思路：扩展nums的size为n+1，此时0<=i<=n，遍历数组，
// 所有数组中数字对应的索引格子均改为-1，之后再遍历一次，看是否有不是-1的
// 出现问题：最后一个格子，nums[curr]==curr，出问题时寻找下一索引要花时间
// 根本问题：索引已经使用过和索引已被到达过并不是同一件事！！

// 其他方法：
// ① 排序，并判断排序后数字下标与数字是否相等：时间O(NlogN)，空间O(N)
// ② 使用一个n+1大小数组（或哈希表）额外保存是否被到达过：时间O(N)，空间O(N)
// ③ 利用位运算x⊕x=0和x⊕0=x，在数组后再添加0-n全部数字，遍历(n+n+1)个数得到缺失的数：时间O(N)，空间O(N)
// ④ 利用高斯求根公式，逐个减去判断缺了谁：时间O(N)，空间O(1)

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum = n * (n+1) >> 1;
        for(int i=0; i<n; i++)
        {
            sum -= nums[i];
        }
        return sum;
    }
};
// @lc code=end

