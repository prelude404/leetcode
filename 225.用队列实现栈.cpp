/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <queue>

using namespace std;

// 初步思路：标准队列库<queue>维护栈结构
// 利用私有成员queue<int> q进行维护
// <queue>的front()返回队首元素，pop()只弹出队首元素但不返回
// 与队列不符的pop()和top()需将整个队列“遍历”一次
// 时间复杂度：pop()和top()均为O(N)，push(x)为O(1)（需修改）
// 这样不优雅，也不像真的栈结构，不如在push时将队列“遍历”将元素放入队首（栈顶）

// 方法2：利用两个队列维护
// 模拟栈：每次将push(x)时将元素放在队首
// 实现方式：将栈队列q1中全部元素放至辅助队列q2
// q1中放入x后再将q2中元素放回，此时x位于q1的队首（栈顶）
// 时间复杂度：pop()和top()均为O(1)，push(x)为O(N)

// @lc code=start
class MyStack {
public:
    MyStack() {
        // 不需要再对q进行初始化
    }
    
    void push(int x) {
        int siz = q.size();
        q.push(x);
        for(int i=0; i<siz; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();

        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

