/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

#include <string>

using namespace std;

// 初步思路：一个n位数的平方根一定在10^(n/2)到10^(n/2+1)之间（用了指数！）
// 由此确定初步范围[low,high]，再对该范围进行二分，比较mid^2和该数


// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        string xStr = to_string(x);
        int digits = xStr.size();
        
    }
};
// @lc code=end

