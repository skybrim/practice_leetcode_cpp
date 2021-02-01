//
//  offer_32.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/29.
//

/**
 剑指 Offer 32 - I. 从上到下打印二叉树

 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 例如:
 给定二叉树: [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
 返回：
 [3,9,20,15,7]

 提示：
     节点总数 <= 1000
 */

#include <stdio.h>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ret;
        deque<TreeNode *> help_deq = { root };
        while (!help_deq.empty()) {
            TreeNode *node = help_deq.back();
            ret.push_back(node->val);
            if (node->left) {
                help_deq.push_front(node->left);
            }
            if (node->right) {
                help_deq.push_front(node->right);
            }
            help_deq.pop_back();
        }
        return ret;
    }
};
