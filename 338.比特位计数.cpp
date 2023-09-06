/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include <vector>

using namespace std;

// basic idea：以某种方式得到关于更小数字比特位计数的表达式

// 初步思路：每一次进位，都是0~n-1的重复（再加1）
// 即最高有效位方法[动态规划]：去掉最高位的1再在结果加1
// 时间复杂度O(N)，空间复杂度O(1)
// 缺点：需要维护更新最高有效位pre_index

// 方法2：最低有效位[动态规划]，去掉最低位再在结果加除2的余数
// bits[x] = bits[⌊x/2​⌋] + x%2

// 方法3：最低设置位[动态规划]，把最低位的1变成0再加1
// bits[x]=bits[x & (x−1)]+1

// 动态规划（Dynamic Programming，简称 DP）将问题分解为子问题，并保存子问题的解，避免重复计算，从而提高算法的效率。
// 动态规划常常用于解决具有重叠子问题和最优子结构性质的问题。
// 基本步骤：定义子问题；建立状态转移方程；解决基本问题；自底向上计算；返回最终解


// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        int i=1;
        int pre_index;
        
        while(i<=n)
        {
            // 进位情况（==的优先级高于&，会先计算，故加括号）
            if((i & (i-1)) == 0)
            {
                pre_index = i;
            }
            ans[i] = 1 + ans[i-pre_index];
            i++;
        }

        return ans;
    }
};
// @lc code=end

