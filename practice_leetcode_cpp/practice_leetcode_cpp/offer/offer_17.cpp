//
//  offer_17.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/1.
//
/**
 剑指 Offer 17. 打印从1到最大的n位数
 
 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
 比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

 示例 1:
 输入: n = 1
 输出: [1,2,3,4,5,6,7,8,9]

 说明：
 用返回一个整数列表来代替打印
 n 为正整数
*/
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        if (n <= 0) return ret;
        
        string number(n, '0');
        
        for (int i = 0; i < 10; ++i) {
            number[0] = i + '0';
            recursive(number, n, 0);
        }
        
        return ret;
    }
private:
    vector<int> ret;
    void recursive(string &number, int length, int index) {
        if (index == length - 1) {
            save(number);
            return;;
        }
        for (int i = 0; i < 10; ++i) {
            number[index+1] = i + '0';
            recursive(number, length, index+1);
        }
    }
    
    void save(string &number) {
        bool isBeginZero = true;
        string s = "";
        string::iterator it = number.begin();
        while (it != number.end()) {
            if (isBeginZero && *it != '0')
                isBeginZero = false;
            if (!isBeginZero)
                s += *it;
            it++;
        }
        if (s != "") {
            int num = stoi(s);
            ret.push_back(num);
        }
    }
};
