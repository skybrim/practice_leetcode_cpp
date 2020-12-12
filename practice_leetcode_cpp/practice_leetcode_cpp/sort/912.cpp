/*
912. 排序数组

给你一个整数数组 nums，请你将该数组升序排列。

示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]

示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, (int)nums.size()-1);
        return nums;
    }
    
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int pivot = nums[l];
        int index = l;
        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] < pivot) {
                ++index;
                swap(nums[i], nums[index]);
            }
        }
        swap(nums[l], nums[index]);
        quickSort(nums, l, index-1);
        quickSort(nums, index+1, r);
    }
};