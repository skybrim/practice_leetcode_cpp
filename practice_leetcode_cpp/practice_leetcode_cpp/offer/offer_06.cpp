//
//  offer_06.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/13.
//

/*
 剑指 Offer 06. 从尾到头打印链表
 
 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 示例 1：
 输入：head = [1,3,2]
 输出：[2,3,1]
  

 限制：
 0 <= 链表长度 <= 10000
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        while (head != nullptr) {
            ret.push_back(head->val);
            head = head->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


