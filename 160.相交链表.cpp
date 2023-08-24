/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

#include <cstddef>

using namespace std;

// 看了答案：假设链表A,B的长度分别为a,b，公共部分的长度为c
// 令两指针均遍历相同的长度，并在公共节点处相遇
// l_a = (a-c) + c + (b-c) = a+b-c
// l_b = (b-c) + c + (a-c) = a+b-c
// 若无公共部分，即c=0，此时两指针均遍历完A和B，它们的next应均为nullptr
// 若有公共部分，即c>0，则此时两指针的next应均为公共节点

// 在无公共部分时，如何判断已遍历完(a+b)？
// curA和curB均为空指针
// 若AB长度相同，若有公共部分，在第一轮就已离开循环；若无公共部分，在第一轮就同时为空
// 若AB长度不同且无公共部分，第一轮遍历时不能同时为空；第二轮最后必定同时为空

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return NULL;

        ListNode *curA = headA;
        ListNode *curB = headB;
        
        while(curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
            
            if(!curA && !curB) return NULL;
            
            else if(!curA) curA = headA;
            else if(!curB) curB = headB;
        }

        return curA;
    }
};
// @lc code=end

