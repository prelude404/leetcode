/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <string>
#include <unordered_map>

// 问题本质：如果小数a在大数b左侧，则减去它；否则加上它
// 可以写一个private的函数来获取字符

using namespace std;

// @lc code=start

class Solution {
private:
// 利用无序无重复地图，通过关键字查找值，进行字母转数字；也可使用输入为char输出为int的函数求取
unordered_map<char,int> num_val = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

public:
    int romanToInt(string s) {
        int num=0; // num要初始化
        int len = s.size();
        int cur;
        for(int i=0; i<len; i++)
        {
            cur = num_val[s[i]];
            // 还有后一位字母 且 当前位比后一位大时：减去当前位对应数字
            if(i<len-1 && cur < num_val[s[i+1]])
            {
                num -= cur;
                continue;
            }
            // 其他情况均为加
            num += cur;
        }
        return num;
    }
};

/***未考虑数学本质，未使用哈希表和私有函数，仅利用switch枚举***/
// class Solution {
// public:
//     int romanToInt(string s) {
//         int num=0;//num要初始化
//         int len = s.size();
//         int i=0;
//         while(i<len)
//         {
//             switch(s[i]){
//                 case 'I':
//                     i++;
//                     if(s[i]=='V' && i<len)
//                     {num += 4;i++;}
//                     else if(s[i]=='X' && i<len)
//                     {num += 9;i++;}
//                     else{num += 1;}
//                     break;
                
//                 case 'X':
//                     i++;
//                     if(s[i]=='L' && i<len)
//                     {num += 40;i++;}
//                     else if(s[i]=='C' && i<len)
//                     {num += 90;i++;}
//                     else{num += 10;}
//                     break;

//                 case 'C':
//                     i++;
//                     if(s[i]=='D' && i<len)
//                     {num += 400;i++;}
//                     else if(s[i]=='M' && i<len)
//                     {num += 900;i++;}
//                     else{num += 100;}
//                     break;

//                 case 'V':
//                     i++;
//                     num += 5;
//                     break;
                
//                 case 'L':
//                     i++;
//                     num += 50;
//                     break;
                
//                 case 'D':
//                     i++;
//                     num += 500;
//                     break;
                
//                 case 'M':
//                     i++;
//                     num += 1000;
//                     break;
//             }
            
//         }
//         return num;
//     }
// };

// @lc code=end

