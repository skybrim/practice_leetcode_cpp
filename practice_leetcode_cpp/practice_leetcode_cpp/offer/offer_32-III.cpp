//
//  offer_32-III.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/2/5.
//
/**
 剑指 Offer 32 - III. 从上到下打印二叉树 III

 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

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
   [20,9],
   [15,7]
 ]

 提示：
     节点总数 <= 1000
 */
#include <stdio.h>
#include <vector>
#include <queue>

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
        queue<TreeNode *> help_queue;
        help_queue.push(root);
        while (!help_queue.empty()) {
            vector<int> temp;
            size_t count = help_queue.size();
            while (count--) {
                TreeNode *cur = help_queue.front();
                help_queue.pop();
                temp.push_back(cur->val);
                if (cur->left) {
                    help_queue.push(cur->left);
                }
                if (cur->right) {
                    help_queue.push(cur->right);
                }
            }
            if ((ret.size() & 1) != 0) {
                reverse(temp.begin(), temp.end());
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
