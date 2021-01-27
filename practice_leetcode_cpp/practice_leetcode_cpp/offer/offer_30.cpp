//
//  offer_30.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/27.
//

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
