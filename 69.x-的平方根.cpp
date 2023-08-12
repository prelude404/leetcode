/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

#include <string>

using namespace std;

// 初步思路：一个n位数的平方根一定在10^(n/2)到10^(n/2+1)之间（用了指数！）
// 由此确定初步范围[low,high]，再对该范围进行二分，比较mid^2和该数
// 时间复杂度O(log(x))，空间复杂度O（1）

// 方法2：利用自带的指数函数和对数函数计算
// ans = exp(0.5 * log(x))（作弊啊！这是作弊啊！！
// 由于存储位数有限可能会导致结果不准确

// 方法3：牛顿迭代法（二次收敛，所以比二分法快）
// 答案为 f(x) = x^2 -C 的零点
// x_i+1 = x_i - f(x_i) / f’(x_i) = 0.5 * (x_i + C/x_i)

// 整型int的溢出问题：
// int类型通常是32位，其范围是从-2^31到2^31-1
// long long和int64_t类型是64位
// 该程序中，mid*mid可能会造成溢出
// mid low high均为int，令long long square = static_cast<long long>(mid) * mid
// long long square = mid*mid不行，或许是因为赋值（类型转换）是在乘法之后进行
// 或是令mid和square均为long long类型


// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0) {return 0;}
        
        // 利用字符串的长度获取平方根的范围（不适用于0）
        string xStr = to_string(x);
        int digits = xStr.size() - 1; // 去除开头一位
        
        string lowStr = "1" + string(digits/2,'0');
        string highStr = "1" + string(digits/2+1,'0');
        
        int low = stoi(lowStr);
        int high = stoi(highStr);

        // 二分法计算平方根
        while(low<high)
        {
            long long mid = (low+high)/2 + 1;
            // +1 是为了防止在(high-low)==1时不再进行

            long long square = mid*mid;

            if(square > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid;
            }
        }

        return low; // 最终low==high
    }
};
// @lc code=end

