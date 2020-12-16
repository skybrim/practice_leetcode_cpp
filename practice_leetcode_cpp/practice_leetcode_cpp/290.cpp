//
//  290.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/16.
//
/*
 290. 单词规律
 
 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

 示例1:
 输入: pattern = "abba", str = "dog cat cat dog"
 输出: true
 
 示例 2:
 输入:pattern = "abba", str = "dog cat cat fish"
 输出: false
 
 示例 3:
 输入: pattern = "aaaa", str = "dog cat cat dog"
 输出: false
 
 示例 4:
 输入: pattern = "abba", str = "dog dog dog dog"
 输出: false
 
 说明:
 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。
*/
#include <stdio.h>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int i = 0;
        int l = (int)s.length();
        unordered_map<char, string> ch2str;
        unordered_map<string, char> str2ch;
        for (auto &ch : pattern) {
            if (i >= l) {
                return false;
            }
            int j = i;
            while (s[j] != ' ' && j < l) {
                ++j;
            }
            const string &strSlice = s.substr(i, j-i);
            i = j+1;
            
            if (ch2str.count(ch) && ch2str[ch] != strSlice) {
                return false;
            }
            if (str2ch.count(strSlice) && str2ch[strSlice] != ch) {
                return false;
            }
            ch2str.insert({ch, strSlice});
            str2ch.insert({strSlice, ch});
        }
        return i >= l;
    }
};
