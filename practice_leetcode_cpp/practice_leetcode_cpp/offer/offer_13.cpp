//
//  offer_13.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/24.
//
/**
 剑指 Offer 13. 机器人的运动范围
 
 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 一个机器人从坐标 [0, 0] 的格子开始移动，
 它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 请问该机器人能够到达多少个格子？

 示例 1：
 输入：m = 2, n = 3, k = 1
 输出：3
 
 示例 2：
 输入：m = 3, n = 1, k = 0
 输出：1
 
 提示：
 1 <= n,m <= 100
 0 <= k <= 20
*/
#include <stdio.h>
#include <vector>

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (k == 0) return 1;
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
        visited[0][0] = 1;
        int ret = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] || get(i) + get(j) > k) {
                    continue;
                }
                if (j > 0) {
                    visited[i][j] |= visited[i][j-1];
                }
                if (i > 0) {
                    visited[i][j] |= visited[i-1][j];
                }
                ret += visited[i][j];
            }
        }
        return ret;
    }
private:
    int get(int num) {
        int ret = 0;
        while (num > 0) {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }
};
