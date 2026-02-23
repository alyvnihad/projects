#include <vector>
#include <unordered_map>
using namespace std;

/*  1. Two Sum
 *https://leetcode.com/problems/two-sum/

* Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = target - nums[i];
            if (map.find(temp) != map.end()) {
                return {map[temp], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
