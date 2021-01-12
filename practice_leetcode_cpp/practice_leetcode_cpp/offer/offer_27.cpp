//
//  offer_27.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/12.
//

#include <stdio.h>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
private:
    void dfs(TreeNode *root) {
        using std::swap;
        if (!root) return;
        dfs(root->left);
        dfs(root->right);
        swap(root->left, root->right);
    }
};
