/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// int i = 42, j = 15;
// int &r1 = i; // &紧随类型名，声明引用
// int *p; // *紧随类型名，声明指针
// p = &i; // &在表达式中，取地址符
// *p = j; // *在表达式中，解引用符
// int &r2 = *p;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// (*node).next先对指针解引用再访问成员过于繁琐，可直接使用node->next

// 当前问题：出不了循环

// @lc code=start


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // new用于动态分配内存并创建对象，在不再使用时需要利用delete释放内存
        ListNode *preHead = new ListNode(); // preHead储存合并后的表头前一个伪表头
        
        ListNode *node;// node储存遍历时的当前ListNode
        node = preHead;
        
        // 三元运算符 条件表达式 ? 表达式1 : 表达式2
        // list1和list2表头还要后移，所以不能直接赋值
        // list3 = (list1->val  < list2->val) ? list1 : list2;
        
        // 一个链表遍历结束后，另一链表剩余节点需单独处理，因为剩余节点已无法与空节点进行比较
        // 所以此处只能用&&保证两链表均非空，不能一次把两个链表都处理完
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val  < list2->val)
            {
                node->next = list1;
                list1 = list1->next;
            }
            else
            {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        
        // 有剩余链表节点只需改一个指针即可
        if(list1 != nullptr)
        {node->next = list1;}
        else{node->next = list2;}

        return preHead->next;
    }
};
// @lc code=end

