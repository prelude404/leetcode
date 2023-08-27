/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <stack>

using namespace std;

// 每个操作均摊时间复杂度为O(1)：设置in_stack和out_stack
// 所有push均进入in_stack，所有pop和peek均取自out_stack
// 当out_stack为空时，in_stack所有元素放入out_stack（栈底变栈顶/队首）
// push和empty为O(1)，pop和peek均摊为O(1)（每个元素出入栈各2次）

// @lc code=start
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
private:
    stack<int> s1,s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

