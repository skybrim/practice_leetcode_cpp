//
//  49.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/14.
//

/*
 49. 字母异位词分组
 
 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

 示例:
 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 输出:
 [
   ["ate","eat","tea"],
   ["nat","tan"],
   ["bat"]
 ]
 
 说明：
 所有输入均为小写字母。
 不考虑答案输出的顺序。

*/
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> helper;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            helper[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto it = helper.cbegin(); it != helper.cend(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};
