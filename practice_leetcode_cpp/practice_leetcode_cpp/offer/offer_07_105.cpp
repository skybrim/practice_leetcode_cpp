//
//  offer_07_105.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/14.
//

/*
 剑指 Offer 07. 重建二叉树
 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

  

 例如，给出

 前序遍历 preorder = [3,9,20,15,7]
 中序遍历 inorder = [9,3,15,20,7]
 返回如下的二叉树：

     3
    / \
   9  20
     /  \
    15   7
  

 限制：

 0 <= 节点个数 <= 5000
*/

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = (int)inorder.size();
        if (n == 0) {
            return nullptr;
        }
        for (int i = 0; i < n; ++i) {
            index_store[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, n-1, 0, n-1);
    }
private:
    unordered_map<int, int> index_store;
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder,
                     int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l > pre_r) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_l]);
        int in_root_index = index_store[preorder[pre_l]];
        int length = in_root_index - in_l;
        
        root->left = helper(preorder, inorder, pre_l+1, pre_l+length, in_l, in_root_index-1);
        root->right = helper(preorder, inorder, pre_l+1+length, pre_r, in_root_index+1, in_r);
        
        return root;
    }
};
