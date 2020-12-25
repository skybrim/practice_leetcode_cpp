//
//  offer_14-I.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/25.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

class Solution {
public:
    int cuttingRope(int n) {
        std::vector<int> dp(n+1, 0);
        dp[2] = 1;
        for (int i = 3; i < n+1; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = std::max(dp[i], std::max((i-j)*j, dp[i-j]*j));
            }
        }
        return dp[n];
    }
};
