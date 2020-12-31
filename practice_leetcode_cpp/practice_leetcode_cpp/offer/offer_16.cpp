//
//  offer_16.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/31.
//
/**
 剑指 Offer 16. 数值的整数次方
 
 实现函数double Power(double base, int exponent)，求base的exponent次方。
 不得使用库函数，同时不需要考虑大数问题。

 示例 1:
 输入: 2.00000, 10
 输出: 1024.00000
 
 示例 2:
 输入: 2.10000, 3
 输出: 9.26100
 
 示例 3:
 输入: 2.00000, -2
 输出: 0.25000
 解释: 2-2 = 1/22 = 1/4 = 0.25

 说明:
 -100.0 < x < 100.0
 
*/
#include <stdio.h>

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0;
        for (int i = n; i != 0; i /= 2, x *= x) {
            if ((i & 1) == 1) {
                ret *= x;
            }
        }
        return n > 0 ? ret : 1 / ret;
    }
};
