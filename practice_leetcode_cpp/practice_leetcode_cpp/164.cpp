#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 1;i < nums.size();++i) {
            ret = ret > nums[i] - nums[i-1] ? ret : nums[i] - nums[i-1];
        }
        return ret;
    }
};