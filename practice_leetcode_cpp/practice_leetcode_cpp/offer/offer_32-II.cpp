//
//  offer_32-II.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/2/1.
//

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
