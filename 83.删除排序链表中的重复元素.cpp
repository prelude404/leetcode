/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 一点改进：因为pre_head和current_head始终相邻，可以只用一个cur_head
// 可以不用(head == nullptr)而是直接(head)和(!head)

// @lc code=start

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {return head;}
        ListNode *current = head;
        
        while(current->next)
        {
            if(current->next->val != current->val)
            {
                current = current->next;
            }
            else{
                ListNode *to_free = current->next;
                current->next = current->next->next;
            }
        }
        return head;
    }
};
// @lc code=end

