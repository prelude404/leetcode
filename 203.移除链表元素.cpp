/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// 初步思路：首先去除头节点之后的链表元素，再判断头节点进行更新
// 方法2：这一迭代思路也可以用递归实现，但是空间复杂度会由O(1)变为O(N)
// 方法3：添加一虚拟头节点，就不用对删除头节点进行特殊考虑

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head) return nullptr;
        
        ListNode* cur = head;
        
        while(cur->next)
        {
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        
        if(head->val == val){
            head = head->next;
        }

        return head;
    }
};
// @lc code=end

