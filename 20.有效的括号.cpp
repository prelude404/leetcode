/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <string>
#include <vector>
#include <unordered_map>

// 有直接可使用的栈数据结构，可以不用vector
// #include <stack>


/*** std库中现有的数据结构 ***/
// vector：动态数组，支持随机访问，可以在末尾快速插入和删除元素
// list：双向链表，支持在任意位置插入和删除元素
// queue：队列，支持先进先出（FIFO）的元素访问和操作
// stack：栈，支持后进先出（LIFO）的元素访问和操作
// deque：双端队列，支持在两端快速插入和删除元素
// map 和 unordered_map：关联容器，用于建立键值对映射关系
// set 和 unordered_set：集合容器，用于存储唯一的值
// priority_queue：优先队列，用堆结构实现，允许按照优先级获取和删除元素。
// bitset：位集容器，用于存储和操作位序列
// array：静态数组，大小固定，支持随机访问
// string：字符串，支持字符操作和查找
// tuple：元组，用于存储多个元素，可以是不同类型

using namespace std;

// @lc code=start
class Solution {
private:
// 可以直接使用左括号和右括号配对，无需映射到数字上
// unordered_map<char,char> pairs = {{')','('}, {']','['}, {'}','{'}};
unordered_map<char,int> kuohao = {{'(',1}, {'{',2}, {'[',3}, {')',4}, {'}',5}, {']',6}};

public:
    bool isValid(string s) {
        vector<int> judger;
        int len = s.size();

        if(s.empty()){return true;} // 空字符串，真
        if(s.size()%2 == 1){return false;} // 奇数括号数，假

        for(int i=0; i<len; i++)
        {
            int current = kuohao[s[i]];
            if(current<=3)
            {
                judger.push_back(current); // 左括号，直接入栈
            }
            else if(!judger.empty() && (current-3)==judger.back())
            {
                judger.pop_back(); // 右括号，非空且顶部元素序号对应，才可抵消
            }
            else {return false;}
        }
        return judger.empty(); // 最终栈空，真
    }
};
// @lc code=end

