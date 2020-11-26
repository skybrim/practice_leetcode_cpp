#include <iostream>
#include "leetcode_164.cpp"

using namespace std;
int main(int argc, char *argv[]) {
    
    Solution test;
    vector<int> nums = {3, 6, 9, 1};
    int ret = test.maximumGap(nums);
    cout << ret << endl;
    
    return 0;
}