//
//  offer_05.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/12.
//

/*
 剑指 Offer 05. 替换空格
 
 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 示例 1：
 输入：s = "We are happy."
 输出："We%20are%20happy."
  
 限制：
 0 <= s 的长度 <= 10000
*/
#include <stdio.h>
#include <string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for (auto &c : s) {
            if (c == ' ') {
                ret += "%20";
            } else {
                ret += c;
            }
        }
        return ret;
    }
};
