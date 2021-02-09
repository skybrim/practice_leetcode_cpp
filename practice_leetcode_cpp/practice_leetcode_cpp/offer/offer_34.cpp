//
//  offer_34.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/2/9.
//
/**
 剑指 Offer 34. 二叉树中和为某一值的路径

 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

 示例:
 给定如下二叉树，以及目标和 sum = 22，
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \    / \
         7    2  5   1
 返回:
 [
    [5,4,11,2],
    [5,8,4,5]
 ]

 提示：
     节点总数 <= 10000

 注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/

 */
#include <stdio.h>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        help(root, sum, path, res);
        return res;
    }
private:
    void help(TreeNode *node, int tar, vector<int> &path, vector<vector<int>> &res) {
        if (node == nullptr) return;
        tar = tar - node->val;
        path.push_back(node->val);
        if (tar == 0 && node->left == nullptr && node->right == nullptr) {
            res.push_back(path);
        }
        help(node->left, tar, path, res);
        help(node->right, tar, path, res);
        path.pop_back();
    }
};
