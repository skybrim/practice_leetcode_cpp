//
//  offer_24.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/7.
//
/**
 剑指 Offer 24. 反转链表

 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 示例:
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL

 限制：
 0 <= 节点个数 <= 5000

 注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/
*/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
