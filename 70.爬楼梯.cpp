/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// 一切程序均为优雅的遍历

// 初步思路：以2的个数结合组合数进行遍历（需计算阶乘，造成整型溢出）

// 方法2：最后一阶只有跨1阶或2阶两种可能，由此划分时间复杂度O(n)
// 则f(n)=f(n-1)+f(n-2),f(1)=1,f(2)=2
// 方法3：可以写成矩阵形式，由矩阵快速幂计算
// 方法4：恰好为斐波那契数列，有计算的通项公式

// 矩阵快速幂 O(log(n))（快速幂：可以理解为一种分治）
// n: 阶数； a: 底数（数或矩阵）； b: n在该位的二进制数 
// 任何指数n均可以表示为n = b0 + b1 * 2 + b2 * 2^2 + ... + bk * 2^k (bk=0or1)
// 那么a^n =  a^(b0) * a^(b1 * 2) * a^(b2 * 2^2) * ... * a^(bk * 2^k)
// 由a^(2^i)的结果可以得到a^(2^(i+1))的结果

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        vector<vector<long long>> mat = {{1,1},{1,0}};
        
        if(n==1){return 1;}

        vector<vector<long long>> ans = pow_mat(mat, n-2);

        return (2*ans[0][0] + ans[0][1]);
    }

private:
    vector<vector<long long>> mult_mat(vector<vector<long long>> a, vector<vector<long long>> b)
    {
        vector<vector<long long>> c(2, vector<long long>(2, 0)); // 需要初始化分配内存
        for(int i=0; i<2; ++i)
        {
            for(int j=0; j<2; ++j)
            {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
    
    vector<vector<long long>> pow_mat(vector<vector<long long>> mat, int n)
    {
        // if(n==0)
        // {
        //     vector<vector<int>> eye = {{1,0},{0,1}};
        //     return eye;
        // }
        // else if(n==1)
        // {
        //     return mat;
        // }
        // else{
        //     vector<vector<int>> mat_half = pow_mat(mat,n/2);

        //     if(n%2 == 1)
        //     {
        //         return mult_mat(mat,mult_mat(mat_half,mat_half));
        //     }
        //     else{
        //         return mult_mat(mat_half,mat_half);
        //     }
        // }

        // 不使用递归，直接迭代
        vector<vector<long long>> result = {{1,0},{0,1}};

        while(n>0)
        {
            if(n%2 == 1){
                // 二进制的该位存在，则乘上去
                result = mult_mat(result,mat);
            }

            // 最后一次可能会造成溢出，所以类型均改为long long
            // 注意mat和n的变化！！！
            // 底层逻辑可用于十进制转二进制
            mat = mult_mat(mat,mat);
            n /= 2;
        }

        return result;
    }
};

/*** 计算阶乘会造成溢出，即使换成long long也不够 ***/

// class Solution {
// public:
//     int climbStairs(int n) {
//         int lim_2 = n/2; // 最多2阶数
//         int ans = 0;

//         // 储存0!到n!的结果
//         int fac[n+1];
//         fac[0] = 1;
//         for(int i=1; i<=n; ++i)
//         {
//             fac[i] = i * fac[i-1];
//         }

//         // 加和全部情况（i为2阶个数）
//         for(int i=0; i<=lim_2; ++i)
//         {
//             int c_nk = fac[n-i] / (fac[i] * fac[n-2*i]);
//             ans += c_nk;
//         }

//         return ans;
//     }
// };

// @lc code=end

