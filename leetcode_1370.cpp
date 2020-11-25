#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string sortString(string s) {
        vector<int> bucket(26);
        for (auto &ch : s) {
            bucket[ch - 'a']++;
        }
        string ret;
        while (ret.length() < s.length()) {
            for (int i = 0; i < 26; ++i) {
                if (bucket[i]) {
                    --bucket[i];
                    ret += (i + 'a');
                }
            }
            for (int i = 25; i > -1; --i) {
                if (bucket[i]) {
                    --bucket[i];
                    ret += (i + 'a');
                }
            }
        }
        return ret;
    }
};