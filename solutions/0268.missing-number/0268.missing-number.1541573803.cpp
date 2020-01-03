/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (46.44%)
 * Total Accepted:    216.7K
 * Total Submissions: 466.6K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int sum = 0;
        for (int n : nums) {
            maxi = max(maxi, n);
            mini = min(mini, n);
            sum += n;
        }
        int expected = maxi * (maxi + 1) / 2;
        if (sum < expected) {
            return expected - sum;
        } else if (mini > 0) {
            return 0;
        } else {
            return maxi + 1;
        }
    }
};

