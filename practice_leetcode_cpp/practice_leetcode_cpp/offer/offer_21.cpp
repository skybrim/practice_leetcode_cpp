//
//  offer_21.cpp
//  practice_leetcode_cpp
//
//  Created by wiley on 2021/1/5.
//
/**
 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 示例：
 输入：nums = [1,2,3,4]
 输出：[1,3,2,4]
 注：[3,1,2,4] 也是正确的答案之一。

 提示：
     1 <= nums.length <= 50000
     1 <= nums[i] <= 10000
*/
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = (int)nums.size();
        while (i < j) {
            while (i < j && (nums[i] & 1) == 1) {
                ++i;
            }
            while (i < j && (nums[j] & 1) != 1) {
                --j;
            }
            swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};
