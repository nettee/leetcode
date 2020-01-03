/*
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (33.27%)
 * Total Accepted:    161.4K
 * Total Submissions: 480.7K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int N = nums.size();
        for (int u = 0; u < N; u++) {
            int lo = u > k ? u - k : 0;
            // Check nums[lo..u]
            // nums[lo..u-1] is already checked in the previous loop
            // We only compare nums[lo..u-1] with nums[u]
            int base = nums[u];
            for (int j = lo; j < u; j++) {
                if (nums[j] == base) {
                    return true;
                }
            }
        }
        return false;
    }
};

