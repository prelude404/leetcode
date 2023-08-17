/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <vector>
#include <algorithm>

using namespace std;

// 只能想到：遍历所有情况，记录赚钱最多的一种（时间复杂度O(n^2)）
// 看了答案：遍历一轮，记录历史最低价，当前赚钱最多为当天价格减历史最低价，时间复杂度O(n)

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int pre_low = prices[0]; // 历史最低价格
        int cur_pri = prices[0]; // 当天股票价格
        
        int profit = 0;
        int siz = prices.size();
        
        for(int i=1; i<siz; i++)
        {
            cur_pri = prices[i];
            if(cur_pri < pre_low){
                pre_low = cur_pri;
            }
            else if(cur_pri-pre_low > profit){
                profit = cur_pri-pre_low;
            }
        }
        
        return profit;
    }
};
// @lc code=end

