/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <string>
// #include <algorithm>

// 初步思路：“列竖式”，倒序相加，记录进位，该位结果+之前结果拼接
// 剩余部分直接拼接（不进位），调用自身add(rest,"1")再拼接
// 代码缺陷：具体数位如何相加是用穷举实现的；一个字符串空后需要对剩余的单独操作

// 一些改进：
// reverse(a.begin(),a.end());先将字符串倒序最后再倒回来
// a[i_a]=='1'可以记为1，其他（空或0）均为0
// 由sum记录该位加和结果：sum%2为该位的计算结果；sum/2为该位的进位结果
// int num = a.charAt(i_a)-'0'可以由字符串计算数值

using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        string result;
        
        int i_a = a.size()-1;
        int i_b = b.size()-1;
        
        if(a == "0")return b;
        if(b == "0")return a;

        while(i_a >= 0 && i_b >= 0)
        {
            if(a[i_a]=='0' && b[i_b]=='0')
            {
                if(carry){
                    result = "1" + result;
                    carry = false;
                }
                else{
                    result = "0" + result;
                }
            }
            else if(a[i_a]=='1' && b[i_b]=='1')
            {
                if(carry){
                    result = "1" + result;
                }
                else{
                    result = "0" + result;
                    carry = true;
                }
            }
            else
            {
                if(carry){
                    result = "0" + result;
                }
                else{
                    result = "1" + result;
                }
            }
            i_a--;
            i_b--;
        }
        if(i_a == i_b)
        {
            if(carry){
                return ("1"+result);
            }
            else{
                return result;
            }
        }
        else if(i_a < i_b)
        {
            if(carry){
                return (addBinary(b.substr(0,(i_b+1)),"1")+result);
            }
            else{
                return (b.substr(0,(i_b+1))+result);
            }
        }
        else
        {
            if(carry){
                return (addBinary(a.substr(0,(i_a+1)),"1")+result);
            }
            else{
                return (a.substr(0,(i_a+1))+result);
            }
        }
    }
};
// @lc code=end

