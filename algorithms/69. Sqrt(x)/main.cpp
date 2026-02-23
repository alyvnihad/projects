/*  69. Sqrt(x)
 * https://leetcode.com/problems/sqrtx/description/
 *
    Example 1:
    Input: x = 4
    Output: 2
    Explanation: The square root of 4 is 2, so we return 2.

    Example 2:
    Input: x = 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 */
// TAM YAZILMAYIB
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int a = x / 2;
        int i = 1;
        while (i < a) {
            if (i * i <= x) {
                i++;
            } else {
                --i;
                break;
            }
        }
        return i;
    }
};