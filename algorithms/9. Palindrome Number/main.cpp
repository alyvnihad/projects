/*  9. Palindrome Number

https://leetcode.com/problems/palindrome-number/description/

* Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
 */

#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string temp = to_string(x);
        int i = 0;
        while (i <= temp.size() / 2) {
            if (temp[i] != temp[(temp.size() - 1) - i]) {
                return false;
            }
            i++;
        }
        return true;
    }
};

int main() {
    int x;
    cin >> x;
    cout << boolalpha;
    cout << Solution().isPalindrome(x);
}
