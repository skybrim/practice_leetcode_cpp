//
//  offer_30.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/27.
//
/**
 剑指 Offer 30. 包含min函数的栈

 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 示例:
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.min();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.min();   --> 返回 -2.

 提示：
     各函数的调用总次数不超过 20000 次

 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/
 */
#include <stdio.h>
#include <vector>
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        main_vec.push_back(x);
        if (help_vec.empty() || x <= *(--help_vec.end())) {
            help_vec.push_back(x);
        }
    }
    
    void pop() {
        if (*(--main_vec.end()) == *(--help_vec.end())) {
            help_vec.pop_back();
        }
        main_vec.pop_back();
    }
    
    int top() {
        return *(--main_vec.end());
    }
    
    int min() {
        return *(--help_vec.end());
    }
private:
    std::vector<int> main_vec;
    std::vector<int> help_vec;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
