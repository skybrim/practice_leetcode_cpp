#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string sortString(string s) {
        int bucket[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            bucket[s[i] - 'a']++;
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