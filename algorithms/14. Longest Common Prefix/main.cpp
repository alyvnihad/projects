/*  14. Longest Common Prefix
 *
 *https://leetcode.com/problems/longest-common-prefix/submissions/1855283748/
 *
 *Example 1:
 *Input: strs = ["flower","flow","flight"]
 *Output: "fl"
*/


#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        string text = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            char letter = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || letter != strs[j][i]) {
                    return text;
                }
            }
            text += letter;
        }
        return text;
    }
};
