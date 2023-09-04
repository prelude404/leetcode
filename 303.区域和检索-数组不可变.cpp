/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// 初步思路：拷贝构造，遍历求和
// 看了答案：既然只用求和，构造时存储0-i,0-j的和，之后相减即可
// 另一思路：惰性计算，用一个count记录当前算到的位数，当j>count时才继续算到j

#include <vector>

using namespace std;

// @lc code=start
class NumArray {
private:
    vector<int> sum_array;

public:
    NumArray(vector<int>& nums) {
        int siz = nums.size();
        sum_array.resize(siz+1);
        // vector<int> sum_array(siz);
        // sum_array = new vector<int>(siz);
        sum_array[0] = 0;
        for(int i=1; i<=siz; i++)
        {
            sum_array[i] = sum_array[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return(sum_array[right+1]-sum_array[left]);
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

