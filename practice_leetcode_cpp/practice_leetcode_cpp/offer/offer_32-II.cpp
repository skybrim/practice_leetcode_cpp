//
//  offer_32-II.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/2/1.
//
/**
 剑指 Offer 32 - II. 从上到下打印二叉树 II

 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 例如:
 给定二叉树: [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
 返回其层次遍历结果：
 [
   [3],
   [9,20],
   [15,7]
 ]

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ret;
        deque<TreeNode *> help_deq;
        help_deq.push_back(root);
        while (!help_deq.empty()) {
            vector<int> temp;
            size_t count = help_deq.size();
            while (count--) {
                TreeNode *cur = help_deq.front();
                help_deq.pop_front();
                temp.push_back(cur->val);
                if (cur->left) {
                    help_deq.push_back(cur->left);
                }
                if (cur->right) {
                    help_deq.push_back(cur->right);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
