//
//  offer_29.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/14.
//
/**
 剑指 Offer 29. 顺时针打印矩阵

 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 示例 1：
 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 输出：[1,2,3,6,9,8,7,4,5]

 示例 2：
 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

 限制：
     0 <= matrix.length <= 100
     0 <= matrix[i].length <= 100

 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/
*/
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty()) return ret;
        int top = 0, left = 0, bottom = (int)matrix.size()-1, right = (int)matrix[0].size()-1;
        while (true) {
            for (int i = left; i <= right; ++i) ret.push_back(matrix[top][i]);
            if (++top > bottom) break;
            for (int i = top; i <= bottom; ++i) ret.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int i = right; i >= left; --i) ret.push_back(matrix[bottom][i]);
            if (--bottom < top) break;
            for(int i = bottom; i >= top; --i) ret.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return ret;
    }
};
