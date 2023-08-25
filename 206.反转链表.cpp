/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// 迭代思路：遍历逐步替换指针，需注意首尾的维护

// 递归思路：只进行当前节点和反转后的之后链表的拼接

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/***递归思路***/
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(!head || !head->next) return head;
//         // 保存好头节点之后反转列表的尾节点
//         ListNode* post = head->next;
//         // 头节点之后链表的反转
//         ListNode* end = reverseList(post);
//         // 头节点和之后反转链表的拼接
//         post->next = head;
//         // 尾部空节点的维护
//         head->next = nullptr;
//         return end;
//     }
// };

/***迭代思路***/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head) return nullptr;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* post;
        
        while(cur)
        {
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        
        return pre;
    }
};
// @lc code=end

