//
//  offer_35.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/2/18.
//
/**
 剑指 Offer 35. 复杂链表的复制

 请实现 copyRandomList 函数，复制一个复杂链表。
 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。


 示例 1：
 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

 示例 2：
 输入：head = [[1,1],[2,1]]
 输出：[[1,1],[2,1]]

 示例 3：
 输入：head = [[3,null],[3,0],[3,null]]
 输出：[[3,null],[3,0],[3,null]]

 示例 4：
 输入：head = []
 输出：[]
 解释：给定的链表为空（空指针），因此返回 null。

 提示：
     -10000 <= Node.val <= 10000
     Node.random 为空（null）或指向链表中的节点。
     节点数目不超过 1000 。

 */
#include <stdio.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node *cur = head;
        while (cur) {
            Node *newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node *ret = cur = head->next;
        Node *pre = head;
        while (cur->next) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return ret;
    }
};
