/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include <vector>

using namespace std;

// 题目难点：时间复杂度O(N)，空间复杂度O(1)
// 查看解析：使用异或运算⊕
// 1.任何数和0做异或运算，结果仍然是原来的数，即 a⊕0 = a
// 2.任何数和其自身做异或运算，结果是0，即 a⊕a = 0
// 3.异或运算满足交换律和结合律，即 a⊕b⊕a = b⊕a⊕a = b⊕(a⊕a) = b⊕0 = b

// 利用信息：除了某个元素只出现一次以外，其余每个元素均出现两次

/***位运算***/
// 与运算（AND）： 对应位上的两个操作数都为1时，结果为1，否则为0。(&)
// 或运算（OR）： 对应位上的两个操作数都为1时，结果为1，否则为0。(|)
// 异或运算（XOR）： 对应位上的两个操作数相同时，结果为0，不同时结果为1。(^)
// 取反运算（NOT）： 将位的值取反，1变为0，0变为1。(~)
// 左移（<<）： 将位向左移动指定的位数，右边补0，用于乘以2的幂。(<<)
// 右移（>>）： 将位向右移动指定位数，左边补0或补符号位，用于除以2的幂。(>>)

/***基于范围的for循环***/
/*** for(element_declaration : range_expression){statement} ***/
// for(auto e : v){}：e为v中的每个元素，auto进行自动的类型推导，以值访问，无法修改
// for(auto& e : v){}：引用访问，可以修改v中的元素
// for(const auto& e : v){}：引用访问，无法修改v中的元素，但不存在值访问的拷贝

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(const auto& e:nums){
            ans ^= e;
        }
        return ans;
    }
};
// @lc code=end

