//
//  offer_20.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/4.
//
/**
 剑指 Offer 20. 表示数值的字符串

 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
 但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
*/
#include <stdio.h>
#include <string>

using namespace std;

// 整数的格式可以用[+|-]B表示, 其中B为无符号整数

class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0) return false;
        
        int index = 0;
        while (s[index] == ' ')
            ++index;
        
        bool numeric = scanInteger(s, index);
        
        // 如果是小数点
        if (s[index] == '.') {
            ++index;
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
            numeric = scanUInteger(s, index) || numeric;
        }
        
        // 如果是'e'或者'E'
        if (s[index] == 'e' || s[index] == 'E') {
            ++index;
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4;
            // 3. e或E后面可能有符号
            numeric = numeric && scanInteger(s, index);
        }
        
        while (s[index] == ' ')
            ++index;
        
        return numeric && index == s.size();
    }
    
private:
    bool scanInteger(const string s, int &index) {
        if (s[index] == '+' || s[index] == '-') {
            ++index;
        }
        
        return scanUInteger(s, index);
    }
    
    // 找到第一个非数字的字符
    bool scanUInteger(const string s, int &index) {
        int before = index;
        while (index != s.size() && s[index] >= '0' && s[index] <= '9') {
            ++index;
        }
        return index > before;
    }
};
