//
//  offer_09.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2020/12/16.
//

/*
 剑指 Offer 09. 用两个栈实现队列
 
 用两个栈实现一个队列。
 队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 示例 1：
 输入：
 ["CQueue","appendTail","deleteHead","deleteHead"]
 [[],[3],[],[]]
 输出：[null,null,3,-1]
 
 示例 2：
 输入：
 ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
 [[],[],[5],[2],[],[]]
 输出：[null,-1,null,null,5,2]
 
 提示：
 1 <= values <= 10000
 最多会对 appendTail、deleteHead 进行 10000 次调用
*/
#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
class CQueue {
public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (!stack2.empty()) {
            int top = stack2.top();
            stack2.pop();
            return top;
        }
        if (stack1.empty()) {
            return -1;
        } else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            return -1;
        }
    }
private:
    stack<int> stack1, stack2;
};
