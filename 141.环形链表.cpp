/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

#include <cstddef>
#include <unordered_set>
// <cstddef>提供了对NULL的定义，c++11之后一般用nullptr

// 初步想法：遍历链表，元素存入哈希表并判断是否有重复存入
// 时间复杂度O(N)，空间复杂度O(N)

// 快慢指针：空间复杂度O(1)（圆圆还很不熟练）
// 慢指针：每次指向slow->next（步长为1）
// 快指针：每次指向fast->next->next（步长为2）
// 不存在环：迟早快指针的next或者next->next为nullptr
// 存在环：迟早快慢指针会相遇

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head || !head->next) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow != fast)
        {
            if(fast->next == nullptr || fast->next->next == nullptr){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(!head) return false;
        
//         unordered_set<ListNode*> us;
        
//         while(head)
//         {
//             if(us.count(head)){
//                 return true;
//             }

//             us.insert(head);
            
//             head = head->next;
//         }

//         return false;
//     }
// };

// @lc code=end

