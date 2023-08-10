/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>

// 初步思路：加一直到不进位为止

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1; // 当前所在数位，从后往前遍历
        bool carry = true; // 判断当前数位是否造成进位，进位的话前一项需加一
        
        while(carry && i>=0)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
            }
            else
            {
                digits[i]++;
                carry = false;
            }
            i--;
        }

        // 如果进位已经到头了且仍需要进位
        // 说明出现了999+1 = 1000这种情况，直接新建一个vector
        if(i==-1 && carry == true)
        {
            vector<int> expand(digits.size()+1,0);
            expand[0] = 1;
            return expand;
        }
        else
        {
            return digits;
        }
    }
};
// @lc code=end

